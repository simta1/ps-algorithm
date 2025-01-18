[카테고리](/README.md)
## LCA(Lowest Common Ancestor, Binary Lifting)
### fixed root
```cpp
class Tree {
private:
    const int root = 1;
    int maxDepth;
    vector<int> depth;
    vector<vector<int> > adj, ac; //ancestor

    void makeTree(int cur, int parent) { // 1-based
        depth[cur] = depth[parent] + 1;
        ac[cur][0] = parent;
        for (int i = 1; i <= maxDepth; i++) ac[cur][i] = ac[ac[cur][i - 1]][i - 1];
        for (int next : adj[cur]) if (next != parent) makeTree(next, cur);
    }

public:
    Tree(int n) : depth(n + 1), adj(n + 1), maxDepth(floor(log2(n))), ac(n + 1, vector<int>(maxDepth + 1)) { // 1-based
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        makeTree(root, 0);
    }

    int getLCA(int a, int b) { // 1-based // fixed root
        if (depth[a] > depth[b]) swap(a, b);
        int diff = depth[b] - depth[a];
        while (diff) {
            b = ac[b][__builtin_ctz(diff)];
            diff &= (diff - 1);
        }

        if (a == b) return a;

        for (int i = maxDepth; i >= 0; i--) if (ac[a][i] != ac[b][i]) a = ac[a][i], b = ac[b][i];
        return ac[a][0];
    }
    
    int getLCA(int root, int a, int b) { // 1-based // unfixed root
        int x = getLCA(root, a);
        int y = getLCA(root, b);
        int res = getLCA(a, b);
        if (depth[res] < depth[x]) res = x;
        if (depth[res] < depth[y]) res = y;
        return res;
    }
};
```

### TODO 
https://blog.naver.com/PostList.naver?blogId=fkddl1436&from=postList&categoryNo=7 처럼 depth대신 dfsn으로 계산하는 게 더 효율적임   
https://www.acmicpc.net/problem/33150 은 depth로 구현하는 게 더 편한 듯, 오프라인 쿼리로 dfsn 먼저 계산해두면 dfsn으로도 구현할 수 있을 거 같긴 함   

### 시간복잡도 
preprocessing $O(N~logN)$   
getLCA $O(logN)$

### 문제
[LCA 2](https://www.acmicpc.net/problem/11438) - fixed root   
[LCA와 쿼리](https://www.acmicpc.net/problem/15480) - unfixed root

### 원리
LCA(r, u, v)는 fixed root에 대한 LCA(r, u), LCA(u, v), LCA(v, r) 중 깊이가 가장 깊은 것을 고르면 된다.