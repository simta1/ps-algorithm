[카테고리](/README.md)
### inversions (세그트리 사용해서 구현)
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

    void update(int i, T add) { // 1-based
        for (; i < tree.size(); i += (i & -i)) tree[i] += add;
    }

    T query(int l, int r) { // 1-based
        return sum(r) - sum(l - 1);
    }
};

template <typename T>
void coordinate_compression(vector<T> &orig) {
    vector<T> v(orig);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto &e : orig) e = lower_bound(v.begin(), v.end(), e) - v.begin();
}

long long countInversions(vector<int> v) {
    coordinate_compression(v); // 0-based

    long long res = 0;
    FenwickTree<int> fw(v.size());

    for (auto &e : v) {
        ++e; // 1-based
        res += fw.query(e + 1, v.size());
        fw.update(e, 1);
    }

    return res;
}
```
### Inversions (분할정복으로 구현)
```

```
### 시간복잡도
$O(N~logN)$   

### 용어정의
배열 $\{a_1, \cdots, a_n\}$에서 $i \lt j$, $a_i \gt a_j$를 만족하는 순서쌍 $(i, j)$의 개수

### 사용관련
분할정복 쓰면 좌표압축 안 쓰고 계산 가능

### 백준문제
[버블 소트](https://www.acmicpc.net/problem/1517)   
[D. Swap Dilemma](https://codeforces.com/contest/1983/problem/D)