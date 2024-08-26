[카테고리](/README.md)
## Combination by DP
```cpp
template <typename T, T mod>
class Combination {
private:
    vector<vector<T> > dp;

public:
    Combination(int maxN, int maxK) : dp(maxN + 1, vector<T>(maxK + 1, -1)) {}
    Combination(int maxN) : Combination(maxN, maxN) {}

    T operator()(int n, int k) {
        if (k > n || k < 0) return 0;
        if (n == 1) return 1;
        if (k == 0 || k == n) return 1;
        
        T &res = dp[n][k];
        if (~res) return res;

        return res = ((*this)(n - 1, k - 1) + (*this)(n - 1, k)) % mod;
    }
};
```
### 시간복잡도 
$O(N K)$   

### 문제
[다리 놓기](https://www.acmicpc.net/problem/1010)   
[N포커](https://www.acmicpc.net/problem/16565)   

### 원리
파스칼의 삼각형   

$\binom{n}{r} = \binom{n-1}{r-1} + \binom{n-1}{r} $   