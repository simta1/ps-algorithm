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
### 시간복잡도 
$O(VE^2)$   

### 백준문제
[도시 왕복하기 1](https://www.acmicpc.net/problem/17412)

### 참고문헌
https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm