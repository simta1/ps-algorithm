[카테고리](/README.md)
## 최장 증가 부분 수열(LIS, Longest Increasing Subsequence)
```cpp
template <typename T>
int LIS(const vector<T> &v) {
    vector<T> dp; // dp[i] : 길이 i이상의 LIS를 만들 때 LIS의 i번째 원소로 가능한 최소값
    for (auto e : v) {
        if (dp.empty() || dp.back() < e) dp.push_back(e);
        else *lower_bound(dp.begin(), dp.end(), e) = e;
    }
    return dp.size();
}
```
### 시간복잡도
$O(N \log{N})$   

### 문제
[가장 긴 증가하는 부분 수열 3](https://www.acmicpc.net/problem/12738)   