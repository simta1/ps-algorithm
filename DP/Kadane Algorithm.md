[카테고리](/README.md)
### Kadane Algorithm
```cpp
template <typename T>
T kadane(const vector<T> &v) {
    T res = v[0], sum = 0;
    for (auto &e : v) {
        sum = max(sum, 0) + e;
        res = max(res, sum);
    }
    return res;
}
```
### 시간복잡도 
$O(N)$   

### 주의사항
v의 원소가 전부 음수일 수 있으니 res = 0으로 초기화하면 안 된다.   

### 사용관련
최소한 하나 이상의 값을 골라야 하는 경우의 구현이다.   
값을 아무것도 고르지 않는 것이 허용된다면 res = 0으로 초기화하면 된다.   

### 백준문제
[연속합](https://www.acmicpc.net/problem/1912)