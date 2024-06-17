[카테고리](/README.md)
## 예시문제 : [양팔저울](https://www.acmicpc.net/problem/2629)
### sol)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &e : v) cin >> e;

    const int offset = 15005;
    bitset<55005> dp;
    dp[offset] = 1;
    for (auto &e : v) {
        dp |= (dp << e);
        dp |= (dp >> e);
    }

    int t;
    for (cin >> t; t--;) {
        int x;
        cin >> x;
        cout << (dp[x + offset] ? "Y " : "N ");
    }

    return 0;
}
```
### 시간복잡도 
$O(2^n)$ (brute force) -> $O(NC)$ (knapsack DP) -> $O(\frac{NC}{32})$ (bitset)   
C는 최대 용량(무게)

### 주의사항
해당 무게가 가능한지 아닌지만 판별하면 되는 문제이므로 사용가능   
당연히 dp값이 0, 1 이외의 값을 가질 수 있는 문제에선 못씀

### 백준문제
[Bad Packing](https://www.acmicpc.net/problem/21135) - 비트셋 안써도 안정적으로 통과하지만 비트셋 쓰면 훨씬 빠름