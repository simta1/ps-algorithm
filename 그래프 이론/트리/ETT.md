[카테고리](/README.md)
## ETT(Euler Tour Technique, dfs ordering)
```cpp
class Tree {
private:
    const int root = 1;
    vector<vector<int> > adj;
    vector<int> in, out;
    int dfsn;

    void ett(int cur, int par) {
        in[cur] = ++dfsn;
        for (int next : adj[cur]) if (next != par) ett(next, cur);
        out[cur] = dfsn;
    }

public:
    Tree(int n) : adj(n + 1), in(n + 1), out(n + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void eulerTour() {
        dfsn = 0;
        ett(root, -1);
    }

    pair<int, int> getRange(int x) {
        return {in[x], out[x]};
    }
};
```
### 시간복잡도 
dfs 한 번. $O(N)$

### 사용설명
`auto [s, e] = getRange(x);`로 사용   
\[s, e\] : 하위노드들(x포함)   
\[s + 1, e\] : 하위노드들(x 미포함)   

### 문제
[자동차 공장](https://www.acmicpc.net/problem/2820)   