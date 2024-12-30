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