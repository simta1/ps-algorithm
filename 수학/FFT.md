[카테고리](/README.md)
## 다항식 연산
### FFT (Fast Fourier Transform)
```cpp
namespace Poly { // FFT
    using ll = long long;
    int pow2GE(int n) { return 1 << __lg(n) + !!(n & (n - 1)); }

    template <typename T>
    void __transform(vector<T> &f, bool is_reverse, T root) {
        int n = f.size();

        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j >= bit; bit >>= 1) j -= bit;
            j += bit;
            if (i < j) swap(f[i], f[j]);
        }
        
        vector<T> wms;
        if (is_reverse) root = T(1) / root;

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

        if (is_reverse) for (auto &e : f) e /= n;
    }
    
    const long double PI = acos(-1);
    
    template <typename double_t>
    void fft(vector<complex<double_t> > &f, bool is_reverse) {
        double_t t = 2 * PI / f.size();
        __transform(f, is_reverse, complex<double_t>(cos(t), sin(t)));
    }

    template <typename double_t, typename T>
    vector<ll> multiply(const vector<T> &v1, const vector<T> &v2) {
        using cpx = complex<double_t>;
        vector<cpx> a(v1.begin(), v1.end());
        vector<cpx> b(v2.begin(), v2.end());
        int n = pow2GE(a.size() + b.size());
        a.resize(n);
        b.resize(n);
        fft(a, false);
        fft(b, false);
        for (int i = 0; i < n; i++) a[i] *= b[i];
        fft(a, true);

        vector<ll> res(n);
        for (int i = 0; i < n; i++) res[i] = round(a[i].real());
        return res;
    }

    template <typename double_t, typename T>
    vector<ll> square(const vector<T> &v) {
        using cpx = complex<double_t>;
        vector<cpx> a(v.begin(), v.end());
        int n = pow2GE(a.size() * 2);
        a.resize(n);
        fft(a, false);
        for (int i = 0; i < n; i++) a[i] *= a[i];
        fft(a, true);

        vector<ll> res(n);
        for (int i = 0; i < n; i++) res[i] = round(a[i].real());
        return res;
    }
}
```
### 정확도 높은 FFT
### TODO [씽크스몰](https://www.acmicpc.net/problem/11385)에서 WA 받았음
```cpp
namespace Poly { // 정확도 높은 FFT
    static const int splitBit = 20;
    static const int split = 1 << splitBit;
    template <typename double_t=double, typename T>
    vector<ll> multiplyPrecisely(const vector<T> &v1, const vector<T> &v2) {
        using cpx = complex<double_t>;
        int n = pow2GE(v1.size() + v2.size() + 1);

        vector<cpx> a1(n), a2(n), b1(n), b2(n);
        for (int i = 0; i < v1.size(); i++) {
            a1[i] = v1[i] & (split - 1);
            a2[i] = v1[i] >> splitBit;
        }
        for (int i = 0; i < v2.size(); i++) {
            b1[i] = v2[i] & (split - 1);
            b2[i] = v2[i] >> splitBit;
        }

        fft(a1, false);
        fft(a2, false);
        fft(b1, false);
        fft(b2, false);

        vector<cpx> c1(n), c2(n), c3(n);
        for(int i=0; i<n; i++){
            c1[i] = a1[i] * b1[i];
            c2[i] = a1[i] * b2[i] + a2[i] * b1[i];
            c3[i] = a2[i] * b2[i];
        }

        fft(c1, true);
        fft(c2, true);
        fft(c3, true);

        vector<ll> res(n);
        for (int i = 0; i < n; i++) res[i] = round(c1[i].real()) + (ll(round(c2[i].real())) << splitBit) + (ll(round(c3[i].real())) << 2 * splitBit);
        return res;
    }
}
```
### [ModInt](/utils/ModInt.md)
<details>
<summary>ModInt 코드</summary>

```cpp
using ll = long long;
template <ll MOD>
class ModInt {
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

    ModInt operator+(const ModInt &other) const { ll res = value + other.value; if (res >= MOD) res -= MOD; return ModInt(res); }
    ModInt &operator+=(const ModInt &other) { value += other.value; if (value >= MOD) value -= MOD; return *this; }
    ModInt operator-(const ModInt &other) const { ll res = value - other.value; if (res < 0) res += MOD; return ModInt(res); }
    ModInt &operator-=(const ModInt &other) { value -= other.value; if (value < 0) value += MOD; return *this; }
    ModInt operator*(const ModInt &other) const {
        if constexpr ((MOD - 1) > numeric_limits<ll>::max() / (MOD - 1)) return ModInt(ll(__int128(value) * other.value % MOD));
        else return ModInt(value * other.value % MOD);
    }
    ModInt &operator*=(const ModInt &other) {
        if constexpr ((MOD - 1) > numeric_limits<ll>::max() / (MOD - 1)) value = ll(__int128(value) * other.value % MOD);
        else value = value * other.value % MOD;
        return *this;
    }
    ModInt operator/(const ModInt &other) const { return *this * other.inv(); }
    ModInt &operator/=(const ModInt &other) { return *this *= other.inv(); }
    bool operator==(const ModInt &other) const { return value == other.value; }
    bool operator!=(const ModInt &other) const { return value != other.value; }
    friend istream &operator>>(istream &is, ModInt &m) { ll x; is >> x; m = ModInt(x); return is; }
    friend ostream &operator<<(ostream &os, const ModInt &m) { return os << m.value; }
};

```
</details>

