[카테고리](/README.md)
## Dijkstra
```cpp
template <bool directed, typename T>
class Graph {
private:
    const T INF;
    int n;
    vector<vector<pair<int, T> > > adj;

public:
    Graph(int n) : INF(numeric_limits<T>::max()), n(n), adj(n + 1) {}

    void addEdge(int u, int v, T w) { // 1-based
        adj[u].push_back({v, w});
        if constexpr (!directed) adj[v].push_back({u, w});
    }

    pair<vector<T>, vector<int> > dijkstra(int start) { // 1-based
        vector<T> dist(n + 1, INF);
        dist[start] = 0;

        vector<int> path(n + 1, -1);

        priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > pq;
        pq.push({dist[start], start});

        while (!pq.empty()) {
            auto [distance, cur] = pq.top();
            pq.pop();

            if (distance > dist[cur]) continue;

            for (auto [next, cost] : adj[cur]) if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
                pq.push({dist[next], next});
                path[next] = cur;
            }
        }
        
        return {dist, path};
    }
};
```
### 경로 역추적
```cpp
auto trace = [&path](int start, int end) {
    vector<int> res;
    for (int cur = end; cur != start; cur = path[cur]) res.push_back(cur);
    res.push_back(start);
    reverse(res.begin(), res.end());
    return res;
};
```
### 시간복잡도 
$O(E~logV)$   

### 사용설명
모든 간선의 가중치가 0 이상일 때만 사용 가능   
음수 가중치 존재 시 벨만-포드 사용   

간선이 양방향일 경우 addEdge()함수에서 주석 해제   

### 문제
[최소비용 구하기](https://www.acmicpc.net/problem/1916)   
[최소비용 구하기](https://www.acmicpc.net/problem/11779) - 경로 역추적   
[거의 최단 경로](https://www.acmicpc.net/problem/5719) - 간선 활성화/비활성화
