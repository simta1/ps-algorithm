#include <bits/stdc++.h>
#define int ll
using namespace std;

using ll = long long;
template <ll MOD>
class ModInt {
    static_assert(MOD > 1);
    static_assert(MOD - 1 <= numeric_limits<long long>::max() / 2, "operator+ 수정해야 함");

public:
    ll value;

    explicit ModInt() = default;
    explicit ModInt(ll n) {
        value = n % MOD;
        if (value < 0) value += MOD;
    }

    tuple<ll, ll, ll> extendedGCD(ll a, ll b) const { // ax + by = gcd(a, b)
        if (b == 0) return {1, 0, a};
        auto [x, y, g] = extendedGCD(b, a % b);
        return {y, x - (a / b) * y, g};
    }

    ModInt inv() const {
        auto [x, y, g] = extendedGCD(value, MOD);
        assert(g == 1); // g!=1이면 역원 존재 안함
        return ModInt(x);
    }

    ModInt pow(ll n) const {
        ModInt base = *this, res(1);
        while (n) {
            if (n & 1) res *= base;
            base *= base;
            n >>= 1;
        }
        return res;
    }
    
    ModInt operator-() const { return ModInt(-value); }
    ModInt& operator+=(const ModInt &other) { if ((value += other.value) >= MOD) value -= MOD; return *this; }
    ModInt& operator-=(const ModInt &other) { if ((value -= other.value) < 0) value += MOD; return *this; }
    ModInt& operator*=(const ModInt &other) {
        if constexpr ((MOD - 1) > numeric_limits<ll>::max() / (MOD - 1)) value = ll(__int128(value) * other.value % MOD);
        else value = value * other.value % MOD;
        return *this;
    }
    ModInt& operator/=(const ModInt &other) { return *this *= other.inv(); }
    ModInt operator+(const ModInt &other) const { return ModInt(value) += other; }
    ModInt operator-(const ModInt &other) const { return ModInt(value) -= other; }
    ModInt operator*(const ModInt &other) const { return ModInt(value) *= other; }
    ModInt operator/(const ModInt &other) const { return ModInt(value) /= other; }
    bool operator==(const ModInt &other) const { return value == other.value; }
    bool operator!=(const ModInt &other) const { return value != other.value; }
    friend istream &operator>>(istream &is, ModInt &m) { ll x; is >> x; m = ModInt(x); return is; }
    friend ostream &operator<<(ostream &os, const ModInt &m) { return os << m.value; }
};

namespace Poly { // FFT
    using ll = long long;
    int pow2GE(int n) { return 1 << __lg(n) + !!(n & (n - 1)); }
    
    vector<vector<pair<int, int> > > bitRev; // 비트 반전 저장 // 다항식 곱셈 한 번에도 fft()가 여러 번 호출되므로 비트 반전 결과를 캐싱해두고 사용하면 성능향상에 좋음
    const vector<pair<int, int> >& getBitRev(int n) {
        if (__lg(n) >= bitRev.size()) bitRev.resize(__lg(n) + 1);

        auto &res = bitRev[__lg(n)];
        if (!res.empty()) return res;
        
        res.reserve(n / 2);
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j >= bit; bit >>= 1) j -= bit;
            j += bit;
            if (i < j) res.emplace_back(i, j);
        }
        return res;
    }

    template <typename T>
    void __transform(vector<T> &f, bool is_reverse, T root) {
        int n = f.size();
        for (auto [i, j] : getBitRev(n)) swap(f[i], f[j]);
        
        if (is_reverse) root = T(1) / root;
        vector<T> wms;
        for (int m = n; m >= 2; m >>=1) {
            wms.push_back(root);
            root *= root;
        }

        for (int m = 2, wIdx = wms.size(); m <= n; m <<= 1) {
            T w_m = wms[--wIdx];
            for (int i = 0; i < n; i += m) {
                T w_j(1); // (w_m)^j
                for (int j = 0; j < m / 2; j++, w_j *= w_m) {
                    T even = f[i + j];
                    T odd = w_j * f[i + j + m / 2];
                    f[i + j] = even + odd;
                    f[i + j + m / 2] = even - odd;
                }
            }
        }

        if (is_reverse) for (auto &e : f) e /= T(n);
    }
    
    template <typename double_t>
    void fft(vector<complex<double_t> > &f, bool is_reverse) {
        double_t t = 2 * acos(double_t(-1)) / f.size(); // acos(double_t(-1))는 PI
        __transform(f, is_reverse, complex<double_t>(cos(t), sin(t)));
    }

    template <typename double_t, typename T>
    vector<ll> multiply(const vector<T> &f, const vector<T> &g) {
        using cpx = complex<double_t>;
        vector<cpx> a(f.begin(), f.end());
        vector<cpx> b(g.begin(), g.end());
        int n = pow2GE(a.size() + b.size());
        a.resize(n);
        b.resize(n);
        fft(a, false);
        fft(b, false);
        for (int i = 0; i < n; i++) a[i] *= b[i];
        fft(a, true);

        vector<ll> res(f.size() + g.size() - 1);
        for (int i = 0; i < res.size(); i++) res[i] = round(a[i].real());
        return res;
    }
}

