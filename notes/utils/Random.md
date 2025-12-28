[카테고리](/README.md)
## Random
```cpp
template <typename T>
class Random {
    mt19937 engine;
    uniform_int_distribution<T> distribution;
    
public:
    Random(T mn, T mx) : engine(chrono::system_clock::now().time_since_epoch().count()), distribution(mn, mx) {} // mn, mx 포함하는 범위에서 난수 생성
    T operator()() { return distribution(engine); }
};
```

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