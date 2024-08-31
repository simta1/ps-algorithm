[카테고리](/README.md)
## Cornacchia
### [Tonelli-Shanks](/수학/Tonelli-Shanks.md)
<details>
<summary>코드</summary>

```cpp
ll tonelliShanks(ll n, ll p) { // x^2 === n (mod p)
    n = (n + p) % p;

    ll Q = p - 1, S = 0;
    while (~Q & 1) {
        Q >>= 1;
        ++S;
    }

    ll z;
    do {z = rand() % (p - 2) + 2;} while (MillerRabin::power(z, (p - 1) / 2, p) == 1);

    ll M = S;
    ll c = MillerRabin::power(z, Q, p);
    ll t = MillerRabin::power(n, Q, p);
    ll R = MillerRabin::power(n, (Q + 1) / 2, p);

    while (t != 0 && t != 1) {
        ll i = [&]() {
            ll tmp = t;
            for (int i = 1; i < M; i++) {
                tmp = MillerRabin::power(tmp, 2, p);
                if (tmp == 1) return i;
            }
        }();

        ll b = MillerRabin::power(c, MillerRabin::power(2, M - i - 1, p - 1), p); // c ^ (2 ^ (M - i - 1)), phi(p) = p - 1
        M = i;
        c = multiply(b, b, p);
        t = multiply(t, c, p);
        R = multiply(R, b, p);
    }
    
    return t == 1 ? R : 0;
}
```
</details>

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
<!-- TODO -->

### 문제
[제곱수의 합 2 (More Huge)](https://www.acmicpc.net/problem/17646)

### 원리
<!-- TODO -->

### 참고링크
https://en.wikipedia.org/wiki/Cornacchia%27s_algorithm