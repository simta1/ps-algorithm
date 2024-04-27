### GCD SegmentTree (range update & range query)
```cpp
template <typename T>
class SegmentTree {
private:
    struct Node {
        T sum, gcd;

        Node() {}
        Node(T sum) : sum(sum), gcd(abs(sum)) {}

        void update(T add) {
            sum += add;
            gcd = abs(sum);
        }
    };

    Node merge(const Node &a, const Node &b) {
        Node res;
        res.sum = a.sum + b.sum;
        res.gcd = __gcd(a.gcd, b.gcd);
        return res;
    }

    int n;
    vector<Node> tree;

    void init(const vector<T> &v, int node, int s, int e) {
        if (s == e) {
            tree[node] = Node(v[s]);
            return;
        }

        int m = s + e >> 1;
        init(v, node * 2, s, m);
        init(v, node * 2 + 1, m + 1, e);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void updatePoint(int node, int s, int e, int i, T add) {
        if (i < s || e < i) return;
        if (s == e) {
            tree[node].update(add);
            return;
        }
        
        int m = s + e >> 1;
        updatePoint(node * 2, s, m, i, add);
        updatePoint(node * 2 + 1, m + 1, e, i, add);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int s, int e, int l, int r) {
        if (l <= s && e <= r) return tree[node];
        if (l > e || s > r) return Node(0);

        int m = s + e >> 1;
        Node lq = query(node * 2, s, m, l, r);
        Node rq = query(node * 2 + 1, m + 1, e, l, r);
        return merge(lq, rq);
    }

public:
    SegmentTree(int n) : n(n), tree(4 * n) {}
    SegmentTree(vector<T> v) : n(v.size()), tree(4 * v.size()) {
        for (int i = n - 1; i; i--) v[i] -= v[i - 1];
        init(v, 1, 0, n - 1);
    }

    void updateRange(int l, int r, T add) { // 1-based
        updatePoint(1, 0, n - 1, l - 1, add);
        if (r != n) updatePoint(1, 0, n - 1, r, -add);
    }

    T query(int l, int r) { // 1-based
        return __gcd(query(1, 0, n - 1, 0, l - 1).sum, l == r ? 0 : query(1, 0, n - 1, l, r - 1).gcd);
    }
};
```
### 시간복잡도
update O(logN)   
query O(logN)   
lazy propagation 없이도 O(logN)으로 range update, range query 모두 가능하다.

### 백준 문제
[Range GCD](https://www.acmicpc.net/problem/12858)   

### 원리
유클리드 호제법을 사용하기 위해 세그먼트 트리에 배열의 값 대신 이웃한 값의 차이를 저장한다.   
imos법 느낌으로 range update도 lazy없이 구현 가능하다.   
gcd(a, b, c, d, ..., e, f) = gcd(a, b - a, c - b, d - c, ..., f - e) = gcd(a, gcd(b - a, c - b, d - c, ..., f - e))이고 a는 이웃한 값의 차이들의 합과 같으므로 point sum query로 구할 수 있다.