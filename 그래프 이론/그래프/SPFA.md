[카테고리](/README.md)
## SPFA (Shortest Path Faster Algorithm)
```cpp
template <typename T>
class Graph {
private:
    int n;
    vector<vector<pair<int, T> > > adj;
    vector<T> dist;

public:
    Graph(int n) : n(n), adj(n + 1), dist(n + 1) {}

    void addEdge(int u, int v, T w) {
        adj[u].push_back({v, w});
    }

    bool SPFA(int start) {
        const T INF = numeric_limits<T>::max();
        fill(dist.begin(), dist.end(), INF);
        dist[start] = 0;

        vector<int> inqueue(n + 1, 0), cnt(n + 1, 0);
        
        queue<int> q;
        q.push(start);
        inqueue[start] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            inqueue[cur] = false;

            if (++cnt[cur] >= n) return false;

            for (auto &[next, cost] : adj[cur]) if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
                if (!inqueue[next]) {
                    q.push(next);
                    inqueue[next] = true;
                }
            }
        }

        for (auto &e : dist) {
            if (e == INF) e = -1;
        }

        return true;
    }

    T getDist(int end) {
        return dist[end];
    }
};
```
### 시간복잡도 
average $O(E)$   
worst $\Omega(VE)$   

### 사용설명
SPFA()는 음수 간선 순환 발생 시(비용을 무한히 줄일 수 있는 경우) false 리턴   

### 문제
[타임머신](https://www.acmicpc.net/problem/11657)

### 참고링크
https://en.wikipedia.org/wiki/Shortest_path_faster_algorithm   
https://www.crocus.co.kr/1089