[카테고리](/README.md)
## 다항식 연산
### FFT (Fast Fourier Transform)
```cpp
namespace Poly { // FFT
    using ll = long long;
    int pow2GE(int n) { return 1 << __lg(n) + !!(n & (n - 1)); }
    
    vector<vector<pair<int, int> > > bitRev; // 비트 반전 저장 // 다항식 나눗셈 등에선 ntt()를 여러 번 호출하므로 비트 반전 결과를 캐싱해두면 좋다고 함
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
    void __transform(vector<T> &f, bool is_reverse, const vector<T> &roots) {
        int n = f.size();
        for (auto [i, j] : getBitRev(n)) swap(f[i], f[j]);

        for (int m = 2; m <= n; m <<= 1) {
            int step = n / m;
            for (int i = 0; i < n; i += m) {
                for (int j = 0; j < m / 2; j++) {
                    T even = f[i + j];
                    T odd = roots[step * j] * f[i + j + m / 2];
                    f[i + j] = even + odd;
                    f[i + j + m / 2] = even - odd;
                }
            }
        }

        if (is_reverse) for (auto &e : f) e /= T(n);
    }
    
    const long double PI = acos(-1);
    
    template <typename double_t>
    void fft(vector<complex<double_t> > &f, bool is_reverse) {
        int n = f.size();
        double_t ang = 2 * PI / n * (is_reverse ? -1 : 1);

        vector<complex<double_t> > roots(n / 2);
        for (int i = 0; i < n / 2; i++) roots[i] = complex<double_t>(cos(ang * i), sin(ang * i));

        __transform(f, is_reverse, roots);
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

        vector<ll> res(v1.size() + v2.size() - 1);
        for (int i = 0; i < res.size(); i++) res[i] = round(c1[i].real()) + (ll(round(c2[i].real())) << splitBit) + (ll(round(c3[i].real())) << 2 * splitBit);
        return res;
    }
}
```
### NTT (Number Theoretic Transform) ([ModInt](/utils/ModInt.md) 코드 필요)
```cpp
namespace Poly { // NTT
    template <ll p, ll primitiveRoot>
    void ntt(vector<ModInt<p> > &f, bool is_reverse) {
        int n = f.size();
        ModInt<p> w = ModInt<p>(primitiveRoot).pow((p - 1) / n);
        if (is_reverse) w = w.inv();
        
        vector<ModInt<p> > roots(n / 2, ModInt<p>(1));
        for (int i = 1; i < n / 2; i++) roots[i] = roots[i - 1] * w;
        __transform(f, is_reverse, roots);
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
```
### 다항식 나눗셈, 키타마사
```cpp
namespace Poly { // NTT 다항식 나눗셈, 키타마사
    template <ll p, ll primitiveRoot, typename T>
    vector<ll> invertMod(const vector<T> &f, int deg) { // f(x)^-1 mod x^deg 계산 // 계수는 mod p로 계산
        assert(f[0] != 0); // f(x)의 상수항이 0이면 역원이 존재하지 않음 // 참고로 divideMod(f, g)에서 g의 계수를 뒤집은 게 invertMod의 f이므로 f[0]!=0이란 건 divideMod에서 g의 최고차항의 계수가 0이 아니란 것과 동치임

        vector<ll> res = {ModInt<p>(f[0]).inv().value}; // f(x)^-1 mod x^1

        for (int curDeg = 1; curDeg < deg; curDeg <<= 1) {
            int nextDeg = curDeg << 1;

            // prod = f(x) * res(x)
            vector<ll> prod = multiplyMod<p, primitiveRoot>(res, vector<ll>(f.begin(), f.begin() + nextDeg));
            prod.resize(nextDeg);

            // prod = 2 - f(x) * res(x) (1이 되어야 함)
            if ((prod[0] -= 2) < 0) prod[0] += p;
            for (int i = 0; i < prod.size(); i++) if (prod[i] != 0) prod[i] = p - prod[i];

            // 새로운 res(x) = res(x) * (2 - f(x) * res(x))
            res = multiplyMod<p, primitiveRoot>(res, prod);
            res.resize(nextDeg);
        }

        res.resize(deg);
        return res;
    }

    template <ll p, ll primitiveRoot, typename T>
    pair<vector<ll>, vector<ll> > divideMod(const vector<T> &f, const vector<T> &g) {
        int n = f.size(), m = g.size();
        if (n < m) return {vector<ll>{0}, vector<ll>(f.begin(), f.end())};
        
        vector<ll> F(f.rbegin(), f.rend());
        vector<ll> G(g.rbegin(), g.rend());

        vector<ll> q = multiplyMod<p, primitiveRoot>(F, invertMod<p, primitiveRoot>(G, n - m + 1));
        q.resize(n - m + 1);
        reverse(q.begin(), q.end());

        // r(x) = f(x) - q(x) * g(x)
        vector<ll> r = multiplyMod<p, primitiveRoot>(q, g);
        r.resize(m - 1);

        for (int i = 0; i < m - 1; i++) {
            r[i] = (f[i] - r[i]) % p;
            if (r[i] < 0) r[i] += p;
        }

        return {q, r};
    }

    template <ll p, ll primitiveRoot, typename T>
    vector<ll> remainderMod(const vector<T> &f, const vector<T> &g) {
        return divideMod<p, primitiveRoot>(f, g).second;
    }

    template <ll p, ll primitiveRoot, typename T>
    vector<ll> kitamasaNTT(ll n, const vector<T> &g) { // f(x)=x^n에 대해 f % g 계산 // g차수 k일 때 O(K logK logN)
        vector<ll> res = {1};
        vector<ll> xn = {0, 1};
        
        while (n) {
            if (n & 1) res = remainderMod<p, primitiveRoot>(multiplyMod<p, primitiveRoot>(res, xn), g);
            xn = remainderMod<p, primitiveRoot>(multiplyMod<p, primitiveRoot>(xn, xn), g);
            n >>= 1;
        }

        return res;
    }

    template <typename T>
    vector<ll> kitamasaNaive(ll n, const vector<T> &g, const ll MOD) { // f(x)=x^n에 대해 f % g 계산 // g차수 k일 때 O(K^2 logN)
        vector<ll> res = {1};
        vector<ll> xn = {0, 1};

        auto add = [&MOD](ll &a, ll b) { a = (a + b) % MOD; };
        auto sub = [&MOD](ll &a, ll b) { a = (a - b) % MOD; if (a < 0) a += MOD; };

        auto multiplyModNaive = [&](const vector<ll> &a, const vector<ll> &b) {
            vector<ll> res(a.size() + b.size() - 1);
            for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size(); j++) add(res[i + j], a[i] * b[j]);
            return res;
        };

        auto remainderModNaive = [&](const vector<ll> &a, const vector<ll> &b) {
            vector<ll> res(a);
            for (int i = a.size() - 1; i >= b.size() - 1; i--) for (int j = 0; j < b.size(); j++) sub(res[i - (b.size() - 1 - j)], res[i] * b[j]);
            res.resize(b.size() - 1);
            return res;
        };
        
        while (n) {
            if (n & 1) res = remainderModNaive(multiplyModNaive(res, xn), g);
            xn = remainderModNaive(multiplyModNaive(xn, xn), g);
            n >>= 1;
        }

        return res;
    }
    
    template <ll p, ll primitiveRoot, typename T> // p = a * 2^b + 1 꼴 소수
    ll recurrenceNTT(ll n, const vector<T> &a, const vector<T> &coef) { // a는 초항{a1, a2, ..., ak}, c는 계수{c1, c2, ..., ck} // A_n = (C_1 x A_n−1 + C_2 x A_n−2 + ... + C_k x A_n−k) mod P일 때 A_n 계산
        if (n <= a.size()) return a[n - 1];

        vector<ll> f(coef.size() + 1, 1); // x^k - c_1 x^(k-1) - c_2 x^(k-2) - ... - c_k x^0
        for (int i = 0; i < coef.size(); i++) f[coef.size() - 1 - i] = -coef[i];
        auto d = kitamasaNTT<p, primitiveRoot>(n - 1, f); // x^(n-1)을 {x^k - c_1 x^(k-1) - c_2 x^(k-2) - ... - c_k x^0}로 나눈 나머지

        ll res = 0; // an = a1 * d1 + a2 * d2 + ... + ak * dk
        for (int i = 0; i < d.size(); i++) res = (res + a[i] * d[i]) % p;
        return res;
    }
    
    template <typename T> // p = a * 2^b + 1 꼴 소수
    ll recurrenceNaive(ll n, const vector<T> &a, const vector<T> &coef, const ll MOD) { // a는 초항{a1, a2, ..., ak}, c는 계수{c1, c2, ..., ck} // A_n = (C_1 x A_n−1 + C_2 x A_n−2 + ... + C_k x A_n−k) mod P일 때 A_n 계산
        if (n <= a.size()) return a[n - 1];

        vector<ll> f(coef.size() + 1, 1); // x^k - c_1 x^(k-1) - c_2 x^(k-2) - ... - c_k x^0
        for (int i = 0; i < coef.size(); i++) f[coef.size() - 1 - i] = -coef[i];
        auto d = kitamasaNaive(n - 1, f, MOD); // x^(n-1)을 {x^k - c_1 x^(k-1) - c_2 x^(k-2) - ... - c_k x^0}로 나눈 나머지와 같음
        
        ll res = 0; // an = a1 * d1 + a2 * d2 + ... + ak * dk
        for (int i = 0; i < d.size(); i++) res = (res + a[i] * d[i]) % MOD;
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

### 문제
[큰 수 곱셈 (2)](https://www.acmicpc.net/problem/15576)   
[큰 수 곱셈 (3)](https://www.acmicpc.net/problem/22289)   
[보석 가게](https://www.acmicpc.net/problem/13575)   
[씽크스몰](https://www.acmicpc.net/problem/11385) - NTT + CRT(`multiplyMod5e18()` 함수 사용하면 됨)   
[RNG](https://www.acmicpc.net/problem/13725) - 다항식 나눗셈(키타마사 필요)   

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
https://algoshitpo.github.io/2020/05/20/fft-ntt/ - fft, 정확도 높은 fft, ntt   
https://algoshitpo.github.io/2020/05/20/linear-recurrence/ - 다항식 나눗셈   
https://blog.myungwoo.kr/147 - 다항식 나눗셈 시간복잡도   
https://hyperbolic.tistory.com/4   