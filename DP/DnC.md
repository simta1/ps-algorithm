[카테고리](/README.md)
### Divide & Conquer Optimization
```cpp
vector dp(n, vector<T>(m));

auto monge = [&](int k, int j) { return _; };

// min
function<void(int, int, int, int, int)> dnc = [&dp, &monge, &dnc](int i, int s, int e, int l, int r) {
    if (l > r) return;

    int m = l + r >> 1;
    int bestK = -1;

    dp[i][m] = numeric_limits<T>::max();
    for (int k = max(s, lowerLimit(m)); k <= min(e, upperLimit(m)); k++) if (dp[i][m] > dp[i - 1][k] + monge(k, m)) {
        dp[i][m] = dp[i - 1][k] + monge(k, m);
        bestK = k;
    }

    dnc(i, s, bestK, l, m - 1);
    dnc(i, bestK, e, m + 1, r);
};

// max
function<void(int, int, int, int, int)> dnc = [&dp, &monge, &dnc](int i, int s, int e, int l, int r) {
    if (l > r) return;

    int m = l + r >> 1;
    int bestK = -1;

    dp[i][m] = -numeric_limits<T>::max();
    for (int k = max(s, lowerLimit(m)); k <= min(e, upperLimit(m)); k++) if (dp[i][m] < dp[i - 1][k] + monge(k, m)) {
        dp[i][m] = dp[i - 1][k] + monge(k, m);
        bestK = k;
    }

    dnc(i, s, bestK, l, m - 1);
    dnc(i, bestK, e, m + 1, r);
};

auto solve = [&]() { // 0-based
    for (int j = 0; j < dp[0].size(); j++) dp[0][j] = _;
    for (int i = 1; i < dp.size(); i++) dnc(i, i - 1, dp[i].size() - 2, i, dp[i].size() - 1);
};

auto solve = [&]() { // 1-based
    for (int j = 1; j < dp[0].size(); j++) dp[0][j] = _;
    for (int i = 2; i < dp.size(); i++) dnc(i, i - 1, dp[i].size() - 2, i, dp[i].size() - 1);
};
```
### 시간복잡도 
dp[n][m]까지 계산하는 시간:   
naive $O(NM^2)$   
dnc 최적화 $O(NM~logM)$   

### 주의사항
if (l > r) return; 꼭 필요하다.   
ex) l = 0, r = 1   
m = 0, dnc(l, m - 1)호출되면서 l > r 됨   

### 사용관련
람다함수 이름을 monge로 짓긴 했지만 꼭 monge array일 필요는 없음   
monge는 dnc최적화가 사용가능한 충분조건일 뿐 필요조건은 아님   
즉, monge가 아니어도 dnc 최적화 사용가능한 경우가 존재   

정확한 사용조건은,   
1. 점화식의 형태. $dp[i][j] = min_{low(j) \le k \le up(j)} \left[ dp[i - 1][k] + C(k, j) \right]$   
min이 아니라 max여도 가능   
2. 단조성. dp[i][j]에 대해 dp[i - 1][k] + C(k, j)가 최소가 되는 가장 작은 k를 bestK(i, j)라 할 때 bestK가 단조성을 가지는지.   
즉, 항상 bestK(i, j) <= bestK(i, j + 1)이거나 항상 bestK(i, j) >= bestK(i, j - 1)   

    C가 monge array일 경우 항상 조건2를 만족함   

---
$dp[i][j] = min_{lowerLimit(j) \le k \le upperLimit(j)} \left[ dp[i - 1][k] + monge(k, j) \right]$   
수식에 맞게 람다함수 작성

dnc(i, s, e, l, r)는 dp[i][l\~r] 계산   
l~r이 구하려는 범위, s~e는 현재 가능한 k의 범위   
세그먼트트리랑 변수의미 통일해서 이해하면 편하다.   

lowerLimit(m)과 upperLimit(m)은 문제에 따라 알맞게 사용   
lowerLimit가 없다면 s, upperLimit(m)이 없다면 e로 사용   

ex) dp[i][j] = $min_{k < j} \left[ dp[i - 1][k] + monge(k, j) \right]$   
lowerLimit(m) : s   
upperLimit(m) : m - 1   
   
ex) dp[i][j] = $max_{j-d \le k \le j} \left[ dp[i - 1][k] + monge(k, j) \right]$   
lowerLimit(m) : m - d   
upperLimit(m) : m   

### 백준문제
[탈옥](https://www.acmicpc.net/problem/13261) - min   
[김치](https://www.acmicpc.net/problem/11001) - max   

### 참고문헌
https://anz1217.tistory.com/144   
https://blog.myungwoo.kr/99   
https://ps.mjstudio.net/dnc-opt   
https://justicehui.github.io/hard-algorithm/2019/01/03/DnCOpt/   