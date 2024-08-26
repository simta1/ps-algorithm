[카테고리](/README.md)
## CRT(Chinese Remainder Theorem)
```cpp
using ll = long long;
using pll = pair<ll, ll>;

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

pll merge(const pll &a, const pll &b) {
    auto [p1, m1] = a;
    auto [p2, m2] = b;
    
    ll g = __gcd(p1, p2);
    if ((m2 - m1) % g) return {-1, -1};
    
    ll x = (m2 - m1) / g * modInverse(p1 / g, p2 / g) % (p2 / g);
    return {p1 / g * p2, p1 * x + m1};
}

pll crt(const vector<pll> &rems) {
    pll res(1, 0);

    for (auto &p : rems) {
        res = merge(res, p);
        if (res.first == -1) return {-1, -1};
    }

    if (res.second < 0) res.second += res.first;
    return res;
}
```
### 시간복잡도 
$O(N~logN)$   

### 사용설명
crt().first = -1이라면 연립합동식이 해를 가지지 않음

### 문제
[단어 굴리기](https://www.acmicpc.net/problem/1571)