namespace Poly { // NTT
    template <ll p, ll primitiveRoot>
    void ntt(vector<ModInt<p> > &f, bool is_reverse) {
        __transform(f, is_reverse,ModInt<p>(primitiveRoot).pow((p - 1) / f.size()));
    }
    
    // | p = a*2^b+1   | a   | b  | 2^b       | g |
    // | ------------- | --- | -- | --------- | - |
    // | 104'857'601   | 25  | 22 | 4194304   | 3 |
    // | 998'244'353   | 119 | 23 | 8388608   | 3 |
    // | 2'281'701'377 | 17  | 27 | 134217728 | 3 |
    // | 2'483'027'969 | 37  | 26 | 67108864  | 3 |
    template <ll p, ll primitiveRoot, typename T> // p = a * 2^b + 1 꼴 소수, n <= 2^b인 n차 다항식에 대해 mod P에서의 다항식 곱셈 계산
    vector<ll> multiplyMod(const vector<T> &f, const vector<T> &g) {
        vector<ModInt<p> > a(f.begin(), f.end());
        vector<ModInt<p> > b(g.begin(), g.end());
        int n = pow2GE(a.size() + b.size());
        assert(n <= ((p - 1) & -(p - 1)));
        a.resize(n);
        b.resize(n);
        ntt<p, primitiveRoot>(a, false);
        ntt<p, primitiveRoot>(b, false);
        for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
        ntt<p, primitiveRoot>(a, true);
        
        vector<ll> res(f.size() + g.size() - 1);
        for (int i = 0; i < res.size(); i++) res[i] = a[i].value; // 모든 계수가 0 <= 계수 < MOD를 만족함
        return res;
    }
}

tuple<ll, ll, ll> extendedGCD(ll a, ll b) { // ax + by = gcd(a, b)
    if (b == 0) return {1, 0, a};

    auto [x, y, g] = extendedGCD(b, a % b);
    return {y, x - (a / b) * y, g};
}

ll modInverse(ll a, ll b) {
    auto [x, y, g] = extendedGCD(a, b); //ax + by = g
    if (g == 1) return (x + b) % b;
    return -1;
}

main() {
	cin.tie(0) -> sync_with_stdio(0);
	constexpr ll MOD = 998'244'353;

	int n, m;
	cin >> n >> m;

	vector<int> v(m);
	for (auto &e : v) cin >> e;
	int mx = *max_element(v.begin(), v.end());
	ll s = accumulate(v.begin(), v.end(), 0LL);

	auto f = [&](ll n) -> vector<ll> {
		// { nC0, nC1, nC2, ..., nCmx }
		vector<ll> res;
		res.push_back(1);
		for (int i = 1; i <= n && i <= mx; i++) res.push_back(res.back() * ((n + 1 - i) % MOD) % MOD * modInverse(i, MOD) % MOD);
		return res;
	};

	vector<ll> a = f(2 * n);
	for (int i = 0; i < a.size(); i += 2) a[i] = 0;
	vector<ll> b = f(s - 2 * n);

	auto c = Poly::multiplyMod<MOD, 3>(a, b);

	vector<ll> fac(2 * n + 1, 1);
	for (int i = 2; i < fac.size(); i++) fac[i] = fac[i - 1] * i % MOD;

	vector<ll> mul(2 * n);
	mul[2 * n - 1] = (s - 2 * n + 1) % MOD;
	for (int i = 2 * n - 2; i >= 0; i--) mul[i] = mul[i + 1] * ((s - i) % MOD) % MOD;

	ll ans = 0;
	for (auto k : v) {
		ans += c[k] * fac[k] % MOD * mul[k] % MOD;
		ans %= MOD;
	}
	cout << ans * modInverse(2, MOD) % MOD * modInverse(fac[2 * n], MOD) % MOD;

	return 0;
}
