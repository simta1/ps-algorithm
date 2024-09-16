[카테고리](/README.md)
## Phi Function(Euler's Totient Function)
### $ O(\sqrt{N}) $ 소인수분해 사용
```cpp
template <typename T>
T phi(T n) {
    T res = n;

    for (long long p = 2; p * p <= n; p++) if (n % p == 0) {
        while (n % p == 0) n /= p;
        res = res / p * (p - 1);
    }
    if (n > 1) res = res / n * (n - 1);

    return res;
}
```
### $ O(\sqrt[4]{N}) $ 소인수분해 사용([Pollard Rho](/수학/PollardRho.md))
```cpp
namespace PollardRho {
    //pollard rho code
}

ll phi(ll n) {
    ll res = n;
    for (auto &p : PollardRho::factorize(n)) res = res / p * (p - 1);
    return res;
}
```
### O(N) 함수 테이블 채우기
```cpp
vector<int> getPhi(int n) {
    vector<int> phi(n + 1);
    phi[1] = 1;

    vector<int> primes, lpf(n + 1); // least prime factor
    primes.reserve(n / log(n));

    for (ll i = 2; i <= n; i++) {
        if (!lpf[i]) {
            lpf[i] = i;
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for (auto p : primes) {
            if (i * p > n) break;
            lpf[i * p] = p;
            if (i % p == 0) {
                phi[i * p] = phi[i] * p;
                break;
            }
            else {
                phi[i * p] = phi[i] * phi[p];
            }
        }
    }

    return phi;
}
```
### 시간복잡도 
`phi[n]` 하나 계산 $O(\sqrt{N})$   
폴라드 로 사용 시 $O(\sqrt[4]{N})$   

`phi[1:n]` 전부 계산 $O(N)$   

### 구현 주의사항
n이 소수일 경우도 고려    
```cpp
if (n > 1) res = res / n * (n - 1);
```

### 문제
[GCD(n, k) = 1](https://www.acmicpc.net/problem/11689) - $O(\sqrt{N})$   
[gcd(n, k) = 1](https://www.acmicpc.net/problem/13926) - $O(\sqrt[4]{N})$

### 원리
$phi(n) = n \times \prod_{i=1}^{}(\frac{p_i-1}{p_i})$

### 참고링크
곱셈적 함수 linear sieve   
https://ps.mjstudio.net/linear-sieve#%EC%9D%91%EC%9A%A9-1---%EC%86%8C%EC%9D%B8%EC%88%98%EB%B6%84%ED%95%B4   