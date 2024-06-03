[카테고리](/README.md)
# 부호에 따라 1, 0, -1 리턴
```cpp
return (x > 0) - (x < 0);
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

# 사이값 확인
```cpp
// 변경 전
return (a < b && b < c) || (c < b && b < a);

// 변경 후
return (b > a) != (b > c);
```