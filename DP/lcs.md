[카테고리](/README.md)
## LCS
# 코드실험안끝났음
TODO
```cpp
int LCS(const string &a, const string &b) {
    vector dp(a.size() + 1, vector<int>(b.size() + 1));
    
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[~-i] == b[~-j]) dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }

    return dp.back().back();
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