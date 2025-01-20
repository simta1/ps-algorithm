[카테고리](/README.md)
### Extended GCD
```cpp
tuple<ll, ll, ll> extendedGCD(ll a, ll b) { // ax + by = gcd(a, b)
    if (b == 0) return {1, 0, a};

    auto [x, y, g] = extendedGCD(b, a % b);
    return {y, x - (a / b) * y, g};
}
```
### Modular Inverse
```cpp
ll modInverse(ll a, ll b) {
    auto [x, y, g] = extendedGCD(a, b); //ax + by = g
    if (g == 1) return (x + b) % b;
    return -1;
}
```
mod하는 수가 소수라면 페르마의 소정리에 따라 $a^{-1} \equiv a^{p-2} \pmod{p}$로 계산할 수도 있다.   

### 시간복잡도 
$O(logN)$   

### 사용설명
modInverse(n, MOD);로 사용

__$1, 2, ..., n$ 각각의 모듈러 역원을 $O(N+\log{MOD})$에 전부 계산하는 법__   
$1!, ..., n!$과 팩토리얼들의 모듈러 역원을 계산해 사용   
```cpp
vector<ll> fac(n + 1, 1);
for (int i = 2; i < fac.size(); i++) fac[i] = fac[i - 1] * i % mod;

vector<ll> facInv(fac.size(), modInverse(fac.back(), mod));
for (int i = facInv.size() - 1; i > 0; i--) facInv[i - 1] = facInv[i] * i % mod;

vector<ll> inv(n + 1, 1);
for (int i = 2; i < inv.size(); i++) inv[i] = facInv[i] * fac[i - 1] % mod;
```

__모듈러가 소수 p일 때 $1, 2, ..., n$ 각각의 모듈러 역원을 $O(N)$에 전부 계산하는 법__
```cpp
vector<ll> inv(n + 1, 1);
for (int i = 2; i <= n; ++i) inv[i] = (p - ((p / i) * inv[p % i]) % p) % p;
```
$p = \left\lfloor \dfrac{p}{n} \right\rfloor n + p \% n$   

$-\left\lfloor \dfrac{p}{n} \right\rfloor n \equiv p \% n \pmod{p}$   

$n^{-1} \equiv -\left\lfloor \dfrac{p}{n} \right\rfloor (p \% n)^{-1} \pmod{p}$   

p가 소수이므로 $p \% n$은 항상 0이 아니고 따라서 $(p \% n)^{-1}$의 값도 잘 정의된다.   
반대로 p가 합성수라면 쓸 수 없는 방법이다.   

### 문제
[Σ](https://www.acmicpc.net/problem/13172)   

### 원리
베주항등식 $ax_1 + by_1 = g$ 는 항상 해를 가짐   
$let)~ a=bk+r$   
$(bk + r)x_1 + by_1 = g$   
$b(kx_1+y_1) + rx_1 = g$   
$let)~ x_2 = kx_1+y_1, y_2=x_1$   
$\therefore x_1=y_2, y_1 = x_2-ky_2$

### 참고링크
https://rkm0959.tistory.com/182   