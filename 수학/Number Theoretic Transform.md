[카테고리](/README.md)
### NTT
```cpp
template <ll mod, ll primitiveRoot>
class NTT {
private:
    ll multiply(ll a, ll b) {
        return __int128(a) * b % mod;
    }

    ll power(ll a, ll n) { //a ^ n % mod
        ll res = 1;

        while (n) {
            if (n & 1) res = multiply(res, a);
            a = multiply(a, a);
            n >>= 1;
        }

        return res;
    }

    ll modInv(ll a) {
        return power(a, mod - 2);
    }

public:
    NTT() {
        // assert(isPrime(mod) && isPrimitiveRoot(primitiveRoot, mod))
    }

    void ntt(vector<ll> &f, bool is_reverse) {
        int n = f.size();

        for (int i = 1, j = 0; i < n; i++) {
            int bit = n / 2;
            while (j >= bit) {
                j -= bit;
                bit /= 2;
            }
            j += bit;
            if (i < j) swap(f[i], f[j]);
        }

        vector<ll> root(n / 2, 1);
        ll w = power(primitiveRoot, (mod - 1) / n);
        if (is_reverse) w = modInv(w);
        for (int i = 1; i < root.size(); i++) root[i] = multiply(root[i - 1], w);
        
        for (int m = 2; m <= n; m *= 2) {
            int step = n / m;
            for (int i = 0; i < n; i += m) {
                for (int j = 0; j < m / 2; j++) {
                    ll even = f[i + j];
                    ll odd = multiply(root[step * j], f[i + j + m / 2]);
                    f[i + j] = (even + odd) % mod;
                    f[i + j + m / 2] = (even - odd) % mod;
                    if (f[i + j + m / 2] < 0) f[i + j + m / 2] += mod;
                }
            }
        }

        if (is_reverse) {
            ll oon = modInv(n); // one over n
            for (auto &e : f) e = multiply(e, oon);
        }
    }
    
    template <typename T>
    vector<ll> multiply(const vector<T> &v1, const vector<T> &v2) {
        vector<ll> a(v1.begin(), v1.end());
        vector<ll> b(v2.begin(), v2.end());

        int n = 2;
        while (n < a.size() + b.size()) n <<= 1;

        a.resize(n);
        b.resize(n);
        
        ntt(a, false);
        ntt(b, false);

        for (int i = 0; i < n; i++) a[i] = multiply(a[i], b[i]);
        ntt(a, true);

        return a;
    }
};
```
### 소수, 원시근 예시
```cpp
NTT<998'244'353, 3> ntt;
NTT<2'281'701'377, 3> ntt;
NTT<2'483'027'969, 3> ntt;
```
### 시간복잡도 
$O(N~logN)$   

### 주의사항
이유를 모르겠는데 multiply함수에서 n(resize()할 크기) 계산할 때 FFT 코드에서 했던 방식으로 계산하면 안된다. [백준 질문 게시판](https://www.acmicpc.net/board/view/142161)   
```cpp
// FFT
int n = 1;
while (n <= a.size() || n <= b.size()) n <<= 1;
n <<= 1;

// NTT
int n = 2;
while (n < a.size() + b.size()) n <<= 1;
```
NTT에서 n계산부분만 바꿔서 제출해보면 틀렸다고 나온다.   

### 백준문제
[큰 수 곱셈 (2)](https://www.acmicpc.net/problem/15576)   
[큰 수 곱셈 (3)](https://www.acmicpc.net/problem/22289)