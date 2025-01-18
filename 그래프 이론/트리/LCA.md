[카테고리](/README.md)
## LCA(Lowest Common Ancestor, Binary Lifting)
```cpp
class Tree {
private:
    const int root = 1;
    vector<int> dep;
    vector<vector<int> > adj, ac; //ancestor

    int getAc(int cur, int pow) { // cur의 2^pow번째 조상
        return pow < ac[cur].size() ? ac[cur][pow] : -1;
    }

    void makeTree(int cur, int parent) { // 1-based
        if (cur != root) {
            dep[cur] = dep[parent] + 1;
            ac[cur].resize(32 - __builtin_clz(dep[cur])); // log2f(dep[cur]) + 1
            ac[cur][0] = parent;
            for (int i = 1; i < ac[cur].size(); i++) ac[cur][i] = getAc(ac[cur][i - 1], i - 1);
        }

        for (int next : adj[cur]) if (next != parent) makeTree(next, cur);
    }

public:
    Tree(int n) : dep(n + 1), adj(n + 1), ac(n + 1) { // 1-based
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        makeTree(root, 0);
    }

    int getLCA(int a, int b) { // 1-based // fixed root
        if (dep[a] > dep[b]) swap(a, b);
        int diff = dep[b] - dep[a];
        while (diff) {
            b = ac[b][__builtin_ctz(diff)];
            diff &= (diff - 1);
        }

        if (a == b) return a;

        for (int i = ac[a].size() - 1; i >= 0; i--) if (getAc(a, i) != getAc(b, i)) a = ac[a][i], b = ac[b][i];
        return ac[a][0];
    }
    
    int getLCA(int root, int a, int b) { // 1-based // unfixed root
        int x = getLCA(root, a);
        int y = getLCA(root, b);
        int res = getLCA(a, b);
        if (dep[res] < dep[x]) res = x;
        if (dep[res] < dep[y]) res = y;
        return res;
    }
};
```

### TODO 
https://blog.naver.com/fkddl1436/223701943267 처럼 depth대신 dfsn으로 계산하는 게 더 효율적임   
https://www.acmicpc.net/problem/33150 은 depth로 구현하는 게 더 편한 듯, 오프라인 쿼리로 dfsn 먼저 계산해두면 dfsn으로도 구현할 수 있을 거 같긴 함   

### 시간복잡도 
preprocessing $O(N~logN)$   
getLCA $O(logN)$

### 문제
[LCA 2](https://www.acmicpc.net/problem/11438) - fixed root   
[LCA와 쿼리](https://www.acmicpc.net/problem/15480) - unfixed root

### 원리
LCA(r, u, v)는 fixed root에 대한 LCA(r, u), LCA(u, v), LCA(v, r) 중 깊이가 가장 깊은 것을 고르면 된다.