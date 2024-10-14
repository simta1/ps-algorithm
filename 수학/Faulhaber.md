[카테고리](/README.md)
## Faulhaber
<details>
<summary>모듈러 역원</summary>

```cpp
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

```
</details>

<details>
<summary>Combination(dp)</summary>

```cpp
template <typename T, T mod>
class Combination {
private:
    vector<vector<T> > dp;

public:
    Combination(int maxN, int maxR) : dp(maxN + 1, vector<T>(maxR + 1, -1)) {}
    Combination(int maxN) : Combination(maxN, maxN) {}

    T operator()(int n, int r) {
        if (r > n || r < 0) return 0;
        if (n == 1) return 1;
        if (r == 0 || r == n) return 1;
        
        T &res = dp[n][r];
        if (~res) return res;

        return res = ((*this)(n - 1, r - 1) + (*this)(n - 1, r)) % mod;
    }
};
```
</details>

$dp[k] = \dfrac{1}{k+1} \left\{ (n + 1)^{k+1} - 1 - \displaystyle\sum_{i=0}^{k-1} \binom{k+1}{i} dp[i] \right\}$   
```cpp
ll powSum(ll n, int k) { // 1^k + 2^k + ... + n^k
    const ll mod = 1e9 + 7;
    Combination<ll, mod> comb(k + 1);
    
    vector<ll> dp(k + 1, -1); //  DP[k] = 1^k + 2^k + ... + n^k
    dp[0] = n;

    for (int i = 1, pow = (n + 1) * (n + 1) % mod; i <= k; i++, pow = pow * (n + 1) % mod) {
        dp[i] = pow - 1; // (n + 1)^(i + 1) - 1
        for (int j = 0; j <= i - 1; j++) dp[i] = (dp[i] - comb(i + 1, j) * dp[j]) % mod;
        dp[i] += (dp[i] < 0) * mod;
        dp[i] = dp[i] * modInverse(i + 1, mod) % mod;
    }

    return dp[k];
}
```
### 시간복잡도
$O(K^2 logK)$   
$logK$는 모듈러 역원 때문에 붙음   

### 사용설명
$(1^k + 2^k + ... + n^k) \mod{M}$ 계산   

### 원리
<!-- TODO Faulhaber's formula 추가해야됨 -->
어쩌다보니 Faulhaber안썼음   
나중에 추가하려나   

### 문제
[합](https://www.acmicpc.net/problem/1492)

### 참고링크
https://en.wikipedia.org/wiki/Faulhaber%27s_formula   