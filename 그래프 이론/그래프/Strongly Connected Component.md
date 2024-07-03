[카테고리](/README.md)
### SCC - Tarjan's algorithm
```cpp
class Graph {
private:
    int n, dfsn, sccn;
    vector<vector<int> > adj;
    vector<int> visited, sccNumber;
    stack<int> s;

    int dfs(int cur) {
        int res = visited[cur] = dfsn++;
        s.push(cur);

        for (int next : adj[cur]) {
            if (!~visited[next]) res = min(res, dfs(next));
            else if (!~sccNumber[next]) res = min(res, visited[next]);
        }

        if (res == visited[cur]) {
            while (1) {
                int node = s.top();
                s.pop();
                sccNumber[node] = sccn;
                if (node == cur) break;
            }
            ++sccn;
        }

        return res;
    }

public:
    Graph(int n) : n(n), adj(n + 1), visited(n + 1, -1), sccNumber(n + 1, -1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    vector<vector<int> > findSCC() {
        dfsn = sccn = 0;

        for (int i = 1; i <= n; i++) if (!~visited[i]) {
            dfs(i);
        }

        vector<vector<int> > sccList(sccn);
        for (int i = 1; i <= n; i++) sccList[sccn - 1 - sccNumber[i]].push_back(i);
        
        return sccList;
    }
};
```
### 시간복잡도 
$O(V + E)$   

### 주의사항
타잔 알고리즘으로 SCC를 구할 경우 위상정렬의 역순이 되므로 sccNumber의 값이 클수록 위상정렬 시 앞 쪽에 위치

### 백준문제
[Strongly Connected Component](https://www.acmicpc.net/problem/2150)