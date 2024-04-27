<span class="gold">[카테고리](/README.md)</span>
### FenwickTree2D (point update & range query)
```cpp
template <typename T>
class FenwickTree2D {
private:
    vector<vector<T> > tree;

    T sum(int r, int c) {
        T res = 0;
        for (int i = r; i > 0; i -= (i & -i)) {
            for (int j = c; j > 0; j -= (j & -j)) res += tree[i][j];
        }
        return res;
    }

public:
    FenwickTree2D(int n, int m) : tree(n + 1, vector<T>(m + 1)) {}
    FenwickTree2D(const vector<vector<T> > &v) : tree(v.size() + 1, vector<T>(v[0].size() + 1)) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                update(i + 1, j + 1, v[i][j]);
            }
        }
    }

    void update(int r, int c, T add) { // 1-based
        for (int i = r; i < tree.size(); i += (i & -i)) {
            for (int j = c; j < tree[0].size(); j += (j & -j)) tree[i][j] += add;
        }
    }

    T query(int x1, int y1, int x2, int y2) { // 1-based
        return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
    }
};
```


### FenwickTree2D (range update & point query)
```cpp
template <typename T>
class FenwickTree2D {
private:
    vector<vector<T> > tree;

    void updatePoint(int r, int c, T add) {
        for (int i = r; i < tree.size(); i += (i & -i)) {
            for (int j = c; j < tree[0].size(); j += (j & -j)) tree[i][j] += add;
        }
    }

public:
    FenwickTree2D(int n, int m) : tree(n + 2, vector<T>(m + 2)) {}
    FenwickTree2D(const vector<vector<T> > &v) : tree(v.size() + 2, vector<T>(v[0].size() + 2)) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                updateRange(i + 1, j + 1, i + 1, j + 1, v[i][j]);
            }
        }
    }

    void updateRange(int x1, int y1, int x2, int y2, T add) { // 1-based
        updatePoint(x1, y1, add);
        updatePoint(x1, y2 + 1, -add);
        updatePoint(x2 + 1, y1, -add);
        updatePoint(x2 + 1, y2 + 1, add);
    }

    T query(int r, int c) { // 1-based
        T res = 0;
        for (int i = r; i > 0; i -= (i & -i)) {
            for (int j = c; j > 0; j -= (j & -j)) res += tree[i][j];
        }
        return res;
    }
};
```
### 시간복잡도
update O(log(N) * log(M))    
query O(log(N) * log(M))   
N, M은 각각 행과 열의 개수   

### 주의사항
range update & point query 의 경우 imos법 사용하면서 (x2 + 1, y2 + 1)까지 접근하므로 배열은 [n + 1][m + 1]번째 항까지 필요

### 백준 문제
[구간 합 구하기 3](https://www.acmicpc.net/problem/11658)
