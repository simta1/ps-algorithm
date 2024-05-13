[카테고리](/README.md)
### Dijkstra
```cpp
template <typename T>
class Graph {
private:
    const T INF;
    vector<vector<pair<int, T> > > adj;
    vector<T> dist;

public:
    Graph(int n) : INF(numeric_limits<T>::max()), adj(n + 1), dist(n + 1) {}

    void addEdge(int u, int v, T w) { // 1-based
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }

    void dijkstra(int start) { // 1-based
        fill(dist.begin(), dist.end(), INF);
        dist[start] = 0;

        priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > pq;
        pq.push({dist[start], start});

        while (!pq.empty()) {
            auto [distance, cur] = pq.top();
            pq.pop();

            if (distance > dist[cur]) continue;

            for (auto &[next, cost] : adj[cur]) if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
                pq.push({dist[next], next});
            }
        }
    }

    T getDist(int end) { // 1-based
        return dist[end];
    }
};
```
### 시간복잡도 
$O(E~logV)$   

### 주의사항
모든 간선의 가중치가 0 이상일 때만 사용 가능   
음수 가중치 존재 시 벨만-포드 사용   

### 사용관련
간선이 양방향일 경우 addEdge()함수에서 주석 해제   

### 백준문제
[최소비용 구하기](https://www.acmicpc.net/problem/1916)   
[거의 최단 경로](https://www.acmicpc.net/problem/5719) - 다익스트라 + 최단경로 역추적
