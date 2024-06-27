[카테고리](/README.md)
### [Segment Tree](/ps-snippet/자료구조/세그먼트%20트리/SegmentTree.md)
<details>
<summary>세그먼트 트리 기본 코드</summary>

```cpp
template <typename T>
class SegmentTree {
private:
    int n;
    vector<T> tree;

    T merge(const T &a, const T &b) {
        return a + b;
    }

    void init(const vector<T> &v, int node, int s, int e) {
        if (s == e) {
            tree[node] = v[s];
            return;
        }

        int m = s + e >> 1;
        init(v, node * 2, s, m);
        init(v, node * 2 + 1, m + 1, e);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int s, int e, int i, T val, bool add) {
        if (i < s || e < i) return;
        if (s == e) {
            if (add) tree[node] = merge(tree[node], val);
            else tree[node] = val;
            return;
        }
        
        int m = s + e >> 1;
        update(node * 2, s, m, i, val, add);
        update(node * 2 + 1, m + 1, e, i, val, add);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    T query(int node, int s, int e, int l, int r) {
        if (l <= s && e <= r) return tree[node];
        if (l > e || s > r) return 0;

        int m = s + e >> 1;
        T lq = query(node * 2, s, m, l, r);
        T rq = query(node * 2 + 1, m + 1, e, l, r);
        return merge(lq, rq);
    }

public:
    SegmentTree(int n) : n(n), tree(4 * n) {}
    SegmentTree(const vector<T> &v) : n(v.size()), tree(4 * v.size()) {
        init(v, 1, 0, n - 1);
    }

    void updateAdd(int i, T val) { // 1-based
        update(1, 0, n - 1, i - 1, val, 1);
    }

    void updateChange(int i, T val) { // 1-based
        update(1, 0, n - 1, i - 1, val, 0);
    }

    T query(int l, int r) { // 1-based
        return query(1, 0, n - 1, l - 1, r - 1);
    }
};
```
</details>

### findKth
```cpp
private:
    int findKth(int node, int s, int e, T k) {
        if (s == e) return s;

        int m = s + e >> 1;
        if (k <= tree[node * 2]) return findKth(node * 2, s, m, k);
        return findKth(node * 2 + 1, m + 1, e, k - tree[node * 2]);
    }

public:
    int findKth(T k) {
        return k > tree[1] ? -1 : findKth(1, 0, n - 1, k);
    }
```
### 시간복잡도 
$O(logN)$   

### 백준문제
[중앙값 측정](https://www.acmicpc.net/problem/9426)

### 참고문헌
https://00ad-8e71-00ff-055d.tistory.com/162