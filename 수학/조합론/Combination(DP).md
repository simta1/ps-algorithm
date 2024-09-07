[카테고리](/README.md)
## Combination by DP
### Combination
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
### Catalan
```cpp
template <typename T, T mod>
class Catalan {
private:
    vector<T> dp;

public:
    Catalan(int maxN) : dp(maxN + 1, -1) {}

    T operator()(int n) {
        if (n == 0) return 1;
        
        T &res = dp[n];
        if (~res) return res;

        res = 0;
        for (int i = 0; i < n; i++) res = (res + (*this)(i) * (*this)(n - 1 - i)) % mod;
        return res;
    }
};
```
### 시간복잡도 
$O(N R)$   

### 공간복잡도
Combination $O(N R)$   
Catalan $O(N)$

### 사용설명
catalan이나 H, A사용할 경우 combination기준에서 maxN 얼마인지 계산해서 사용
카탈란수만 필요하면 Catalan사용.

```cpp
template <typename T>
class Combination {
private:
    vector<vector<T> > dp;
    T INF;

public:
    Combination(int maxN, int maxR) : dp(maxN + 1, vector<T>(maxR + 1, -1)) {}
    Combination(int maxN) : Combination(maxN, maxN) {}

    T operator()(int n, int r) {
        if (r > n || r < 0) return 0;
        if (n == 1) return 1;
        if (r == 0 || r == n) return 1;
        
        T &res = dp[n][r];
        if (~res) return res;

        return res = min(INF, (*this)(n - 1, r - 1) + (*this)(n - 1, r));
    }
};
```
modInt 대신 infInt사용한 코드   
INF <= numeric_limits\<T\>::max() / 2 가정한 거라서 INF 더 큰 경우에는 덧셈 로직 바꿔서 사용

### 문제
[다리 놓기](https://www.acmicpc.net/problem/1010)   
[N포커](https://www.acmicpc.net/problem/16565)   
[정상 회담 2](https://www.acmicpc.net/problem/1670) - catalan   

### 원리
파스칼의 삼각형   

$\binom{n}{r} = \binom{n-1}{r-1} + \binom{n-1}{r} $   