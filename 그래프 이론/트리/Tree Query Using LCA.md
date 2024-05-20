[카테고리](/README.md)
### Tree Query Using LCA
```cpp
template <typename T>
class Tree {
private:
    struct Data {
        T mn, mx;

        Data() : mn(numeric_limits<T>::max()), mx(-numeric_limits<T>::max()) {}
        Data(T val) : mn(val), mx(val) {}
    };

    Data merge(const Data &a, const Data &b) {
        Data res;
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        return res;
    }

    int maxDepth;
    vector<int> depth;
    vector<vector<pair<int, T> > > adj;
    vector<vector<pair<int, Data> > > ac;

    void makeTree(int cur, int parent) { // 1-based
        depth[cur] = depth[parent] + 1;

        for (int i = 1; i <= maxDepth; i++) {
            int ancestor = ac[cur][i - 1].first;
            ac[cur][i].first = ac[ancestor][i - 1].first;
            ac[cur][i].second = merge(ac[cur][i - 1].second, ac[ancestor][i - 1].second);
            if (ancestor == 0) break;
        }

        for (auto [next, cost] : adj[cur]) if (next != parent) {
            ac[next][0] = {cur, Data(cost)};
            makeTree(next, cur);
        }   
    }

public:
    Tree(int n) : depth(n + 1), adj(n + 1), maxDepth(floor(log2(n))), ac(n + 1, vector<pair<int, Data> >(maxDepth + 1)) {
        for (int i = 1; i < n; i++) {
            int a, b;
            T c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        ac[1][0] = {0, Data()};
        makeTree(1, 0);
    }

    pair<T, T> query(int a, int b) { // 1-based
        Data res;

        if (depth[a] > depth[b]) swap(a, b);
        int diff = depth[b] - depth[a];
        while (diff) {
            res = merge(res, ac[b][log2(diff & -diff)].second);
            b = ac[b][log2(diff & -diff)].first;
            diff &= (diff - 1);
        }

        if (a == b) {
            return {res.mn, res.mx};
        }

        for (int i = maxDepth; i >= 0; i--) {
            if (ac[a][i].first != ac[b][i].first) {
                res = merge(res, ac[a][i].second);
                res = merge(res, ac[b][i].second);
                a = ac[a][i].first;
                b = ac[b][i].first;
            }
        }

        res = merge(res, ac[a][0].second);
        res = merge(res, ac[b][0].second);
        return {res.mn, res.mx};
    }
};
```
### 시간복잡도 
preprocessing $O(N~logN)$   
query $O(logN)$

### 주의사항
노드를 위로 올리기 전에 먼제 res를 업데이트해야 된다.   
```cpp
// 맞는 코드
res = merge(res, ac[a][i].second);
a = ac[a][i].first;

// 틀린 코드
// a = ac[a][i].first;
// res = merge(res, ac[a][i].second);
```

### 백준문제
[도로 네트워크](https://www.acmicpc.net/problem/3176)