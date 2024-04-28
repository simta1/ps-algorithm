[카테고리](/README.md)
### Pollard Rho
```cpp
using ll = long long;
using pll = pair<ll, ll>;

ll multiply(ll a, ll b, ll mod) {
    return __int128(a) * b % mod;
}

namespace MillerRabin {
    ll power(ll a, ll n, ll mod) { //a ^ n % mod
        ll res = 1;

        while (n) {
            if (n % 2) res = multiply(res, a, mod);
            a = multiply(a, a, mod);
            n >>= 1;
        }

        return res;
    }

    bool isPrime(ll n) {
        if (n <= 1) return false;

        ll d = n - 1, r = 0;
        while (d % 2 == 0) {
            d >>= 1;
            ++r;
        }

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
        for (ll a : nums) if (a % n) {
            if (!check(a)) return false;
        }

        return true;
    }
}

namespace PollardRho {
    ll getPrime(ll n) {
        if (~n & 1) return 2;
        if (MillerRabin::isPrime(n)) return n;

        ll a, b, c, g;
        auto f = [&c, &n](ll x) {
            return (multiply(x, x, n) + c) % n;
        };

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

    vector<pll> factorize(ll n) {
        vector<pll> primes;

        while (n > 1) {
            ll prime = getPrime(n), cnt = 0;
            while (n % prime == 0) {
                n /= prime;
                ++cnt;
            }
            primes.push_back({prime, cnt});
        }
        
        sort(primes.begin(), primes.end());
        return primes;
    }
}
```
### 시간복잡도 
$O(\sqrt[4]N)$   

### 주의사항
PollardRho::getPrime()는 2를 찾지 못하기 때문에 따로 2의 배수인지 확인해야 된다. (getPrime()함수 첫번째 줄 코드)

### 백준문제
[큰 수 소인수분해](https://www.acmicpc.net/problem/4149)