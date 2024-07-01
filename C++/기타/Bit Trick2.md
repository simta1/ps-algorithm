### 최우측 1비트 (count trailing zeros)
```cpp
__builtin_ctz(n) // int
__builtin_ctzll(n) // long long
```
### 최좌측 1비트 (count leading zeros)
```cpp
31 - __builtin_clz(n) // int
63 - __builtin_clzll(n) // long long
```

### 응용
```cpp
ll mnBit = 1LL << __builtin_ctzll(val); // ex) 11010 -> 10
ll mxBit = 1LL << 63 - __builtin_clzll(val); // ex) 11010 -> 10000
```

### n 미만 자연수 중 가장 큰 2의 거듭제곱
```cpp
assert(n > 1);
return 1LL << 63 - __builtin_clzll(n) - !(n & (n - 1));
```
### n 이하 자연수 중 가장 큰 2의 거듭제곱
```cpp
assert(n > 1);
return 1LL << 63 - __builtin_clzll(n);
```