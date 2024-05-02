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
페르마의 소정리에 의해 $a^{-1} \equiv a^{p-2} (mod~p)$이므로 분할정복으로 거듭제곱을 계산하는 방법도 있다.

### 시간복잡도 
$O(logN)$   

### 사용관련
modInverse(n, MOD);로 사용

### 백준문제
[Σ](https://www.acmicpc.net/problem/13172)

### 원리
베주항등식 $ax_1 + by_1 = g$ 는 항상 해를 가짐   
$let)~ a=bk+r$   
$(bk + r)x_1 + by_1 = g$   
$b(kx_1+y_1) + rx_1 = g$   
$let)~ x_2 = kx_1+y_1, y_2=x_1$   
$\therefore x_1=y_2, y_1 = x_2-ky_2$
