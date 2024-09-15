[카테고리](/README.md)
## Harmonic Lemma
### $\displaystyle\sum_{k=1}^{n} \left\lfloor \dfrac{n}{k} \right\rfloor$ 계산
```cpp
template <typename T>
ll harmonicSum(T n) { // [n/1] + [n/2] + ... + [n/n]
    ll res = 0;
    T sq = sqrt(n);
    for (T i = 1; i <= sq; i++) res += n / i;
    for (T i = sq + 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        res += n / i * (j - i + 1);
    }
    return res;
}
```
### $\displaystyle\sum_{k=1}^{min(m, n)} \left\lfloor \dfrac{m}{k}  \right\rfloor\left\lfloor \dfrac{n}{k} \right\rfloor$ 계산
```cpp
template <typename T>
ll harmonicSum(T n) { // [m/1][n/1] + [m/2][n/2] + ... + [m/min(m,n)][n/min(m,n)]
    ll res = 0;
    for (T i = 1, j; i <= n; i = j + 1) {
        j = min(m / (m / i), n / (n / i));
        res += (m / i) * (n / i) * (j - i + 1);
    }
    return res;
}
```
### $\displaystyle\sum_{k=1}^{n} \left\lfloor \dfrac{x}{k} \right\rfloor$ 계산
```cpp
template <typename T>
ll harmonicSum(T n, T x) { // [x/1] + [x/2] + ... + [x/n]
    n = min(x, n);
    ll res = 0;
    T sq = sqrt(x);
    for (T i = 1; i <= sq; i++) res += x / i;
    for (T i = sq + 1, j; i <= n; i = j + 1) {
        j = min(n, x / (x / i));
        res += x / i * (j - i + 1);
    }
    return res;
}
```
### $\displaystyle\sum_{k=1}^{n} f \left( \left\lfloor \dfrac{n}{k} \right\rfloor \right) g(k) $ 계산
```cpp
template <typename T>
ll harmonicSum(T n) { // f([n/1])g(1) + f([n/2])g(2) + ... + f([n/n])g(n)
    ll res = 0;
    T sq = sqrt(n);
    for (T i = 1; i <= sq; i++) res += f(n / i) * g(i);
    for (T i = sq + 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        res += f(n / i) * (pfs_g(j) - pfs_g(i - 1));
    }
    return res;
}
```
### 시간복잡도 
$O(\sqrt N)$   

### 문제
[잘못 구현한 에라토스테네스의 체](https://www.acmicpc.net/problem/15897)

### 원리
`n / i = n / j`를 만족하는 최대 j계산   
`j <= n / (n / i)`   
`i <= sqrt(n)`이라면 `n / i != n / (i + 1)` 즉, `max(j) = i`

아래 코드에서 i <= sqrt(n)인 경우만 따로 계산한 게 위 코드
```cpp
template <typename T>
ll harmonicSum(T n) { // [n/1] + [n/2] + ... + [n/n]
    ll res = 0;
    for (T i = 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        res += n / i * (j - i + 1);
    }
    return res;
}
```
```cpp
template <typename T>
ll harmonicSum(T n, T x) { // [x/1] + [x/2] + ... + [x/n]
    n = min(x, n);
    ll res = 0;
    for (T i = 1, j; i <= n; i = j + 1) {
        j = min(n, x / (x / i));
        res += x / i * (j - i + 1);
    }
    return res;
}
```

### 참고링크
https://ahgus89.github.io/algorithm/Harmonic-Lemma/   
https://codeforces.com/blog/entry/53925   
https://xy-plane.tistory.com/17   