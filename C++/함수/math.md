[카테고리](/README.md)
## math

### 수학 상수
```cpp
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

int main() {
    cout << M_PI << "\n"; // PI
    cout << M_E << "\n"; // 자연로그 밑 e
    
    return 0;
}
```
보통 `#include` 전에 적음

### 삼각함수
```cpp
auto rad = deg / 180 * PI;
cout << sin(rad) << " " << cos(rad);
```
라디안 단위임에 주의   
asin, acos 등도 라디안으로 리턴함   

### atan, atan2
```cpp
atan(y / x) // -PI/2 ~ PI/2 반환
atan2(y, x) // -PI ~ PI 반환
```
첫번째 매개변수가 y임에 주의   