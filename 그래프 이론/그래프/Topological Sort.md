[카테고리](/README.md)
### Topological Sort
```cpp
class Graph {
   private:
    int n;
    vector<vector<int> > adj;
    vector<int> inDegree;

   public:
    Graph(int n) : n(n), adj(n + 1), inDegree(n + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        ++inDegree[v];
    }

    vector<int> topologicalSort() {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<int> sorted;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            sorted.push_back(cur);

            for (int next : adj[cur]) {
                if (--inDegree[next] == 0) q.push(next);
            }
        }

        return sorted;
    }
};
```
### 시간복잡도 
O(V + E)

### 사용관련
topologicalSort()에서 sorted.size() != n이라면 사이클이 존재

### 백준문제
[줄 세우기](https://www.acmicpc.net/problem/2252)