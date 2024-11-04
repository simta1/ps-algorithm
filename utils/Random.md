[카테고리](/README.md)
## Random
```cpp
template <typename T, T MIN, T MAX>
class Random {
    mt19937 engine;
    uniform_int_distribution<T> distribution;
    
public:
    Random() : engine(chrono::system_clock::now().time_since_epoch().count()), distribution(MIN, MAX) {}
    T operator()() { return distribution(engine); }
};
```
### 시간복잡도 
$O()$   

### 구현설명
(unsigned int)time(NULL) : 초 단위 현재 시간
chrono::system_clock::now().time_since_epoch().count() 나노초 단위 현재 시간

### 사용설명
난수 범위는 MIN, MAX를 포함

```cpp
int main() {
    Random<int, 0, 10> rand;
    for (int it = 10; it--;) cout << rand() << "\n";
}
```