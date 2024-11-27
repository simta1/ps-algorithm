[카테고리](/README.md)
## HLD(heavy-light decomposition)
## 일단 테스트는 끝났지만 임시구현임, 수정 필요
```cpp
template <typename T>
class SegmentTree {
    // 상황에 맞는 세그먼트 트리 코드
};

class Tree {
private:
    const int root = 1;
    vector<vector<int> > adj, chd;
    vector<int> dep, par, sz;
    
    int dfsn;
    vector<int> top, in, out;

    vector<int> edgeToVertex;
    SegmentTree<int> seg;
    
    void makeTree(int cur, int par) {
        for (auto next : adj[cur]) if (next != par) {
            chd[cur].push_back(next);
            makeTree(next, cur);
        }
    }
    
    void hld(int cur) { // sz, par, dep 계산 & subSize기준으로 간선 순서 재배치
        sz[cur] = 1;
        for (auto &next : chd[cur]) {
            dep[next] = dep[cur] + 1;
            par[next] = cur;
            hld(next);
            sz[cur] += sz[next];
            if (sz[chd[cur][0]] < sz[next]) swap(chd[cur][0], next);
        }
    }

    void ett(int cur) { // ett & reorder에서 재배치된 순서 사용해서 top 계산
        in[cur] = ++dfsn;
        for (auto next : chd[cur]) {
            top[next] = (next == chd[cur][0] ? top[cur] : next);
            ett(next);
        }
        out[cur] = dfsn;
    }
    
public:
    Tree(int n) : adj(n + 1), chd(n + 1), dep(n + 1), par(n + 1), sz(n + 1), top(n + 1), in(n + 1), out(n + 1), edgeToVertex(n + 1), seg(n) {
        vector<tuple<int, int, int> > edges(n);
        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = {u, v, w};
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        makeTree(root, -1);
        hld(root);
        dfsn = 0;
        ett(root);

        for (int i = 1; i < n; i++) {
            auto [u, v, w] = edges[i];
            edgeToVertex[i] = par[u] == v ? u : v;
            updateEdge(i, w);
        }
    }

    void updateVertex(int vertexIdx, int val) {
        seg.updateChange(in[vertexIdx], val);
    }

    void updateEdge(int edgeIdx, int val) {
        seg.updateChange(in[edgeToVertex[edgeIdx]], val);
    }

    int query(int a, int b) {
        int res = 0;
        while (top[a] != top[b]) {
            if (dep[top[a]] > dep[top[b]]) swap(a, b);
            res = max(res, seg.query(in[top[b]], in[b]));
            b = par[top[b]];
        }
        if (dep[a] > dep[b]) swap(a, b);
        res = max(res, seg.query(in[a] + 1, in[b]));
        return res;
    }
};
```
### 시간복잡도
point update $O(logN)$   
query $O(log^2{N})$   

### 구현 주의사항
`hld()`함수에서 `if (sz[chd[cur][0]] < sz[next]) swap(chd[cur][0], next);`을 통해 `chd[cur][0]`에 heavy-edge가 오도록 재배치함.   
이를 위해선 next가 `chd[cur]`의 참조(&)여야 함   
```cpp
for (auto next : chd[cur]) {} // 틀린 코드
for (auto &next : chd[cur]) {} // 맞는 코드
```

### 사용설명


### 문제
[트리와 쿼리 1](https://www.acmicpc.net/problem/13510) - 간선 업데이트   

### 참고링크
https://justicehui.github.io/hard-algorithm/2020/01/24/hld/   
https://jh05013.github.io/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/HLD%20%ED%95%98%EB%82%98%EB%A1%9C%20%EA%B2%BD%EB%A1%9C%20%EC%BF%BC%EB%A6%AC%EC%99%80%20%EC%84%9C%EB%B8%8C%ED%8A%B8%EB%A6%AC%20%EC%BF%BC%EB%A6%AC%20%EB%AA%A8%EB%91%90%20%EC%A7%80%EC%9B%90%ED%95%98%EA%B8%B0/   