[카테고리](/README.md)
### Knapsack
```cpp
// dp[i] : 정확히 i만큼의 무게로 만들 수 있는 최대 가치, 정확히 i의 무게가 불가능하다면 0
template <typename T>
T knapsack(const vector<pair<int, T> > &bag, int maxWeight) {
    vector<T> dp(maxWeight + 1);

    for (auto &[w, v] : bag) if (w <= maxWeight) {
        for (int i = maxWeight; i > w; i--) if (dp[i - w]) {
            dp[i] = max(dp[i], dp[i - w] + v);
        }
        dp[w] = max(dp[w], v);
    }

    return *max_element(dp.begin(), dp.end());
}

// 약간 더 빠른 구현
// dp[i] : i이하의 무게로 만들 수 있는 최대 가치
template <typename T>
T knapsack(const vector<pair<int, T> > &bag, int maxWeight) {
    vector<T> dp(maxWeight + 1);

    for (auto &[w, v] : bag) if (w <= maxWeight) {
        for (int i = maxWeight; i >= w; i--) dp[i] = max(dp[i], dp[i - w] + v);
    }

    return dp.back();
}
```

### 시간복잡도 
$O(NW)$   

### 주의사항
for문 방향 `i--`로 해야 됨   
`if (w <= maxWeight)` 생략하면 `dp[w] = max(dp[w], v)`에서 outOfBounds에러날 수 있으니 꼭 필요함

### 백준문제
[평범한 배낭](https://www.acmicpc.net/problem/12865)   