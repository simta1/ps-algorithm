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

### 원리
원리는 imos법을 생각하면 된다. imos법을 사용하면 range update도 lazy propagation없이 O(logN)구현이 가능하다.   
imos법을 사용하므로 일반적인 상황에선(sum, max 등등을 다루는 세그먼트 트리) range query가 불가능 하지만 gcd를 구하는 상황이기에 range query도 가능하다.   
예를 들어 v = [a, b, c, d, e, f, g, h]에서 c~g의 최대공약수를 구하는 과정은 다음과 같다.   
세그먼트 트리에는 [a, b - a, c - b, d - c, e - d, f - e, g - f, h - g]가 저장된다.   
유클리드 호제법에 의해 gcd(c, d, e, f, g) = gcd(c, d - c, e - d, f - e, g - f) = gcd(c, gcd(d - c, e - d, f - e, g - f))  이다.   
세그먼트 트리의 각 노드에서 sum과 gcd의 두가지 값을 저장하도록 하면    
c의 값은 sum(a, b - a, c - b)와 같으므로 query(0, 2).sum으로 얻을 수 있고,   
gcd(d - c, e - d, f - e, g - f)의 값은 query(3, 6).gcd로 얻을 수 있다.   

### 백준 문제
[Range GCD](https://www.acmicpc.net/problem/12858)
