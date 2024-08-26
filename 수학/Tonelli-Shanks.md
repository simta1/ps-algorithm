[카테고리](/README.md)
## Tonelli-Shanks
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
### 시간복잡도 
$O()$   

### 문제
[제곱수의 합 2 (More Huge)](https://www.acmicpc.net/problem/17646)

### 원리
작성 예정

### 참고링크
https://en.wikipedia.org/wiki/Tonelli%E2%80%93Shanks_algorithm