[카테고리](/README.md)
## Combination by DP
```cpp
template <typename T, T mod>
class Combination {
private:
    vector<vector<T> > dp;

public:
    Combination(int maxN, int maxR) : dp(maxN + 1, vector<T>(maxR + 1, -1)) {}
    Combination(int maxN) : Combination(maxN, maxN) {}

    T operator()(int n, int r) {
        if (r > n || r < 0) return 0;
        if (n == 1) return 1;
        if (r == 0 || r == n) return 1;
        
        T &res = dp[n][r];
        if (~res) return res;

        return res = ((*this)(n - 1, r - 1) + (*this)(n - 1, r)) % mod;
    }

    T catalan(int n) {
        return ((*this)(n << 1, n) - (*this)(n << 1, n - 1) + mod) % mod;
    }

    T H(int n, int r) {
        return (*this)(n + r - 1, r);
    }

    T A(int n, int r) { // A(djacent) // Non-adjacent Combination       
        return (*this)(n - r + 1, r);
    }
};
```
### 시간복잡도 
$O(N R)$   

### 사용설명
catalan이나 H, A사용할 경우 combination기준에서 maxN 얼마인지 계산해서 사용

### 문제
[다리 놓기](https://www.acmicpc.net/problem/1010)   
[N포커](https://www.acmicpc.net/problem/16565)   

### 원리
파스칼의 삼각형   

$\binom{n}{r} = \binom{n-1}{r-1} + \binom{n-1}{r} $   