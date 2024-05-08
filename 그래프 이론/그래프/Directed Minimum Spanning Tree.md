[카테고리](/README.md)
### DMST
```cpp
template <typename T>
class Graph {
private:
    struct Edge {
        int u, v;
        T w;
    };

    int n;
    vector<Edge> edges;

public:
    Graph(int n) : n(n) {}

    void addEdge(int u, int v, T w) { // 1-based
        edges.push_back({u, v, w});
    }

    T dmst(int root) {
        vector<int> comp(n + 1); // compressed
        vector<pair<int, T> > minIn(n + 1);
        const T INF = numeric_limits<T>::max();

        T res = 0;

        int curN = n;
        while (1) {
            fill(minIn.begin(), minIn.end(), pair<int, T>{-1, INF});
            for (auto &[cur, next, cost] : edges) if (cur != next) {
                if (minIn[next].second > cost) minIn[next] = {cur, cost};
            }

            minIn[root] = {-1, 0};
            for (int i = 1; i <= curN; i++) res += minIn[i].second;

            int nextN = 0;
            fill(comp.begin(), comp.end(), -1);
            comp[root] = ++nextN;
            
            for (int i = 1; i <= curN; i++) if (!~comp[i]) {
                int cur;
                for (cur = i; !~comp[cur]; cur = minIn[cur].first) comp[cur] = 0;
                if (!comp[cur]) {
                    ++nextN;
                    for (; !comp[cur]; cur = minIn[cur].first) comp[cur] = nextN;
                }
                for (cur = i; !comp[cur]; cur = minIn[cur].first) comp[cur] = ++nextN;
            }

            if (curN == nextN) break;

            curN = nextN;
            for (auto &[cur, next, cost] : edges) {
                cost -= minIn[next].second;
                cur = comp[cur];
                next = comp[next];
            }

            root = comp[root];
        }

        return res;
    }
};
```
### 시간복잡도 
$O(VE)$   

### 사용관련
```cpp
for (int i = 1; i <= curN; i++) res += minIn[i].second;
```
DMST 불가능한 경우 -1 리턴하게 만들기
```cpp
for (int i = 1; i <= curN; i++) {
    if (minIn[i].second == INF) return -1;
    res += minIn[i].second;
}
```

### 백준문제
[미생물 키우기](https://www.acmicpc.net/problem/16127)

### 참고문헌
https://gina65.tistory.com/23   
https://koosaga.com/265