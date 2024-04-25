### FenwickTree (point update & range query)
```cpp
template <typename T>
class FenwickTree {
private:
    vector<T> tree;

    T sum(int i) {
        T res = 0;
        for (; i > 0; i -= (i & -i)) res += tree[i];
        return res;
    }

public:
    FenwickTree(int n) : tree(n + 1) {}
    FenwickTree(const vector<T> &v) : tree(v.size() + 1) {
        for (int i = 0; i < v.size(); i++) update(i + 1, v[i]);
    }

    void update(int i, T add) {
        for (; i < tree.size(); i += (i & -i)) tree[i] += add;
    }

    T query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
```


### FenwickTree (range update & point query)
```cpp
template <typename T>
class FenwickTree {
private:
    vector<T> tree;

    void updatePoint(int i, T add) {
        for (; i < tree.size(); i += (i & -i)) tree[i] += add;
    }

public:
    FenwickTree(int n) : tree(n + 2) {}
    FenwickTree(const vector<T> &v) : tree(v.size() + 2) {
        for (int i = 0; i < v.size(); i++) updateRange(i + 1, i + 1, v[i]);
    }

    void updateRange(int l, int r, T add) {
        updatePoint(l, add);
        updatePoint(r + 1, -add);
    }

    T query(int i) {
        T res = 0;
        for (; i > 0; i -= (i & -i)) res += tree[i];
        return res;
    }
};
```
### 시간복잡도
update O(logN)   
query O(logN)

### 주의사항
range update & point query 의 경우 updateRange(l, r)에서 updatePoint(r + 1)을 호출되므로 배열은 (n + 1)번째 항까지 필요

### 사용설명
update(), query() 매개변수로 보내는 인덱스 범위는 [1, n]

### 백준 문제
[구간 합 구하기](https://www.acmicpc.net/problem/2042) - point update & range query   
[수열과 쿼리 21](https://www.acmicpc.net/problem/16975) - range update & point query
