[카테고리](/README.md)
## Bellman-Ford
```cpp
template <typename T>
class Graph {
private:
    struct Edge {
        int u, v;
        T w;
    };

    int n;
    const T INF;
    vector<Edge> edges;
    vector<T> dist;

public:
    Graph(int n) : n(n), INF(numeric_limits<T>::max()), dist(n + 1) {}

    void addEdge(int u, int v, T w) { // 1-based
        edges.push_back({u, v, w});
    }

    bool bellmanFord(int start) { // 1-based
        fill(dist.begin(), dist.end(), INF);
        dist[start] = 0;

        int it = n - 1;
        while (it--) {
            for (auto &[cur, next, cost] : edges) if (dist[cur] != INF) {
                dist[next] = min(dist[next], dist[cur] + cost);
            }
        }

        for (auto &[cur, next, cost] : edges) if (dist[cur] != INF) {
            if (dist[next] > dist[cur] + cost) return false;
        }

        // for (auto &e : dist) {
        //     if (e == INF) e = -1;
        // }

        return true;
    }

    T getDist(int end) { // 1-based
        return dist[end];
    }
};
```
### 시간복잡도 
$O(VE)$   
다익스트라보다 느리지만 음수 가중치 존재 시에도 사용 가능

### 사용설명
bellmanFord()는 음수 간선 순환 발생 시(비용을 무한히 줄일 수 있는 경우) false 리턴   

### 문제
[최소비용 구하기](https://www.acmicpc.net/problem/1916)
