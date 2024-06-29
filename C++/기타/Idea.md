[카테고리](/README.md)
# 부호에 따라 1, 0, -1 변환
```cpp
int sign = (x > 0) - (x < 0); // int -> sign(1, 0, -1)
char c = "-0+"[sign + 1]; // sign -> char('-', '0', '+')
```

# 소수점 n자리에서 올림
```cpp
// ex) 올림해서 둘째 자리까지 출력
cout << fixed << setprecision(2) << ans + 0.00499999 << "\n";
```

# cyclic 순회
```cpp
// 변경 전 코드, % 사용해서 엄청 느림
for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
}

// 변경 후
for (int i = 0, j = n - 1; i < n; j = i++) {}
```

# 정수 이등분
```cpp
int half1 = x + 1 >> 1;
int half2 = x >> 1;
```
x = x / 2 + (x + 1) / 2   
x기우성 상관없이 항상 성립   

# 사이값 확인
```cpp
// 변경 전
return (a < b && b < c) || (c < b && b < a);

// 변경 후
return (b > a) != (b > c);
```

# 오차 없는 ceil
```cpp
return (a + b - 1) / b; // ceil(a / b)
```
ceil(a / b)로 그냥 ceil() 사용할 경우 부동소수점 오류로 오차 생기는 경우 존재   

# 오차 없는 log2
```cpp
constexpr int log2f(int x) { return 63 - __builtin_clzll(x); }
constexpr int log2c(int x) { return 64 - __builtin_clzll(x - 1); }
```