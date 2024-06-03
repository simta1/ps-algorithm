[카테고리](/README.md)
### Cornacchia
```cpp
pll cornacchia(ll m, ll d = 1) { // x^2 + dy^2 = m
    if (m == 2) return {1, 1};
    
    // m = 4k + 1, prime
    ll r0 = tonelliShanks(-d, m);

    ll prev = m, cur = r0;
    while (1) {
        ll next = prev % cur;
        prev = cur;
        cur = next;
        if (__int128(cur) * cur < __int128(m)) break;
    }
    return {cur, sqrtl((m - cur * cur) / d)};
}
```
### 시간복잡도 
$O()$   

### 백준문제
[제곱수의 합 2 (More Huge)](https://www.acmicpc.net/problem/17646)

### 원리
작성 예정

### 참고문헌
https://en.wikipedia.org/wiki/Cornacchia%27s_algorithm