[카테고리](/README.md)
# 최우측 1비트 (count trailing zeros)
```cpp
__builtin_ctz(n) // int
__builtin_ctzll(n) // long long
```
# 최좌측 1비트 (count leading zeros)
```cpp
31 - __builtin_clz(n) // int
63 - __builtin_clzll(n) // long long
```
왼쪽부터 1 나오기전까지 0 개수 (부호 비트 포함)

# popcount
```cpp
__builtin_popcount(n) // int
__builtin_popcountll(n) // long long
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
[nearest power](/utils/Nearest%20Power.md) 참고