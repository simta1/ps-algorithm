[카테고리](/README.md)
## Faulhaber
원래 Faulhaber쓰려 했는데 라그랑주 보간법이 훨씬 빨라서 내용 바꿈.   
그냥 귀찮아서 제목은 유지했지만 faulhaber아님.   
애초에 보간법 알면faulhaber를 알 필요 자체가 없어보임   

### 빠른 거듭제곱
<details>
<summary>코드</summary>

```cpp
ll power(ll a, ll n, ll mod) { // a ^ n % mod
    ll res = 1;
    while (n) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
```
</details>

### $1^k + 2^k +... + n^k$ 계산 ([라그랑주 보간법](/수학/라그랑주%20보간법.md) 사용)
```cpp
ll powerSum(ll n, int k, ll mod) {
    vector<ll> y(k + 2, 0);
    for (int x = 1; x <= k + 1; x++) y[x] = (y[x - 1] + power(x, k, mod)) % mod;
    return n < y.size() ? y[n] : lagrangeInterpolation(y, n, mod);
}
```
### 시간복잡도
$O(K \log{MOD})$   
$\log$는 라그랑주 보간법에서 모듈러 역원 때문에 붙음   
처음에 y좌표 계산할 때 빠른 거듭제곱 써도 $O(KlogK)$ 걸리긴 하지만 애초에 $K<=mod$라 무시함   

### 사용설명
$(1^k + 2^k + ... + n^k) \mod{M}$ 계산   

$O(K^2logK)$긴 하지만 아래처럼 DP로도 계산할 수 있긴 함(플레2정도의 풀이)   
$let)$ $dp[k] := 1^k + 2^k + ... + n^k$   
$dp[k] = \dfrac{1}{k+1} \left[ (n + 1)^{k+1} - 1 - \displaystyle\sum_{i=0}^{k-1} \binom{k+1}{i} dp[i] \right]$   

### 원리
$f(x) = 1^k + 2^k + ... + x^k = a_{k+1} x^{k+1} + a_k x^k + ... + a_0x^0$라 하면 k+2개의 좌표만 알면 보간법으로 계수를 유일하게 결정 가능   
`vector<ll> y`에 x=0, 1, ..., k+1에 대한 y좌표 저장한 뒤 보간법 사용

### 문제
[합](https://www.acmicpc.net/problem/1492) - $O(K^2logK)$ 가능   
[거듭제곱의 합 1](https://www.acmicpc.net/problem/25974) - $O(K^2logK)$ 가능   
[거듭제곱의 합 2](https://www.acmicpc.net/problem/27293) - $O(K \log{MOD})$   
[F. The Sum of the k-th Powers](https://codeforces.com/problemset/problem/622/F) - $O(K \log{MOD})$   

### 참고링크
https://en.wikipedia.org/wiki/Faulhaber%27s_formula   
https://codeforces.com/topic/113960/en1   
https://codeforces.com/blog/entry/23442   