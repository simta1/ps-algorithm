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
### 시간복잡도 
$O(\sqrt{N})$   
폴라드 로 사용 시 $O(\sqrt[4]{N})$

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