### NTT (Number Theoretic Transform)
```cpp
namespace Poly { // NTT
    template <ll p, ll primitiveRoot>
    void ntt(vector<ModInt<p> > &f, bool is_reverse) {
        __transform(f, is_reverse, ModInt<p>(primitiveRoot).pow((p - 1) / f.size()));
    }
    
    // | p = a*2^b+1   | a   | b  | 2^b       | g |
    // | ------------- | --- | -- | --------- | - |
    // | 998'244'353   | 119 | 23 | 8388608   | 3 |
    // | 2'281'701'377 | 17  | 27 | 134217728 | 3 |
    // | 2'483'027'969 | 37  | 26 | 67108864  | 3 |
    template <ll p, ll primitiveRoot, typename T> // p = a * 2^b + 1 꼴 소수, n <= 2^b인 n차 다항식에 대해 mod P에서의 다항식 곱셈 계산
    vector<ll> multiplyMod(const vector<T> &v1, const vector<T> &v2) {
        vector<ModInt<p> > a(v1.begin(), v1.end());
        vector<ModInt<p> > b(v2.begin(), v2.end());
        int n = pow2GE(a.size() + b.size());
        assert(n <= ((p - 1) & -(p - 1)));
        a.resize(n);
        b.resize(n);
        ntt<p, primitiveRoot>(a, false);
        ntt<p, primitiveRoot>(b, false);
        for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
        ntt<p, primitiveRoot>(a, true);
        
        vector<ll> res(n);
        for (int i = 0; i < n; i++) res[i] = a[i].value;
        return res;
    }

    template <typename T>
    vector<ll> multiplyMod5e18(const vector<T> &v1, const vector<T> &v2) { // mod 5665528335996813313에서 다항식 곱셈한 결과 계산
        constexpr ll p1 = 2'281'701'377, g1 = 3;
        constexpr ll p2 = 2'483'027'969, g2 = 3;
        constexpr ll MOD = p1 * p2;
        
        vector<ll> rem1 = multiplyMod<p1, g1>(v1, v2);
        vector<ll> rem2 = multiplyMod<p2, g2>(v1, v2);
        ll i1 = ModInt<p2>(p1).inv().value; // p1^-1 mod p2
        ll i2 = ModInt<p1>(p2).inv().value; // p2^-1 mod p1

        vector<ll> res(rem1.size());
        for (int i = 0; i < res.size(); i++) res[i] = (__int128(rem1[i]) * p2 * i2 + __int128(rem2[i]) * p1 * i1) % MOD; // CRT
        return res;
    }
}
```

### 시간복잡도 
$O(N \log{N})$   

### 사용설명
FFT 쓸 때 가능하면 double 사용   
오차범위 확인할 때 참고 -> [부동소숫점 오류](https://www.acmicpc.net/blog/view/37)   

```cpp
// FFT를 사용하여 곱셈
// 최대/최소값의 범위가 그리 크지 않다면 double을 사용하는 게 낫다. long double은 정말 느리다.
auto res = Poly::multiply<double>(poly1, poly2);
auto res = Poly::multiply<long double>(poly1, poly2);

// NTT를 사용해 곱셈
auto res = Poly::multiplyMod<998'244'353, 3>(poly1, poly2);
auto res = Poly::multiplyMod<2'281'701'377, 3>(poly1, poly2);
auto res = Poly::multiplyMod<2'483'027'969, 3>(poly1, poly2);

// NTT+CRT
auto res = Poly::multiplyMod5e18(poly1, poly2);
```
<!--
예전 코드 기준 작성했던 거. 지금 코드는 한 번 확인 필요 TODO
[보석 가게](https://www.acmicpc.net/problem/13575) 문제에서 처음 벡터를 선언할 때 크기 1000으로 선언하면 mle가 남?
처음부터 벡터의 크기를 2의 거듭제곱이 되도록(이 문제에선 1024로) 선언한 뒤 거듭제곱을 하니 mle가 해결됐음.    -->

### 문제
[큰 수 곱셈 (2)](https://www.acmicpc.net/problem/15576)   
[큰 수 곱셈 (3)](https://www.acmicpc.net/problem/22289)   
[씽크스몰](https://www.acmicpc.net/problem/11385) - NTT + CRT(`multiplyMod5e18()` 함수 사용하면 됨)   

### 원리
FFT의 비재귀 구현을 위해 `f[i]`와 `f[bitReverse(i)]`를 swap하는 과정에서 비트트릭 사용   
```cpp
// 느린 코드
    int bitReverse(int n, int len) {
        int rev = 0;
        for (int i = 0; i < len; i++) rev |= ((n >> i) & 1) << (len - i - 1);
        return rev;
    }

    void fft(vector<cpx> &f, bool is_reverse) {
        int n = f.size();
        int len = __builtin_ctz(n);
        
        for (int i = 0; i < n; i++) {
            int j = bitReverse(i, len);
            if (i < j) swap(f[i], f[j]);
        }
        // ...
    }

// 빠른코드
    void fft(vector<cpx> &f, bool is_reverse) {
        int n = f.size();

        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j >= bit; bit >>= 1) j -= bit;
            j += bit;
            if (i < j) swap(f[i], f[j]);
        }
        // ...
    }
```

### 참고링크
https://algoshitpo.github.io/2020/05/20/fft-ntt/   