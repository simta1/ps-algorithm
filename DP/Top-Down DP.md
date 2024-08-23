[카테고리](/README.md)
### dp 람다재귀 구현
```cpp
vector dp(dim1, vector<int>(dim2, -1));

function<int(int, int)> f = [&](int cur, int state) -> int {
    // cout << cur << " " << state << "\n"; // for debug

    // base condition

    int &res = dp[cur][state];
    if (~res) return res;

    res = 0; // visit check
    res = (res + f(next, nextState)) % mod;
    return res;
};
```
### map 사용
```cpp
map<pair<int, int>, int> dp;
function<int(int, int)> f = [&](int n, int k) -> int {
    // base condition

    if (dp.count({n, k})) return dp[{n, k}];

    ll &res = dp[{n, k}];
    res = 0;
    res = (res + f(next, nextState)) % mod;
    return res;
};
```
### 결과 안나올 때 확인사항
__1. 처음 dp초기화 제대로 했는지__   
-1로 초기화   
혹시나 dp값으로 음수 가능한 경우에는 불가능한 다른 값으로 초기화하고, if (~res) 부분도 변경   
__2. 방문 체크했는지__   
cur이 계속 증가하거나 감소해서 다시 현재 노드를 방문할 일 없이 단방향으로 전파된다면 필요없지만, 혹시나 다시 dfs(cur)이 호출될 가능성이 있다면 무조건 res = (-1이 아닌값)으로 방문체크를 해두어야 무한루프가 방지됨   
```cpp
// 틀린 코드, 무한루프 가능성 있음
res = dfs(cur + 1);
res += dfs(cur - 1);

// 좋은 코드
res = 0;
res += dfs(cur + 1);
res += dfs(cur - 1);
```
__3. 방문체크값 알맞게 정했는지__   
상황에 따라서 res = -INF;나 res = INF;로 알맞게 방문체크   
max구해야 될 때 0쓰면 틀리고 -INF로 둬야 제대로 계산되는 경우 있다. 일단 0 대신 -INF 쓰고 보는 게 낫다.   

__4. return 했는지__   
혹시 결과 출력 안 되면 return res; 까먹었는지 확인   

## top-down -> bottom-up 변환 예시
### [팰린드롬 만들기](https://www.acmicpc.net/problem/1695)
### top-down
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (auto &e : v) cin >> e;
    
    vector dp(n, vector<int>(n, -1));

    function<int(int, int)> f = [&](int idx1, int idx2) -> int {
        if (idx1 >= idx2) return 0;

        int &res = dp[idx1][idx2];
        if (~res) return res;

        res = 2e9; // visit check
        if (v[idx1] == v[idx2]) res = min(res, f(idx1 + 1, idx2 - 1));
        res = min(res, f(idx1 + 1, idx2) + 1);
        res = min(res, f(idx1, idx2 - 1) + 1);

        return res;
    };

    cout << f(0, n - 1);
    return 0;
}
```

### bottom-up
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (auto &e : v) cin >> e;
    
    vector dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int s = 0, e = len - 1; e < n; s++, e++) {
            dp[s][e] = min(dp[s + 1][e], dp[s][e - 1]) + 1;
            if (v[s] == v[e]) dp[s][e] = min(dp[s][e], dp[s + 1][e - 1]);
        }
    }

    cout << dp[0][n - 1];
    return 0;
}
```