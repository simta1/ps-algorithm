[카테고리](/README.md)
### SparseTable (합성함수)
```cpp
class SparseTable {
private:
    int n;
    vector<vector<int> > table;

    void init() {
        for (int i = 1; i < table.size(); i++) {
            for (int j = 1; j <= n; j++) {
                table[i][j] = table[i - 1][table[i - 1][j]];
            }
        }

    }

public:
    template <typename T>
    SparseTable(T maxK, int n) : n(n), table(floor(log2(maxK)) + 1, vector<int>(n + 1)) {
        for (int i = 1; i <= n; i++) cin >> table[0][i];
        init();
    }
    
    template <typename T>
    SparseTable(T maxK, const vector<int> &v) : n(v.size()), table(floor(log2(maxK)) + 1, vector<int>(v.size() + 1)) {
        for (int i = 0; i < n; i++) table[0][i + 1] = v[i];
        init();
    }

    template <typename T>
    int query(T k, int x) { // f^k[x]
        while (k) {
            x = table[int(log2(k & -k))][x];
            k &= (k - 1);
        }
        return x;
    }
};
```
### 시간복잡도 
preprocessing $O(N~log(maxK))$   
query $O(logK)$   

### 백준문제
[합성함수와 쿼리](https://www.acmicpc.net/problem/17435)

### 원리
$f^7(x) = f^4 \cdot f^2 \cdot f^1(x) $   
$f^9(x) = f^8 \cdot f^1(x) $