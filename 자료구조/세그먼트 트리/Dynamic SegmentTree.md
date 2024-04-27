[카테고리](/README.md)
### DynamicSeg (point update & range query)
```cpp
template <typename U, typename T>
class DynamicSeg {
private:
    struct Node {
        T val;
        Node *l, *r;

        Node(T val) : val(val), l(nullptr), r(nullptr) {}
        Node() : Node(0) {}
        ~Node() {
            if (l) delete l;
            if (r) delete r;
        }
    } *root;

    T merge(const T &a, const T &b) {
        return a + b;
    }

    const U MAX_IDX;

    void update(Node *node, U s, U e, U i, T val, bool add){
        if(s == e) {
            node->val = val + add * node->val;
            return;
        }

        U m = s + e >> 1;
        if (i <= m){
            if(!node->l) node->l = new Node();
            update(node->l, s, m, i, val, add);
        }
        else {
            if(!node->r) node->r = new Node();
            update(node->r, m + 1, e, i, val, add);
        }

        T lval = node->l ? node->l->val : 0;
        T rval = node->r ? node->r->val : 0;
        node->val = merge(lval, rval);
    }

    T query(Node *node, U s, U e, U l, U r){
        if(!node) return 0;
        if(l <= s && e <= r) return node->val;
        if(l > e || s > r) return 0;

        U m = s + e >> 1;
        T lq = query(node->l, s, m, l, r);
        T rq = query(node->r, m + 1, e, l, r);
        return merge(lq, rq);
    }

    U kth(Node *node, U s, U e, T k) {
        if (s == e) return e;
        U m = s + e >> 1;
        T lsz = node->l ? node->l->val : 0;
        if (k <= lsz) return kth(node->l, s, m, k);
        return kth(node->r, m + 1, e, k - lsz);
    }

public:
    DynamicSeg(U maxIdx) : root(new Node()), MAX_IDX(maxIdx) {}
    ~DynamicSeg() {
        if (root) delete root;
    }
    
    void updateAdd(U i, T val) { // 0-based
        update(root, 0, MAX_IDX, i, val, 1);
    }

    void updateChange(U i, T val) { // 0-based
        update(root, 0, MAX_IDX, i, val, 0);
    }

    T query(U l, U r) { // 0-based
        return query(root, 0, MAX_IDX, l, r);
    }

    U kth(int k) {
        return kth(root, 0, MAX_IDX, k);
    }
};
```


### DynamicSeg with Lazy Propagation (range update & range query)
```cpp
//작성중
```
### 시간복잡도
update O(logN)   
query O(logN)

### 공간복잡도
O(QlogN), Q는 쿼리 개수   
기본 세그먼트 트리의 공간복잡도는 O(N)

### 백준 문제 
[일기예보](https://www.acmicpc.net/problem/14577)