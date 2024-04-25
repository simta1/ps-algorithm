### SegmentTree with Lazy Propagation (range update & range query)
```cpp
template <typename T>
class SegmentTree {
private:
    int n;
    vector<T> tree, lazy;
    
    void init(const vector<T> &v, int node, int s, int e) {
        if (s == e) {
            tree[node] = v[s];
            return;
        }

        int m = s + e >> 1;
        init(v, node * 2, s, m);
        init(v, node * 2 + 1, m + 1, e);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void updateLazy(int node, int s, int e) {
        if (!lazy[node]) return;

        tree[node] += (e - s + 1) * lazy[node];
        if (s != e) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void updateRange(int node, int s, int e, int l, int r, T add) {
        updateLazy(node, s, e);

        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            tree[node] += (e - s + 1) * add;
            if (s != e) {
                lazy[node * 2] += add;
                lazy[node * 2 + 1] += add;
            }
            return;
        }
        
        int m = s + e >> 1;
        updateRange(node * 2, s, m, l, r, add);
        updateRange(node * 2 + 1, m + 1, e, l, r, add);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    T query(int node, int s, int e, int l, int r) {
        updateLazy(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];

        int m = s + e >> 1;
        T lq = query(node * 2, s, m, l, r);
        T rq = query(node * 2 + 1, m + 1, e, l, r);
        return lq + rq;
    }

public:
    SegmentTree(int n) : n(n), tree(4 * n), lazy(4 * n) {}
    SegmentTree(const vector<T> &v) : n(v.size()), tree(4 * v.size()), lazy(4 * v.size()) {
        init(v, 1, 0, n - 1);
    }

    void update(int l, int r, T add) {
        updateRange(1, 0, n - 1, l - 1, r - 1, add);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l - 1, r - 1);
    }
};
```
### 시간복잡도
update O(logN)   
query O(logN)

### 주의사항
.

### 사용설명
update(), query() 매개변수로 보내는 인덱스 범위는 [1, n]

### 백준 문제
[구간 합 구하기 2](https://www.acmicpc.net/problem/10999)
