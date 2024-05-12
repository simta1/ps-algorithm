[카테고리](/README.md)
### Articulation Point
```cpp
class Graph {
private:
    int n, order;
    vector<vector<int> > adj;
    vector<int> visited, isArticulation;

    int dfs(int cur, bool isRoot) {
        int res = visited[cur] = order++;
        
        int child = 0;
        for (int next : adj[cur]) {
            if (!~visited[next]) {
                ++child;
                int nextRet = dfs(next, false);
                if (!isRoot && nextRet >= visited[cur]) isArticulation[cur] = 1;
                res = min(res, nextRet);
            }
            else res = min(res, visited[next]);
        }

        if (isRoot && child > 1) isArticulation[cur] = 1;

        return res;
    }

public:
    Graph(int n) : n(n), adj(n + 1), visited(n + 1, -1), isArticulation(n + 1, 0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> getArticulationPoints() {
        order = 0;
        
        for (int i = 1; i <= n; i++) if(!~visited[i]) {
            dfs(i, true);
        }

        vector<int> v;
        for (int i = 1; i <= n; i++) if (isArticulation[i]) v.push_back(i);
        return v;
    }
};
```
### 시간복잡도 
$O(V + E)$   

### 백준문제
[단절점](https://www.acmicpc.net/problem/11266)

### 참고문헌
https://ip99202.github.io/posts/%EB%8B%A8%EC%A0%88%EC%A0%90-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/   
https://jisungbin.medium.com/%EA%B7%B8%EB%9E%98%ED%94%84-%EB%8B%A8%EC%A0%88%EC%A0%90-%EB%8B%A8%EC%A0%88%EC%84%A0-7496e3b49f9c   
https://bowbowbow.tistory.com/3