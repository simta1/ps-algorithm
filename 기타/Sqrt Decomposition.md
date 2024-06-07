[카테고리](/README.md)
### Sqrt Decomposition
```cpp
template <typename T, typename F>
class SqrtDecomposition {
private:
    int sq;
    vector<T> v;
    vector<F> bucket;

public:
    SqrtDecomposition(const vector<T> &v) : v(v) {
        sq = sqrt(v.size());
        bucket.resize(n / sq + 1);

        for (int i = 0; i < n; i++) // v[i] -> bucket[i / sq]
    }

    void update(int i, T val) { // 0-based
        //v[i]
        //bucket[i]
    }

    T query(int l, int r) { // 0-based
    	T res = 0;

        if (l / sq == r / sq) {
            for (int i = l; i <= r; i++) //v[i]
        }
        else {
            for (int i = l; i < (l / sq + 1) * sq; i++) //v[i]
            for (int i = l / sq + 1; i < r / sq; i++) //bucket[i]
            for (int i = r / sq * sq; i <= r; i++) //v[i]
        }

        return res;
    }
};
```
### 시간복잡도 
update $O(1)$   
query $O(\sqrt N)$   
update가 세그먼트 트리보다 빠르므로 mo's algorithm에서 T(N)을 줄여야 하는 경우 쓰기 좋다.

### 백준문제
[수열과 쿼리 18](https://www.acmicpc.net/problem/14504)