[카테고리](/README.md)
## 최장 증가 부분 수열(LIS, Longest Increasing Subsequence)
### LIS의 길이 계산
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

### LIS 계산
```cpp
template <typename T>
vector<int> LIS(const vector<T> &v) { // v에 대한 인덱스로 LIS 나타내서 리턴
    int n = v.size();
    vector<int> pos(n);
    vector<T> dp; // dp[i] : 길이 i이상의 LIS를 만들 때 LIS의 i번째 원소로 가능한 최소값

    for (int i = 0; i < n; i++) {
        if (dp.empty() || dp.back() < v[i]) {
            pos[i] = dp.size();
            dp.push_back(v[i]);
        }
        else {
            pos[i] = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
            dp[pos[i]] = v[i];
        }
    }
    
    
    vector<int> LIS(dp.size());
    for (int i = n - 1, cur = dp.size() - 1; i >= 0; i--) if (pos[i] == cur) LIS[cur--] = i;
    return LIS;
}
```

### 시간복잡도
$O(N \log{N})$   

### 문제
[가장 긴 증가하는 부분 수열 3](https://www.acmicpc.net/problem/12738)   