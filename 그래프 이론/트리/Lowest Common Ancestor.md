[카테고리](/README.md)
### LCA
```cpp
class Tree {
private:
    int maxDepth;
    vector<int> depth;
    vector<vector<int> > adj, ac; //ancestor

    void makeTree(int cur, int parent) { // 1-based
        depth[cur] = depth[parent] + 1;

        ac[cur][0] = parent;
        for (int i = 1; i <= maxDepth; i++) {
            int ancestor = ac[cur][i - 1];
            ac[cur][i] = ac[ancestor][i - 1];
        }

        for (int next : adj[cur]) if (next != parent) {
            makeTree(next, cur);
        }   
    }

public:
    Tree(int n) : depth(n + 1), adj(n + 1), maxDepth(floor(log2(n))), ac(n + 1, vector<int>(maxDepth + 1)) {
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        makeTree(1, 0);
    }

    int getLCA(int a, int b) { // 1-based
        if (depth[a] > depth[b]) swap(a, b);
        for (int i = maxDepth; i >= 0; i--) {
            int ancestor = ac[b][i];
            if (depth[a] <= depth[ancestor]) b = ancestor;
        }

        int lca = a;
        if (a != b) {
            for (int i = maxDepth; i>= 0; i--) {
                if (ac[a][i] != ac[b][i]) {
                    a = ac[a][i];
                    b = ac[b][i];
                }
                lca = ac[a][i];
            }
        }

        return lca;
    }
};
```
### 시간복잡도 
초기화 $O(N~logN)$   
getLCA $O(logN)$

### 백준문제
[LCA 2](https://www.acmicpc.net/problem/11438)