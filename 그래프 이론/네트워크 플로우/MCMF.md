[카테고리](/README.md)
### MCMF
```cpp
template <typename C, typename F> // C : cost, F : flow
class Graph {
private:
    int n;
    C DIST_INF;
    vector<vector<pair<int, C> > > adj;
    F FLOW_INF;
    vector<vector<F> > cap;

public:
    Graph(int n) : n(n), DIST_INF(numeric_limits<C>::max()), adj(n + 1), FLOW_INF(numeric_limits<F>::max()), cap(n + 1, vector<F>(n + 1, 0)) {}

    void addEdge(int a, int b, C c, F capacity=1) { // 1-based
        adj[a].push_back({b, c});
        adj[b].push_back({a, -c}); // residual graph
        if (!~capacity || cap[a][b] == FLOW_INF) cap[a][b] = FLOW_INF;
        else cap[a][b] += capacity;
        // cap[b][a] = cap[a][b];
    }

    pair<C, F> mcmf(int s, int e) { // 1-based
        C minCost = 0;
        F maxFlow = 0;

        vector<vector<F> > flow(n + 1, vector<F>(n + 1, 0));
        vector<int> parent(n + 1);

        vector<C> dist(n + 1);
        vector<bool> inqueue(n + 1, 0);

        auto SPFA = [&]() { // find augmenting path
            fill(parent.begin(), parent.end(), -1);

            fill(dist.begin(), dist.end(), DIST_INF);
            dist[s] = 0;

            queue<int> q;
            q.push(s);
            inqueue[s] = true;
            
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                inqueue[cur] = false;

                for (auto &[next, cost] : adj[cur]) if (cap[cur][next] > flow[cur][next] && dist[next] > dist[cur] + cost) {
                    dist[next] = dist[cur] + cost;
                    parent[next] = cur;
                    
                    if (!inqueue[next]) {
                        q.push(next);
                        inqueue[next] = true;
                    }
                }
            }

            return dist[e] != DIST_INF;
        };

        while (SPFA()) {
            F f = FLOW_INF;
            for (int cur = e; cur != s; cur = parent[cur]) {
                int prev = parent[cur];
                f = min(f, cap[prev][cur] - flow[prev][cur]);
            }

            for (int cur = e; cur != s; cur = parent[cur]) {
                int prev = parent[cur];
                flow[prev][cur] += f;
                flow[cur][prev] -= f;
            }
            minCost += f * dist[e];
            maxFlow += f;
        }

        return {minCost, maxFlow};
    }
};
```
### 시간복잡도 
average $O(Ef)$   
worst $\Omega(VEf)$   
SPFA의 속도에 따라 달라진다.   
f는 최대 유량   

### 사용관련
간선 추가할 때 가중치의 부호를 바꿔 저장하면 최대 비용 최대 유량도 계산 가능   

### 백준문제
[열혈강호 5](https://www.acmicpc.net/problem/11408)   

### 참고문헌
https://m.blog.naver.com/kks227/220810623254    
https://www.crocus.co.kr/1090   