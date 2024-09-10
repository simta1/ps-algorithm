[카테고리](/README.md)
## Harmonic Lemma
### $\displaystyle\sum_{k=1}^{n} \left\lfloor \dfrac{n}{k} \right\rfloor$ 계산
```cpp
template <typename T>
ll harmonic(T n) { // [n/1] + [n/2] + ... + [n/n]
    ll ans = 0;
    T sq = sqrt(n);
    for (T i = 1; i <= sq; i++) ans += n / i;
    for (T i = sq + 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        ans += n / i * (j - i + 1);
    }
    return ans;
}
```
### $\displaystyle\sum_{k=1}^{n} \left\lfloor \dfrac{x}{k} \right\rfloor$ 계산
```cpp
template <typename T>
ll harmonicSum(T n, T x) { // [x/1] + [x/2] + ... + [x/n]
    n = min(x, n);
    ll ans = 0;
    T sq = sqrt(x);
    for (T i = 1; i <= sq; i++) ans += x / i;
    for (T i = sq + 1, j; i <= n; i = j + 1) {
        j = min(n, x / (x / i));
        ans += x / i * (j - i + 1);
    }
    return ans;
}
```
### 시간복잡도 
$O(\sqrt N)$   

### 사용설명
$\displaystyle\sum_{k=1}^{n} f \left( \left\lfloor \dfrac{n}{k} \right\rfloor \right) g(k) $ 계산하는 법  
`ans += n / i * (j - i + 1);` 수정   
`n / i` -> `f(n / i)`   
`(j - i + 1)` -> `pfs_g(j) - pfs_g(i - 1)`   

### 문제
[잘못 구현한 에라토스테네스의 체](https://www.acmicpc.net/problem/15897)

### 원리
`n / i = n / j`를 만족하는 최대 j계산   
`j <= n / (n / i)`   
`i <= sqrt(n)`이라면 `n / i != n / (i + 1)` 즉, `max(j) = i`

아래 코드에서 i <= sqrt(n)인 경우만 따로 계산한 게 위 코드
```cpp
template <typename T>
ll harmonic(T n) { // sum_{k=1}^{n} [n/k]
    ll ans = 0;
    for (T i = 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        ans += n / i * (j - i + 1);
    }
    return ans;
}
```
```cpp
template <typename T>
ll harmonicSum(T n, T x) { // [x/1] + [x/2] + ... + [x/n]
    n = min(x, n);
    ll ans = 0;
    for (T i = 1, j; i <= n; i = j + 1) {
        j = min(n, x / (x / i));
        ans += x / i * (j - i + 1);
    }
    return ans;
}
```

### 참고링크
https://ahgus89.github.io/algorithm/Harmonic-Lemma/