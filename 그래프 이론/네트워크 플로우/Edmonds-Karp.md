[카테고리](/README.md)
### Edmonds–Karp
```cpp
template <typename T>
class Graph {
private:
    int n;
    vector<vector<int> > adj;
    T INF;
    vector<vector<T> > cap;

public:
    Graph(int n) : n(n), adj(n + 1), INF(numeric_limits<T>::max()), cap(n + 1, vector<T>(n + 1, 0)) {}

    void addEdge(int a, int b, T c=1) {
        adj[a].push_back(b);
        adj[b].push_back(a); // residual graph
        cap[a][b] += c;
    }

    int maxFlow(int s, int e) {
        int res = 0;
        vector<vector<T> > flow(n + 1, vector<T>(n + 1, 0));
        vector<int> parent(n + 1);

        auto bfs = [&]() { // find augmenting path
            fill(parent.begin(), parent.end(), -1);

            queue<int> q;
            q.push(s);
            
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (auto &next : adj[cur]) if (!~parent[next] && cap[cur][next] > flow[cur][next]) {
                    q.push(next);
                    parent[next] = cur;
                    if (next == e) return true;
                }
            }

            return false;
        };

        while (bfs()) {
            T f = INF;
            for (int cur = e; cur != s; cur = parent[cur]) {
                int prev = parent[cur];
                f = min(f, cap[prev][cur] - flow[prev][cur]);
            }

            for (int cur = e; cur != s; cur = parent[cur]) {
                int prev = parent[cur];
                flow[prev][cur] += f;
                flow[cur][prev] -= f;
            }
            res += f;
        }

        return res;
    }
};
```
### 정점분할
```cpp
template <typename T>
class Graph {
private:
    int N;
    vector<vector<int> > adj;
    T INF;
    map<pair<int, int>, T> cap;

    void _addEdge(int a, int b, T c) {
        adj[a].push_back(b);
        adj[b].push_back(a); // residual graph
        if (!~c || cap[{a, b}] == INF) cap[{a, b}] = INF;
        else cap[{a, b}] += c;
    }

    int in(int a) { return 2 * a - 2; } // 1-based
    int out(int a) { return 2 * a - 1; } // 1-based

public:
    Graph(int n) : N(2 * n), adj(N), INF(numeric_limits<T>::max()) { // 1-based
        for (int i = 1; i <= n; i++) _addEdge(in(i), out(i), 1);
    }

    void addEdge(int a, int b, T c=1) { // 1-based
        _addEdge(out(a), in(b), c);
        _addEdge(out(b), in(a), c);
    }

    int maxFlow(int s, int e) { // 1-based
        int tmpS = cap[{in(s), out(s)}];
        int tmpE = cap[{in(e), out(e)}];
        cap[{in(s), out(s)}] = INF;
        cap[{in(e), out(e)}] = INF;

        int start = in(s);
        int end = out(e);

        int res = 0;
        map<pair<int, int>, T> flow;
        vector<int> parent(N);

        auto bfs = [&]() { // find augmenting path
            fill(parent.begin(), parent.end(), -1);

            queue<int> q;
            q.push(start);
            
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (auto &next : adj[cur]) if (!~parent[next] && cap[{cur, next}] > flow[{cur, next}]) {
                    q.push(next);
                    parent[next] = cur;
                    if (next == end) return true;
                }
            }

            return false;
        };

        while (bfs()) {
            T f = INF;
            for (int cur = end; cur != start; cur = parent[cur]) {
                int prev = parent[cur];
                f = min(f, cap[{prev, cur}] - flow[{prev, cur}]);
            }

            for (int cur = end; cur != start; cur = parent[cur]) {
                int prev = parent[cur];
                flow[{prev, cur}] += f;
                flow[{cur, prev}] -= f;
            }
            res += f;
        }

        cap[{in(s), out(s)}] = tmpS;
        cap[{in(e), out(e)}] = tmpE;

        return (res != INF ? res : -1);
    }
};
```
### 시간복잡도 
$O(VE^2)$   

### 주의사항
n 커질 때 메모리초과 방지하고자 cap, flow를 2차원 벡터 대신 map으로 선언

### 사용관련
무한간선 추가하려면 addEdge(a, b, c)에서 c=-1 사용   
maxFlow()의 리턴값이 -1이라면 최대유량이 무한한 경우   

미리 in(sink) -> out(sink)로 INF크기의 간선을 만들어 유량을 제한해두면 오버플로우 방지 가능   
정점분할 코드에만 적용해뒀음, 1번째 코드 사용할 때 조심해야 됨

### 백준문제
[도시 왕복하기 1](https://www.acmicpc.net/problem/17412)    
[도시 왕복하기 2](https://www.acmicpc.net/problem/2316) - 정점분할, [양방향 간선을 단방향으로 바꿀 수 있는 이유](https://www.acmicpc.net/board/view/102712)   
[학교 가지마!](https://www.acmicpc.net/problem/1420) - 정점분할, 무한간선

### 참고문헌
https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm