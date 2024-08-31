[카테고리](/README.md)
## Nearest Power of 2
```cpp
long long powGE(long long n) { return 1LL << 64 - __builtin_clzll(n) - !(n & ~-n); }
long long powLE(long long n) { return 1LL << 63 - __builtin_clzll(n); }
long long powG(long long n) { return 1LL << 64 - __builtin_clzll(n); }
long long powL(long long n) { return 1LL << 63 - __builtin_clzll(n) - !(n & ~-n); }
```
### 동치코드
```cpp
long long powGE(long long n) { return 1LL << 63 - __builtin_clzll(n) + !!(n & ~-n); }
long long powG(long long n) { return 1LL << 63 - __builtin_clzll(n) + 1; }
```