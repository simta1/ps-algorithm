[카테고리](/README.md)
### ETT(dfs ordering)
```cpp
class Tree {
private:
    const int root = 1;
    vector<vector<int> > adj;
    vector<pair<int, int> > range;
    int dfsn;

    void dfs(int cur, int parent) {
        range[cur].first = ++dfsn;
        for (int next : adj[cur]) if (next != parent) {
            dfs(next, cur);
        }
        range[cur].second = dfsn;
    }

public:
    Tree(int n) : adj(n + 1), range(n + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void eulerTour() {
        dfsn = 0;
        dfs(root, -1);
    }

    pair<int, int> getRange(int x) {
        return range[x];
    }
};

```
### 시간복잡도 
dfs 한 번. $O(N)$

### 사용관련
auto [s, e] = getRange(x);   
[s, e] : 하위노드들(x포함)   
[s + 1, e] : 하위노드들(x 미포함)   

### 백준문제
[자동차 공장](https://www.acmicpc.net/problem/2820)