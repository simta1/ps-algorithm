[카테고리](/README.md)
## constexpr
### if constexpr
```cpp
// ex)
template <typename T>
void f(T val) {
    if constexpr (is_integral_v<T>) // 정수일 때 코드
    else // 정수 아닐 때 코드
}

// ex) Graph
template <bool directed>
class Graph {
public:
vector<vector<int> > adj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        if constexpr (!directed) adj[v].push_back(u);
    }
}

```
if constexpr의 조건에 맞는 코드만 컴파일되고 아닌 코드는 컴파일 타임에 제거된다.   
if constexpr 속의 조건은 컴파일 타임에 평가될 수 있어야 하므로 리터럴이나 constexpr함수, constexpr변수만 사용해야 한다.   

### static constexpr + 람다
static 변수의 생성자와 함께 한 번만 실행되길 원하는 코드가 있는 경우 람다함수를 사용할 수 있다. (당연히 람다 말고 constexpr함수 선언해두고 써도 되긴 함)
```cpp
// 한 번만 실행되도록 하기 위해 static bool initialized변수를 사용해도 되지만
void f() {
    static array<int, 5> v = {1, 2, 3, 4, 5};
    static bool initialized = false;
    if (!initialized) {
        initialized = true;
        for (int i = 1; i < 5; i++) v[i] += v[i - 1];
    }
}

// 람다 사용하는 게 좀 더 나음
void f() {
    static constexpr array<int, 13> v = []() {
        array<int, 13> res = {1, 2, 3, 4, 5};
        for (int i = 1; i < 5; ++i) res[i] += res[i - 1];
        return res;
    }();
}
```