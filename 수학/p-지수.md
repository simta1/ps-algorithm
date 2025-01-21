[카테고리](/README.md)
## p-지수(p-adic valuation)
### p-지수 $v_p(n)$ 계산
```cpp
template <typename T>
T pAdicValuation(T n, T p) { // n!의 p-지수
    T res = 0;
    while (n) res += (n /= p);
    return res;
}
```

### $\dfrac{n!}{p^{v_p(n)}} \pmod{p^e}$ 계산 (p진법에서 n!의 0이 아닌 마지막 e자리)
```cpp
ll power(ll a, ll n, ll mod) { // a ^ n % mod
    ll res = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

ll pReducedFactorial(ll n, int p, int mod) { // mod는 p^e꼴 // n = p^t * m(t는 p-지수)라 할 때 m % p^e 계산
    vector<int> pFreeFac(mod, 1);
    for (int i = 2; i < mod; i++) pFreeFac[i] = i % p == 0 ? pFreeFac[i - 1] : pFreeFac[i - 1] * i % mod;

    function<int(int)> f = [&](int n) -> int {
        return n == 0 ? 1 : power(pFreeFac[mod - 1], n / mod, mod) * pFreeFac[n % mod] % mod * f(n / p) % mod;
    };
    return f(n);
}

```
### 시간복잡도 
p-지수 $O(\log_{p}{n})$   
`pReducedFactorial` $O\left(\log_{p}{n} * \log{n} \right)$ (전처리 $O(p^e)$)   

### 문제
[이항 계수 6](https://www.acmicpc.net/problem/14854)   

### 참고링크
https://rkm0959.tistory.com/182   