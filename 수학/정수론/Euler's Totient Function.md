[카테고리](/README.md)
### Euler's Totient(Phi) Function
```cpp
ll phi(ll n) {
    ll res = n, p = 2;

    while (p * p <= n) {
        if (n % p == 0) res = res / p * (p - 1);
        while (n % p == 0) n /= p;
        ++p;
    }
    if (n > 1) res = res / n * (n - 1);

    return res;
}
```
### [Pollard Rho](/수학/정수론/PollardRho.md) 사용 
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

### 백준문제
[GCD(n, k) = 1](https://www.acmicpc.net/problem/11689) - $O(\sqrt{N})$   
[gcd(n, k) = 1](https://www.acmicpc.net/problem/13926) - $O(\sqrt[4]{N})$

### 원리
$phi(n) = n \times \prod_{i=1}^{}(\frac{p_i-1}{p_i})$