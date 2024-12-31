[오일러 파이 함수](/수학/Phi%20Function.md)   
[밀러 라빈](/수학/MillerRabin.md)   
[카테고리](/README.md)   
## Pollard Rho
### [Miller Rabin](/수학/MillerRabin.md)
<details>
<summary>밀러 라빈 소수 판별법 코드</summary>

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

bool isPrime(ll n) { // 밀러-라빈, O(7 log^3(N) )
    if (n <= 1) return false;

    ll d = n - 1, r = 0;
    while (~d & 1) d >>= 1, ++r;

    auto check = [&](ll a) {
        ll remain = power(a, d, n);
        if (remain == 1 || remain == n - 1) return true;
        
        for (int i = 1; i < r; i++) {
            remain = multiply(remain, remain, n);
            if (remain == n - 1) return true;
        }

        return false;
    };

    vector<ll> nums = {2,325, 9375, 28178, 450775, 9780504, 1795265022};
    for (ll a : nums) if (a % n && !check(a)) return false;
    return true;
}
```
</details>

### Pollard Rho
```cpp
namespace PollardRho {
    ll getPrime(ll n) {
        if (~n & 1) return 2;
        if (isPrime(n)) return n;

        ll a, b, c, g;
        auto f = [&c, &n](ll x) { return (multiply(x, x, n) + c) % n; };

        do {
            a = b = rand() % (n - 2) + 2;
            c = rand() % 10 + 1;

            do {
                a = f(a);
                b = f(f(b));
                g = __gcd(abs(a - b), n);
            } while (g == 1);
        } while (g == n);

        return getPrime(g);
    }

    vector<pair<ll, ll> > factorize(ll n) {
        vector<pair<ll, ll> > primes;

        while (n > 1) {
            ll prime = getPrime(n), cnt = 0;
            while (n % prime == 0) n /= prime, ++cnt;
            primes.push_back({prime, cnt});
        }
        
        sort(primes.begin(), primes.end());
        return primes;
    }
    
    vector<ll> getAllDivisors(ll n) {
        auto factors = factorize(n);
        
        int cnt = 1;
        for (auto [p, e] : factors) cnt *= e + 1;

        vector<ll> res = {1};
        res.reserve(cnt);
        
        for (auto [p, e] : factorize(n)) {
            int sz = res.size();
            ll curP = p;
            for (int _ = e; _--;) {
                for (int i = 0; i < sz; i++) res.push_back(res[i] * curP);
                curP *= p;
            }
        }
        
        assert(false, "정렬 필요한지 확인");
        // sort(res.begin(), res.end());
        
        return res;
    }
}
```
### 시간복잡도 
$O(\sqrt[4]N)$   

### 구현 주의사항
PollardRho::getPrime()는 2를 찾지 못하기 때문에 따로 2의 배수인지 확인해야 된다. (getPrime()함수 첫번째 줄 코드)

### 문제
[큰 수 소인수분해](https://www.acmicpc.net/problem/4149)