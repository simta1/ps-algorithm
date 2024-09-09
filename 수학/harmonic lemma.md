[카테고리](/README.md)
## Harmonic Lemma
### 최적화 코드
```cpp
template <typename T>
ll harmonic(T n) { // sum_{k=1}^{n} [n/k]
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
```cpp
### 기본 코드
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
### 시간복잡도 
$O(\sqrt N)$   

### 사용설명
harmonic(n)은 $\displaystyle\sum_{k=1}^{n} \lfloor \dfrac{n}{k} \rfloor$ 계산   

### 문제
[잘못 구현한 에라토스테네스의 체](https://www.acmicpc.net/problem/15897)

### 원리
`n / i = n / j`를 만족하는 최대 j계산   
`j <= n / (n / i)`   
`i <= sqrt(n)`이라면 `n / i != n / (i + 1)` 즉, `max(j) = i`

### 참고링크
https://ahgus89.github.io/algorithm/Harmonic-Lemma/