[카테고리](/README.md)
## LCS
### 최장 공통 부분 수열(Longest Common Subsequence)
```cpp
int LCS(const string &a, const string &b) { // subsequence, 연속하게 안 골라도 됨
    int n = a.size(), m = b.size();
    vector dp(n + 1, vector<int>(m + 1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}
```
### 최장 공통 부분 문자열(Longest Common Substring)
```cpp
int LCS(const string &a, const string &b) { // substring, 연속하게 골라야 함
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

더 빠른 알고리즘도 있음.   
[최장 공통 부분 문자열](https://www.acmicpc.net/problem/9249)은 [접미사 배열과 LCP 배열](/문자열/Suffix%20and%20LCP%20Array.md)로 $O((N+M)\log(N+M))$,   
[최장 공통 부분 수열](https://www.acmicpc.net/problem/18439)은 [비트셋 LCS](/DP/비트셋%20LCS.md)로 $O(\dfrac{NM}{w})$에 계산이 가능함   

### 문제
[LCS](https://www.acmicpc.net/problem/9251) - 최장 공통 부분 수열   
[공통 부분 문자열](https://www.acmicpc.net/problem/5582) - 최장 공통 부분 문자열   
[LCS 2](https://www.acmicpc.net/problem/9252) - 최장 공통 부분 수열 + 최단거리 역추적   