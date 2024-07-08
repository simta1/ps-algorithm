[카테고리](/README.md)
### SegmentTree (point update & range query)
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
### 시간복잡도
update $O(logN)$   
query $O(logN)$

### 주의사항
range update가 필요한 경우 lazy propagation 사용

### 사용관련
i번째 값에 val만큼 더하려면 updateAdd(i, val);   
i번째 값을 val로 바꾸려면 updateChange(i, val);   

생성자에서 벡터 받아서 세그먼트 트리 만드는 경우 init쓰는 게 update n번 호출하는 것보다 빠르다.   
실제로 [최솟값 찾기](https://www.acmicpc.net/problem/11003)에서는 탑다운 세그로 푸는 경우엔 시간초과 피하려면 init을 써야 된다.   
```cpp
// 느림
for (int i = 0; i < v.size(); i++) updateChange(i + 1, v[i]);

// 빠른 코드
init(v, 1, 0, n - 1);
```


상황에 맞게 merge()함수 변경해서 사용   
```cpp
// ex) mod sum
T merge(const T &a, const T &b) {
    return (a + b) % mod;
}

// ex) max segment tree
T merge(const T &a, const T &b) {
    return max(a, b);
}
```

상황에 맞게 query()함수 변경해서 사용
```cpp
T query(int node, int s, int e, int l, int r) {
    ...
    if (l > e || s > r) return 0; // sum seg
    if (l > e || s > r) return 1; // mul seg
    if (l > e || s > r) return INF; // min seg
    ...
}
```

### 백준 문제
[구간 합 구하기](https://www.acmicpc.net/problem/2042)

### 참고문헌
https://book.acmicpc.net/ds/segment-tree