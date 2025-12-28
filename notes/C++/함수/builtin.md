[카테고리](/README.md)
# 최우측 1비트 (count trailing zeros)
```cpp
__builtin_ctz(int_n) // int
__builtin_ctzll(ll_n) // long long
```
# 최좌측 1비트 (count leading zeros)
```cpp
__builtin_clz(int_n) // int
__builtin_clzll(ll_n) // long long
```
왼쪽부터 1 나오기전까지 0 개수 (부호 비트 포함)

어떤 수 x에 대해 $\lfloor \log_2{x} \rfloor$의 값은 x를 이진수로 나타냈을 때 최좌측 1비트의 오른쪽에 있는 수들의 개수와 같기 때문에 다음처럼 계산 가능
```cpp
31 - __builtin_clz(int_n) // 전체 비트 32개 중 최좌측1비트(1개) 자기자신과 최좌측비트의 좌측에 0의 개수(__builtin_clz(n))를 빼면 최좌측1비트 우측에 있는 수의 개수임
63 - __builtin_clzll(ll_n) // 
```

# popcount
```cpp
__builtin_popcount(int_n) // int
__builtin_popcountll(ll_n) // long long
```
---
# 양끝 비트 계산
```cpp
ll mnBit = 1LL << __builtin_ctzll(val); // ex) 11010 -> 10
ll mxBit = 1LL << 63 - __builtin_clzll(val); // ex) 11010 -> 10000
```
# 오차 없는 log2
```cpp
constexpr int log2f(ll x) { return 63 - __builtin_clzll(x); }
constexpr int log2c(ll x) { return 64 - __builtin_clzll(x - 1); }
```
# 가까운 2의 멱수 계산
[nearest power](/utils/Nearest%20Power2.md) 참고   