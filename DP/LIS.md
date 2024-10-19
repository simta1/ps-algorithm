[카테고리](/README.md)
## 최장 증가 부분 수열(LIS, Longest Increasing Subsequence)
### LIS $O(N^2)$
```cpp
vector<int> dp(n, 1);
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) if (v[i] > v[j]) dp[i] = max(dp[i], dp[j] + 1);
}
cout << *max_element(dp.begin(), dp.end());
```
### 시간복잡도
<!-- TODO $O(NlogN)$    -->

### 문제
[]()