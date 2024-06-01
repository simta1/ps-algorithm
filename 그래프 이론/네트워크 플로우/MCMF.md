[카테고리](/README.md)
### MCMF
```cpp
template <typename C, typename F> // C : cost, F : flow
class Graph {
private:
    struct Edge {
        int next;
        C cost;
        F capacity;
        int reverseEdgeIdx;
    };

    int n;
    C DIST_INF;
    vector<vector<Edge> > adj; // 간선 목적지, 거리, 흐를 수 있는 유량, 역간선 인덱스
    F FLOW_INF;
    vector<vector<F> > cap;

public:
    Graph(int n) : n(n), DIST_INF(numeric_limits<C>::max()), adj(n + 1), FLOW_INF(numeric_limits<F>::max()), cap(n + 1, vector<F>(n + 1, 0)) {}

    void addEdge(int a, int b, C c, F capacity=1) { // 1-based
        adj[a].push_back({b, c, capacity, int(adj[b].size())});
        adj[b].push_back({a, -c, 0, int(adj[a].size()) - 1}); // residual graph
        if (!~capacity || cap[a][b] == FLOW_INF) cap[a][b] = FLOW_INF;
        else cap[a][b] += capacity;
        // cap[b][a] = cap[a][b];
    }

    pair<C, F> mcmf(int s, int e) { // 1-based
        C minCost = 0;
        F maxFlow = 0;

        vector<vector<F> > flow(n + 1, vector<F>(n + 1, 0));
        vector<pair<int, int> > parent(n + 1); // parent[cur] = {prev, adj[prev][idx] = cur인 idx}

        vector<C> dist(n + 1);
        vector<bool> inqueue(n + 1, 0);

        auto SPFA = [&]() { // find augmenting path
            fill(parent.begin(), parent.end(), pair{-1, -1});

            fill(dist.begin(), dist.end(), DIST_INF);
            dist[s] = 0;

            queue<int> q;
            q.push(s);
            inqueue[s] = true;
            
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                inqueue[cur] = false;

                for (int i = 0; i < adj[cur].size(); i++) {
                    auto [next, cost, capacity, _] = adj[cur][i];
                    if (capacity && dist[next] > dist[cur] + cost) {
                        // cout << "dist[" << next << "]( = " << dist[next] << ")" << " > dist[" << cur << "]( = " << dist[cur] << ") + " << cost << "\n";
                        dist[next] = dist[cur] + cost;
                        parent[next] = {cur, i};
                        
                        if (!inqueue[next]) {
                            q.push(next);
                            inqueue[next] = true;
                        }
                    }
                }
            }

            return dist[e] != DIST_INF;
        };

        while (SPFA()) {
            F f = FLOW_INF;
            for (int cur = e; cur != s; cur = parent[cur].first) {
                auto [prev, _] = parent[cur];
                f = min(f, cap[prev][cur] - flow[prev][cur]);
            }

            for (int cur = e; cur != s; cur = parent[cur].first) {
                auto [prev, idx] = parent[cur];
                flow[prev][cur] += f;
                flow[cur][prev] -= f;
                adj[prev][idx].capacity -= f;
                adj[cur][adj[prev][idx].reverseEdgeIdx].capacity += f;
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

### 주의사항
adj를 vector<vector<pair<int, C> > > 로 하면 문제 생기는 경우 있음.   
[열혈강호 5](https://www.acmicpc.net/problem/11408)에서는 상관없었지만 [제독](https://www.acmicpc.net/problem/3640) 풀다가 문제 있는거 알게 되서 수정함.   
수정 전 코드는 아래 참고   

### 사용관련
간선 추가할 때 가중치의 부호를 바꿔 저장하면 최대 비용 최대 유량도 계산 가능   

### 백준문제
[열혈강호 5](https://www.acmicpc.net/problem/11408)   

### 참고문헌
https://m.blog.naver.com/kks227/220810623254    
https://www.crocus.co.kr/1090   

### 수정 전 코드
문제되는 상황 예시   
u->v 간선과 v->u간선 둘 다 존재한다면,   
spfa()에서 cur=u일 때 u->v실제 간선과 v->u의 역간선(유령 간선)을 확인하게 됨.   
이 때 유령간선의 경우 v->u로 흐르는 유량이 생기기 전까지는 cap[u][v] > flow[u][v] 조건에 의해서 고려되지 않아야 되지만, u->v실제 간선이 존재하므로 cap[u][v]의 값이 양수로 설정되어 있어 cap[u][v] > flow[u][v]를 만족하게 되고 유량이 흐르지 않는 상황인데도 유령간선을 고려하게 됨.   
또한 유령간선의 가중치는 실제간선과 부호가 다르므로 존재하지도 않는 음수사이클을 만들게 될 수가 있고, 이 경우 SPFA에서 dist가 계속 갱신되며 무한 루프가 됨   
최대 유량도 같은 방식으로 구현했지만 문제되지 않은 이유는 parent배열을 통해 방문체크를 하며 단순히 bfs를 하기 때문에 무한 루프 돌 일이 없기 때문   
해결하려면 adj에서 간선을 저장할 때 용량의 정보도 같이 저장하면 됨. 유령 간선이라면 애초에 adj[cur][i].capacity = 0으로 두고, 역방향의 실제 간선이 흘렀을 때 capacity의 값을 양수로 바꾸도록 하여 해결 가능.   
수정된 코드에서는 Edge 구조체를 만들어 vector<vector<Edge> >로 사용했음.    
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