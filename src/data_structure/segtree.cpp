template<typename T, T (*op)(const T&, const T&), T (*e)()>
struct Seg {
    int n, sz;
    vector<T> tree;
    Seg(int n) : Seg(vector<T>(n, e())) {}
    Seg(const vector<T>& v) : n(v.size()) {
        for (sz = 1; sz < n; sz <<= 1);
        tree = vector<T>(sz << 1, e());
        for (int i = 0; i < n; i++) tree[sz | i] = v[i];
        for (int i = sz - 1; i >= 1; i--) tree[i] = op(tree[i << 1], tree[i << 1 | 1]); 
    }
    void update(int i, T val) { // 1-based
        assert(1 <= i && i <= n);
        --i |= sz;
        tree[i] = op(tree[i], val);
        while (i >>= 1) tree[i] = op(tree[i << 1], tree[i << 1 | 1]); 
    }
    T get(int i) const { // 1-based
        assert(1 <= i && i <= n);
        return tree[--i | sz];
    }
    T query(int l, int r) const { // 1-based // [l:r]
        assert(1 <= l && l <= r && r <= n);
        T resL = e(), resR = e();
        for (--l |= sz, --r |= sz; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) resL = op(resL, tree[l++]);
            if (~r & 1) resR = op(tree[r--], resR);
        }
        return op(resL, resR);
    }
    template <typename F>
    int findRightMost(int l, F f) const { // f([l:r])=true인 최대 r, 1-based // 만족하는 r 없다면 l-1리턴
        assert(1 <= l && l <= n);
        int node = (l - 1) | sz;
        T acc = e();
        node >>= __builtin_ctz(node);
        while (f(op(acc, tree[node]))) {
            acc = op(acc, tree[node++]);
            if (!(node & (node - 1))) return n;
            node >>= __builtin_ctz(node);
        }
        while (node < sz) {
            node <<= 1;
            if (f(op(acc, tree[node]))) acc = op(acc, tree[node++]);
        }
        return node ^ sz; // 1-based
    }
    template <typename F>
    int findLeftMost(int r, F f) const { // f([l:r])=true인 최소 l, 1-based // 만족하는 l 없다면 r+1리턴
        assert(1 <= r && r <= n);
        int node = (r - 1) | sz;
        T acc = e();
        node = max(1, node >> __builtin_ctz(~node));
        while (f(op(tree[node], acc))) {
            acc = op(tree[node--], acc);
            if (!((node + 1) & node)) return 1;
            node = max(1, node >> __builtin_ctz(~node));
        }
        while (node < sz) {
            node = node << 1 | 1;
            if (f(op(tree[node], acc))) acc = op(tree[node--], acc);
        }
        return node + 2 - sz; // 1-based
    }
    int findKthSmallest(int l, T k) const { // query([l, r]) >= k인 최소 r // 1-based
        assert(k >= 1);
        return query(l, n) < k ? -1 : findRightMost(l, [&](T sum) { return sum < k; }) + 1;
    }
    int findKthLargest(int r, T k) const { // query([l, r]) >= k인 최대 l // 1-based
        assert(k >= 1);
        return query(1, r) < k ? -1 : findLeftMost(r, [&](T sum) { return sum < k; }) - 1;
    }
};
// ex) 합 세그
int op(const int &a, const int &b) { return a + b; }
int e() { return 0; }
Seg<int, op, e> seg(v);