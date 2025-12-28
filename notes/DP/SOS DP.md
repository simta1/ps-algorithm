[카테고리](/README.md)
### SOS DP
```cpp
template <typename T>
vector<T> sosDP(int n, const vector<T> &v) {
    assert(v.size() == (1 << n));
    vector<T> dp(v);
    for (int axis = 1; axis < (1 << n); axis <<= 1) {
        for (int mask = axis; mask < (1 << n); mask = (mask + 1) | axis) dp[mask] += dp[mask ^ axis];
        // dp[mask] = max(dp[mask], dp[mask ^ axis]); // max로 누적하는 경우
    }
    return dp;
}
```
### 시간복잡도 
$O(N~2^N)$   

### 백준문제
[내가 어렸을 때 가지고 놀던 장난감](https://www.acmicpc.net/problem/2803) - sum   
[직사각형 만들기](https://www.acmicpc.net/problem/1801) - max   

### 원리
아래랑 같은 의미
```cpp
for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1 << n); mask++) {
        if (mask >> i & 1) dp[mask] += dp[mask ^ (1 << i)];
    }
}
```

### 참고링크
https://blog.queuedlab.com/posts/sos-dp   
https://qwerasdfzxcl.tistory.com/35   