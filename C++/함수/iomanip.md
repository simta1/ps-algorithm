[카테고리](/README.md)
## Input/Output manipulators
### setfill, setw
```cpp
cout << setfill('0') << setw(3) << num << "\n";
```
setfill은 패딩문자, setw는 패딩길이 설정   

### fixed, setprecision
```cpp
cout << fixed << setprecision(9) << num << "\n";
```
setprecision은 출력할 숫자의 길이 지정   
fixed할 경우 소수점 밑 숫자의 길이만 계산   

ex) cout << setprecision(5); 정수부분 + 소수부분 합친 총 자리수가 5자리가 되도록 출력   
ex) cout << fixed << setprecision(5); 소수점 밑 5자리까지 출력   

### 진법
```cpp
cout << oct << 10 << "\n"; // 12 // 8진수, octal
cout << dec << 10 << "\n"; // 10 // 10진수, decimal
cout << hex << 10 << "\n"; // a // 12진수, hexadecimal
```

2진수는 manipulator 없어서 비트셋으로 출력하는 게 꽤 유용하다.   
log2f(x)가 `63 - __builtin_clzll(x)`이므로 출력해야 될 길이는 1을 더한 `64 - __builtin_clzll(x)`가 된다.   
```cpp
cout << bitset<64 - __builtin_clzll(10)>(10) << "\n"; // 1010 // 2진수
```

### 영구적용 여부
| 일시적 | 영구적 |
|--------|--------|
| setw   | setfill |
|        | fixed, setprecision |
|        | oct, dec, hex |


setw는 setw이후 단 한번의 출력에만 적용된다.
```cpp
// ex)
cout << setfill('0') << setw(2) << "ab" << 1; // ab1
cout << setfill('0') << "ab" << setw(2) << 1; // ab01
cout << setfill('0') << setw(2) << 1 << ":" << 3; // 01:3
cout << setfill('0') << setw(2) << 1 << ":" << setw(2) << 3; // 01:03
```

### 참고링크
https://en.cppreference.com/w/cpp/io/manip