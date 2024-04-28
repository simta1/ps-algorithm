[카테고리](/README.md)
### GoldMineSeg (point update & range query)
```cpp
template <typename T>
class GoldMineSeg {
private:
    struct Node {
        T sum, l, r, lr;

        Node() : sum(0), l(0), r(0), lr(0) {}
        Node(T sum, T l, T r, T lr) : sum(sum), l(l), r(r), lr(lr) {}
    };

    int n;
    vector<Node> tree;
    const T INF;

    Node merge(const Node &a, const Node &b) {
        Node ret;
        ret.sum = a.sum + b.sum;
        ret.l = max(a.l, a.sum + b.l);
        ret.r = max(b.r, a.r + b.sum);
        ret.lr = max({a.r + b.l, a.lr, b.lr});
        return ret;
    }

    void update(int node, int s, int e, int i, T val, bool add) {
        if (i < s || e < i) return;
        if (s == e) {
            if (add) val += tree[node].sum;
            tree[node] = Node(val, val, val, val);
            return;
        }

        int m = s + e >> 1;
        update(node * 2, s, m, i, val, add);
        update(node * 2 + 1, m + 1, e, i, val, add);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int s, int e, int l, int r) {
        if (l <= s && e <= r) return tree[node];
        if (l > e || s > r) return Node(0, -INF, -INF, -INF);

        int m = s + e >> 1;
        Node lq = query(node * 2, s, m, l, r);
        Node rq = query(node * 2 + 1, m + 1, e, l, r);
        return merge(lq, rq);
    }

public:
    GoldMineSeg(int n) : n(n), tree(4 * n), INF(numeric_limits<T>::max() >> 1) {}
    GoldMineSeg(const vector<T> &v) : n(v.size()), tree(4 * v.size()), INF(numeric_limits<T>::max() >> 1) {
        for (int i = 0; i < v.size(); i++) updateChange(i + 1, v[i]);
    }

    void updateAdd(int i, T val) { // 1-based
        update(1, 0, n - 1, i - 1, val, 1);
    }

    void updateChange(int i, T val) { // 1-based
        update(1, 0, n - 1, i - 1, val, 0);
    }

    T query(int l, int r) { // 1-based
        return query(1, 0, n - 1, l - 1, r - 1).lr;
    }
};
```
### 시간복잡도
update $O(logN)$   
query $O(logN)$   

### 주의사항
.  

### 백준 문제
[연속합과 쿼리](https://www.acmicpc.net/problem/16993)
