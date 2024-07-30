[카테고리](/README.md)
# 부호에 따라 1, 0, -1 변환
```cpp
int sign = (x > 0) - (x < 0); // int -> sign(1, 0, -1)
char c = "-0+"[sign + 1]; // sign -> char('-', '0', '+')

int sign = (x >> 31) - (-x >> 31); // 더 빠른 코드, 형변환 안 일어나서인지 속도차이 꽤 큼
```

# 소수점 n자리에서 올림
```cpp
// ex) 올림해서 둘째 자리까지 출력
cout << fixed << setprecision(2) << ans + 0.00499999 << "\n";
```

# 역방향 순회
```cpp
for (int i = 5; i--;) cout << i << " "; // 4 3 2 1 0

for (int i = v.size(); i--;) v[i];
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

# count in sorted vector
```cpp
int cnt = upper_bound(v.begin(), v.end(), val) - lower_bound(v.begin(), v.end(), val);
```

# search in sorted vector
```cpp
// x이하의 최대 원소
assert (v[0] <= x);
*--upper_bound(v.begin(), v.end(), x);

// x미만의 최대 원소
assert (v[0] < x);
*--lower_bound(v.begin(), v.end(), x);
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
return (a + b - 1) / b; // ceil(double(a) / b)
```
ceil(double(a) / b)로 계산할 경우 부동소수점 오차로 계산 잘못되는 경우 존재   

# 오차 없는 log2
```cpp
constexpr int log2f(int x) { return 63 - __builtin_clzll(x); }
constexpr int log2c(int x) { return 64 - __builtin_clzll(x - 1); }
```

# 벡터 끝쪽 원소 접근
```cpp
// 마지막 원소
v[v.size() - 1]
*(v.end() - 1)
*v.rbegin()
v.back()

*--v.end()

// 마지막 2번째 원소
*----v.end()

// ex) 볼록껍질 등 구현할 때
ccw(*----v.end(), *--v.end(), point)
```

# constrain
```cpp
return (val >= 0) * val;
return max(val, 0);
```