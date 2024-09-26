[Cornacchia](/수학/Cornacchia.md)   
[카테고리](/README.md)
## 이산 제곱근 (Tonelli-Shanks)
```cpp
ll multiply(ll a, ll b, ll mod) {
    return a * b % mod;
    // return __int128(a) * b % mod;
}

ll power(ll a, ll n, ll mod) { //a ^ n % mod
    ll res = 1;

    while (n) {
        if (n & 1) res = multiply(res, a, mod);
        a = multiply(a, a, mod);
        n >>= 1;
    }

    return res;
}

ll tonelliShanks(ll n, ll p) { // x^2 === n (mod p) // 해가 없다면 -1 리턴
    assert (n >= 0 && n < p);
    
    if (!n) return 0;
    if (p == 2) return n;
    if (power(n, (p - 1) / 2, p) != 1) return -1;

    ll Q = p - 1, S = 0;
    while (~Q & 1) {
        Q >>= 1;
        ++S;
    }

    ll z;
    do {z = rand() % (p - 2) + 2;} while (power(z, (p - 1) / 2, p) == 1);

    ll M = S;
    ll c = power(z, Q, p);
    ll t = power(n, Q, p);
    ll R = power(n, (Q + 1) / 2, p);

    while (t != 1) {
        ll i = [&]() {
            ll tmp = t;
            for (int i = 1; i < M; i++) {
                tmp = power(tmp, 2, p);
                if (tmp == 1) return i;
            }
        }();

        ll b = power(c, power(2, M - i - 1, p - 1), p); // c ^ (2 ^ (M - i - 1)), phi(p) = p - 1
        M = i;
        c = multiply(b, b, p);
        t = multiply(t, c, p);
        R = multiply(R, b, p);
    }
    
    return R;
}
```
### 시간복잡도 
$O(log^2{p})$   

### 문제
[제곱수의 합 2 (More Huge)](https://www.acmicpc.net/problem/17646)

### 원리
작성 예정

### 참고링크
https://en.wikipedia.org/wiki/Tonelli%E2%80%93Shanks_algorithm   
https://00ad-8e71-00ff-055d.tistory.com/74   
https://rkm0959.tistory.com/20   