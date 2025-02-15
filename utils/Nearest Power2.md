[카테고리](/README.md)
## Nearest Power of 2
```cpp
long long pow2GE(long long n) { return 1LL << 64 - __builtin_clzll(n) - !(n & ~-n); }
long long pow2LE(long long n) { return 1LL << 63 - __builtin_clzll(n); }
long long pow2G(long long n) { return 1LL << 64 - __builtin_clzll(n); }
long long pow2L(long long n) { return 1LL << 63 - __builtin_clzll(n) - !(n & ~-n); }
```
### 동치코드
```cpp
long long pow2GE(long long n) { return 1LL << 63 - __builtin_clzll(n) + !!(n & ~-n); }
long long pow2G(long long n) { return 1LL << 63 - __builtin_clzll(n) + 1; }
```