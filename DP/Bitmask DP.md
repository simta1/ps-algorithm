[카테고리](/README.md)
[카테고리](/README.md)
## Bitmask DP
```cpp
vector<ld> dp(1 << n, DEFAULT_VALUE);
dp[0] = INIT_VALUE;

for (int bit = 1; bit < (1 << n); bit++) {
    int cnt = __builtin_popcount(bit);
    for (int tmp = bit; tmp; tmp &= tmp - 1) {
        int i = __builtin_ctz(tmp);
        dp[bit] = best(dp[bit], func(dp[bit ^ (1 << i)], i, cnt));
    }
}

cout << dp.back();
```

best()는 min()이나 max(), add() 등의 함수   

### Bitmask DP 최단거리 역추적
```cpp
function<void(int)> trace = [&](int bit) {
    cout << bit << " ";
    if (!bit) return;
    
    int cnt = __builtin_popcount(bit);
    for (int tmp = bit; tmp; tmp &= tmp - 1) {
        int i = __builtin_ctz(tmp);
        if (check(dp[bit ^ (1 << i)], i, cnt)) {
            trace(bit ^ (1 << i));
            return;
        }
    }

    assert(false);
};
```

### 시간복잡도
$O(N ~ 2^{N-1})$   
gcc builtin `__builtin_popcount`와 `__builtin_ctz`는 $O(1)$임   
popcount가 k개인 nCk개의 비트들에 대해 각각 k번씩의 dp 전이가 필요하므로 총 횟수는 $\displaystyle\sum_{k=1}^{n}k\binom{n}{k} = n 2^{n-1} $임   

### 문제
### [007](https://www.acmicpc.net/problem/3056)   
```cpp
vector<ld> dp(1 << n, 0);
dp[0] = 1;

for (int bit = 1; bit < (1 << n); bit++) {
    int cnt = __builtin_popcount(bit);
    for (int tmp = bit; tmp; tmp &= tmp - 1) {
        int i = __builtin_ctz(tmp);
        dp[bit] = max(dp[bit], dp[bit ^ (1 << i)] * v[i][cnt - 1] * 0.01);
    }
}

cout << fixed << setprecision(6) << dp.back() * 100;
```

### [할 일 정하기 1](https://www.acmicpc.net/problem/1311)
```cpp
const int INF = 1e9;
vector<int> dp(1 << n, INF);
dp[0] = 0;

for (int bit = 1; bit < (1 << n); bit++) {
    int cnt = __builtin_popcount(bit);
    for (int tmp = bit; tmp; tmp &= tmp - 1) {
        int i = __builtin_ctz(tmp);
        dp[bit] = min(dp[bit], dp[bit ^ (1 << i)] + v[i][cnt - 1]);
    }
}

cout << dp.back();
```
### [박성원](https://www.acmicpc.net/problem/1086)
```cpp
vector<vector<ll> > dp(1 << n, vector<ll>(k));
dp[0][0] = 1;

for (int bit = 1; bit < (1 << n); bit++) {
    for (int tmp = bit; tmp; tmp &= tmp - 1) {
        int i = __builtin_ctz(tmp);
        
        for (int prevRem = 0; prevRem < k; prevRem++) {
            int rem = (prevRem * pow10[strs[i].size()] + v[i]) % k;
            dp[bit][rem] += dp[bit ^ (1 << i)][prevRem];
        }
    }
}

ll p = dp.back()[0];
```
k로 나눈 나머지를 저장하는 차원이 하나 더 존재하므로 추가 for문 필요

### [In Search of the Lost Array](https://www.acmicpc.net/problem/32457)
```cpp
vector dp(1 << b.size(), vector<bool>(101)); // dp[bit][x] : bit에 있는 b들만 사용할 때 a의 맨 끝에 x가 올 수 있는지
fill(dp[0].begin() + 1, dp[0].end(), true);

for (int bit = 1; bit < dp.size(); bit++) {
    for (int tmp = bit; tmp; tmp &= tmp - 1) {
        int i = __builtin_ctz(tmp);
        
        for (int x = 1; x <= 100; x++) if (b[i] % x == 0 && b[i] / x <= 100) {
            dp[bit][b[i] / x] = dp[bit][b[i] / x] | dp[bit ^ (1 << i)][x];
        }
    }
}

function<void(int, int)> trace = [&](int bit, int x) {
    assert (dp[bit][x]);

    cout << x << " ";
    if (!bit) return;
    
    for (int tmp = bit; tmp; tmp &= tmp - 1) {
        int i = __builtin_ctz(tmp);
        if (b[i] % x == 0 && b[i] / x <= 100 && dp[bit ^ (1 << i)][b[i] / x]) {
            trace(bit ^ (1 << i), b[i] / x);
            return;
        }
    }

    assert(false);
};

for (int x = 1; x <= 100; x++) if (dp.back()[x]) {
    cout << "Yes\n";
    trace(dp.size() - 1, x);
    return 0;
}

cout << "No\n";
return 0;
```

최단거리 역추적 필요한 문제임   
문제 입력상 `1 << n` 대신 `1 << n - 1`사용해야 되서 같은 의미인 `dp.size()`로 대체해서 사용함   