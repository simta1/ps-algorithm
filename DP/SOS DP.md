[카테고리](/README.md)
# 아직 테스트 안 해본 코드임
### SOS DP (2D 구현)
```cpp
vector dp(1 << n, vector<T>(n + 1));
dp[mask][0] = v[0]; ?

for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) { 
        dp[mask][i + 1] = dp[mask][i];
        if(mask & 1 << i) dp[mask][i + 1] += dp[mask ^ (1 << i)][i];
    } 
}
```
### SOS DP (1D 구현)
```cpp
vector<T> dp(1 << n);
for (int i = 0; i < (1 << n); i++) dp[i] = v[i];

for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << n); mask++) if (mask & (1 << i)) {
        dp[mask] += dp[mask ^ (1 << i)];
    }
}
```
### 시간복잡도 
$O(N~2^N)$   

### 주의사항


### 사용관련


### 백준문제
[]()

### 원리


### 참고문헌
https://00ad-8e71-00ff-055d.tistory.com/84   
https://codeforces.com/blog/entry/45223   
https://blog.queuedlab.com/posts/sos-dp   
https://qwerasdfzxcl.tistory.com/35   
https://gina65.tistory.com/6   