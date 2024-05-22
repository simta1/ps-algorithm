[카테고리](/README.md)
### Edmonds–Karp
```cpp
template <typename T>
class Graph {
private:
    int n;
    vector<vector<int> > adj;
    vector<vector<T> > cap;

public:
    Graph(int n) : n(n), adj(n + 1), cap(n + 1, vector<T>(n + 1, 0)) {}

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
            T f = numeric_limits<T>::max();
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
    vector<vector<T> > cap;

    void _addEdge(int a, int b, T c) {
        adj[a].push_back(b);
        adj[b].push_back(a); // residual graph
        cap[a][b] += c;
    }

    int in(int a) { return 2 * a - 2; }
    int out(int a) { return 2 * a - 1; }

public:
    Graph(int n) : N(2 * n), adj(N), cap(N, vector<T>(N, 0)) {
        for (int i = 1; i <= n; i++) _addEdge(in(i), out(i), 1);
    }

    void addEdge(int a, int b, T c=1) {
        _addEdge(out(a), in(b), 1);
        _addEdge(out(b), in(a), 1);
    }

    int maxFlow(int s, int e) {
        const T INF = numeric_limits<T>::max();
        int tmpS = cap[in(s)][out(s)];
        int tmpE = cap[in(e)][out(e)];
        cap[in(s)][out(s)] = INF;
        cap[in(e)][out(e)] = INF;

        int res = 0;
        vector<vector<T> > flow(N, vector<T>(N, 0));
        vector<int> parent(N);

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

        cap[in(s)][out(s)] = tmpS;
        cap[in(e)][out(e)] = tmpE;

        return res;
    }
};
```
### 시간복잡도 
$O(VE^2)$   

### 백준문제
[도시 왕복하기 1](https://www.acmicpc.net/problem/17412)    
[도시 왕복하기 2](https://www.acmicpc.net/problem/2316) - 정점분할, [참고](https://www.acmicpc.net/board/view/102712)   

### 참고문헌
https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm