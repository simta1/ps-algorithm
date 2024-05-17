[카테고리](/README.md)
### LCA (Binary Lifting) - fixed root
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
        int diff = depth[b] - depth[a];
        while (diff) {
            b = ac[b][log2(diff & -diff)];
            diff &= (diff - 1);
        }

        if (a == b) return a;

        for (int i = maxDepth; i >= 0; i--) {
            if (ac[a][i] != ac[b][i]) {
                a = ac[a][i];
                b = ac[b][i];
            }
        }
        return ac[a][0];
    }
};
```
### LCA (Binary Lifting) - unfixed root
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

    int getLCA(int a, int b) { // root : 1
        if (depth[a] > depth[b]) swap(a, b);
        int diff = depth[b] - depth[a];
        while (diff) {
            b = ac[b][log2(diff & -diff)];
            diff &= (diff - 1);
        }

        if (a == b) return a;

        for (int i = maxDepth; i >= 0; i--) {
            if (ac[a][i] != ac[b][i]) {
                a = ac[a][i];
                b = ac[b][i];
            }
        }
        return ac[a][0];
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

    int getLCA(int root, int u, int v) {
        int a = getLCA(root, u);
        int b = getLCA(u, v);
        int c = getLCA(v, root);
        
        int res = a;
        if (depth[res] < depth[b]) res = b;
        if (depth[res] < depth[c]) res = c;
        return res;
    }
};
```
### 시간복잡도 
preprocessing $O(N~logN)$   
getLCA $O(logN)$

### 백준문제
[LCA 2](https://www.acmicpc.net/problem/11438) - fixed root   
[LCA와 쿼리](https://www.acmicpc.net/problem/15480) - unfixed root

### 원리
LCA(r, u, v)는 fixed root에 대한 LCA(r, u), LCA(u, v), LCA(v, r) 중 깊이가 가장 깊은 것을 고르면 된다.