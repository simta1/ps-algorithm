[카테고리](/README.md)
### inversions (세그트리로 구현)
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

template <typename T>
long long countInversions(vector<T> v) {
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
```cpp
template <typename T>
long long countInversions(vector<T> v) {
    function<long long(int, int)> dnc = [&](int s, int e) -> long long {
        if (s == e) return 0;
        
        int m = s + e >> 1;
        long long res = dnc(s, m) + dnc(m + 1, e);

        int l = s, r = m + 1;
        while (l <= m && r <= e) {
            if (v[l] <= v[r]) ++l;
            else {
                res += m - l + 1;
                ++r;
            }
        }
    
        inplace_merge(v.begin() + s, v.begin() + m + 1, v.begin() + e + 1);
        return res;
    };

    return dnc(0, v.size() - 1);
}
```
### 시간복잡도
$O(N~logN)$   

### 용어정의
배열 $\{a_1, \cdots, a_n\}$에서 $i \lt j$, $a_i \gt a_j$를 만족하는 순서쌍 $(i, j)$의 개수   
<-> 배열을 정렬하는데 필요한 호환의 최소횟수   

배열이 distinct라면 호환이 행해질 때마다 반전수의 기우성이 바뀌지만 중복값이 존재한다면 기우성을 일정하게 유지시킬 수 있다.   

### 주의사항
값 변경 있으므로 참조 사용하지 않도록 주의

### 사용관련
분할정복 쓰면 좌표압축 안 쓰고 계산 가능

### 백준문제
[버블 소트](https://www.acmicpc.net/problem/1517)   
[D. Swap Dilemma](https://codeforces.com/contest/1983/problem/D)