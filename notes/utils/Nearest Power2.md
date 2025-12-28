[카테고리](/README.md)
## Nearest Power of 2
```cpp
long long pow2GE(long long n) { assert(n > 1); return 1LL << 64 - __builtin_clzll(n - 1); }
long long pow2LE(long long n) { assert(n > 0); return 1LL << 63 - __builtin_clzll(n); }
long long pow2GT(long long n) { assert(n > 0); return 1LL << 64 - __builtin_clzll(n); }
long long pow2LT(long long n) { assert(n > 1); return 1LL << 63 - __builtin_clzll(n - 1); }
```
`__builtin_clz(0)`은 UB라서 주의해야 됨   

### 시간복잡도
$O(1)$   