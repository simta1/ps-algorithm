[카테고리](/README.md)
## 예시문제 : [할 일 정하기 1](https://www.acmicpc.net/problem/1311)
### sol 1) for문 사용
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<vector<int> > v(n, vector<int>(n));
    for (auto &r : v) for (auto &e : r) cin >> e;

    const int INF = 1e9;
    vector<vector<int> > dp(n + 1, vector<int>(1 << n, INF));
    fill(dp[0].begin(), dp[0].end(), 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cost = v[i][j];
            for (int bit = 0; bit < (1 << n); bit++) if (dp[i][bit] != INF && (~bit & (1 << j))) {
                dp[i + 1][bit | (1 << j)] = min(dp[i + 1][bit | (1 << j)], dp[i][bit] + cost);
            }
        }
    }

    cout << dp[n].back();

    return 0;
}
```

### sol 2) 재귀함수 사용
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<vector<int> > v(n, vector<int>(n));
    for (auto &r : v) for (auto &e : r) cin >> e;

    vector<vector<int> > dp(n, vector<int>(1 << n, -1));

    function<int(int, int)> dfs = [&](int depth, int visited) -> int {
        if (depth == n) return 0;

        int &res = dp[depth][visited];
        if (~res) return res;

        res = 2e9;
        for (int i = 0; i < n; i++) if (~visited & (1 << i)) {
            res = min(res, dfs(depth + 1, visited | (1 << i)) + v[depth][i]);
        }
        return res;
    };

    cout << dfs(0, 0);
    return 0;
}
```
1번 방식은 확인하지 않아도 될 비트들까지 매번 확인하므로 더 느림   
for문으로도 효율적으로 비트필드를 순회하는 방식에 관한 글을 본 기억이 있는 것 같은데 못 찾겠다.

## 예시문제2 : [박성원](https://www.acmicpc.net/problem/1086)
### sol 1) for문 사용
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, k;
    cin >> n;

    vector<string> inputs(n);
    for (auto &st : inputs) cin >> st;
    cin >> k;

    auto getMod = [&k](string st) {
        int res = 0;
        for (auto &c : st) res = (res * 10 + (c - '0')) % k;
        return res;
    };

    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = getMod(inputs[i]);

    vector<int> pow10(51, 1);
    for (int i = 1; i < pow10.size(); i++) pow10[i] = pow10[i - 1] * 10 % k;

    vector<vector<ll> > dp(1 << n, vector<ll>(k));
    dp[0][0] = 1;

    for (int bit = 0; bit < (1 << n); bit++) {
        for (int i = 0; i < n; i++) if (!(bit & (1 << i))) {
            int nextBit = bit | (1 << i);

            for (int rem = 0; rem < k; rem++) { //remainder
                int nextRem = (rem * pow10[inputs[i].size()] + v[i]) % k;
                dp[nextBit][nextRem] += dp[bit][rem];
            }
        }
    }

    ll p = dp.back()[0], q = 1;
    for (int i = 1; i <= n; i++) q *= i;
    
    ll gcd = __gcd(p, q);
    cout << p / gcd << "/" << q / gcd;
    return 0;
}
```

### sol 2) 재귀함수 사용
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, k;
    cin >> n;

    vector<string> inputs(n);
    for (auto &st : inputs) cin >> st;
    cin >> k;

    auto getMod = [&k](string st) {
        int res = 0;
        for (auto &c : st) res = (res * 10 + (c - '0')) % k;
        return res;
    };
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = getMod(inputs[i]);

    vector<int> pow10(51, 1);
    for (int i = 1; i < pow10.size(); i++) pow10[i] = pow10[i - 1] * 10 % k;

    vector dp(1 << n, vector<ll>(k, -1));

    function<ll(int, int)> dfs = [&](int used, int remainder) -> ll {
        if (used == dp.size() - 1) return remainder == 0;

        ll &res = dp[used][remainder];
        if (~res) return res;

        res = 0;
        for (int i = 0; i < n; i++) if (~used & (1 << i)) {
            res += dfs(used | (1 << i), (remainder * pow10[inputs[i].size()] + v[i]) % k);
        }
        return res;
    };

    ll p = dfs(0, 0);
    ll q = 1;
    for (int i = 2; i <= n; i++) q *= i; // n!
    ll gcd = __gcd(p, q);

    cout << p / gcd << "/" << q / gcd;
    return 0;
}
```
이 문제에선 2번 방식이 더 느리다(1번 120ms, 2번 460ms)