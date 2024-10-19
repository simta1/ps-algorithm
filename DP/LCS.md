[카테고리](/README.md)
## LCS
### 최장 공통 부분 수열(Longest Common Subsequence)
```cpp
int LCS(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector dp(n + 1, vector<int>(m + 1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }

    return dp[n][m];
}
```
### 최장 공통 부분 문자열(Longest Common Substring)
```cpp
int LCS(const string &a, const string &b) {
    int res = 0;

    int n = a.size(), m = b.size();
    vector dp(n + 1, vector<int>(m + 1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            res = max(res, dp[i][j]);
        }
    }

    return res;
}
```
### 시간복잡도 
$O(NM)$   

### 주의사항


### 사용관련


### 백준문제
[]()

### 원리


### 참고문헌