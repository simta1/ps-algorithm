### 부분집합 순회
```cpp
for (int i = mask; i > 0; i = (i - 1) & mask){
    cout << mask << "(" << bitset<N>(mask) << ") " << bitset<N>(i) << "\n";
}

// ex) mask = 11101
// 29(11101) 11101
// 29(11101) 11100
// 29(11101) 11001
// 29(11101) 11000
// 29(11101) 10101
// 29(11101) 10100
// 29(11101) 10001
// 29(11101) 10000
// 29(11101) 01101
// 29(11101) 01100
// 29(11101) 01001
// 29(11101) 01000
// 29(11101) 00101
// 29(11101) 00100
// 29(11101) 00001
```
mask의 부분집합들 중 공집합만 제외하고 전부 순회

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