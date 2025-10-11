[Cornacchia](/수학/Cornacchia.md)   
[카테고리](/README.md)
## 이산 제곱근
### Tonelli-Shanks
```cpp
inline ll multiply(ll a, ll b, ll mod) { return __int128(a) * b % mod; }

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
### 이차합동식
```cpp
pll quadraticCongruence(ll a, ll b, ll p) { // x^2 + ax + b === 0 (mod p) // 해가 없다면 {-1, -1} 리턴
    assert (a >= 0 && a < p);
    assert (b >= 0 && b < p);
    
    if (p == 2) {
        if (a && b) return {-1, -1};
        if (a && !b) return {0, 1};
        if (!a && b) return {1, 1};
        return {0, 0};
    }
    else {
        ll c = (a + (a & 1) * p) >> 1;
        ll d = (c * c % p - b + p) % p;
        ll sqr = tonelliShanks(d, p);
        if (!~sqr) return {-1, -1};
        return {(p - c + p - sqr) % p, (p - c + sqr) % p};
    }
}
```
### 시간복잡도 
$O(log^2{p})$   

### 구현 주의사항
원래 tonelliShanks가 p=2일 땐 작동하지 않기에 (`rand() % (p - 2)` 코드 때문) 이차합동식을 풀 때 p=2인 경우를 따로 예외처리했음   

이제는 tonelliShanks내부에서 p=2일 때를 처리하도록 해서 상관없긴 함   

### 사용설명
p는 소수   

n이 mod p에 대한 2차잉여가 아닐 경우 -1 리턴   
리턴된 `R` 말고도 `(p - R) % p`또한 해가 됨

### 문제
[Factorization](https://www.acmicpc.net/problem/17603) - 이차합동식   
[제곱수의 합 2 (More Huge)](https://www.acmicpc.net/problem/17646)   

### 원리 (이차합동식)
$\left( x + \dfrac{a}{2} \right)^2 \equiv -b + \left( \dfrac{a}{2} \right)^2 \pmod{p}$   

$c := \dfrac{a}{2} \pmod{p}$   

$d := c^2 - b \pmod{p}$   


### 참고링크
https://en.wikipedia.org/wiki/Tonelli%E2%80%93Shanks_algorithm   
https://00ad-8e71-00ff-055d.tistory.com/74   
https://rkm0959.tistory.com/20   