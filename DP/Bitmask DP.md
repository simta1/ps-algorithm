[카테고리](/README.md)
[카테고리](/README.md)
## Bitmask DP
```cpp
vector<ld> dp(1 << n, INVALID_VALUE);
dp[0] = INIT_VALUE;

int endBit = ~-(1 << n);
for (int bit = 0; bit < (1 << n); bit++) {
    int cnt = __builtin_popcount(bit);
    int zeroBitFinder = bit;
    while (zeroBitFinder != endBit) {
        int newBit = ~zeroBitFinder & (zeroBitFinder + 1);
        int i = 31 - __builtin_clz(newBit);
        dp[bit | newBit] = best(dp[bit | newBit], func(dp[bit], i, cnt));
        zeroBitFinder |= (zeroBitFinder + 1);
    }
}

cout << dp.back();
```
### 시간복잡도
$O(N ~ 2^{N-1})$   

### 원리
> ### 이해용 기본코드 $O(N^2 2^N)$
> ```cpp
> vector<ld> dp(1 << n, INVALID_VALUE);
> dp[0] = INIT_VALUE;
> 
> for (int cnt = 0; cnt < n; cnt++) {
>     for (int bit = 0; bit < (1 << n); bit++) if (__builtin_popcount(bit) == cnt) {
>         for (int i = 0; i < n; i++) if (!(bit & 1 << i)) {
>             dp[bit | 1 << i] = best(dp[bit | 1 << i], func(dp[bit], i, cnt));
>         }
>     }
> }
> 
> cout << dp.back();
> ```
> best()는 min()이나 max(), add() 등의 함수. 일단 일반화를 위해 best라 표시했음   
> popcount()의 개수 cnt에 대해 for문으로 순회.   
> 시간복잡도 최악.   
> 
> ### 기본코드 $O(N 2^N)$
> ```cpp
> vector<ld> dp(1 << n, INVALID_VALUE);
> dp[0] = INIT_VALUE;
> 
> for (int bit = 0; bit < (1 << n); bit++) {
>     int cnt = __builtin_popcount(bit);
>     for (int i = 0; i < n; i++) if (!(bit & 1 << i)) {
>         dp[bit | 1 << i] = best(dp[bit | 1 << i], func(dp[bit], i, cnt));
>     }
> }
> 
> cout << dp.back();
> ```
> 그냥 0부터 $2^n$까지 순차적으로 봐도 됨   
> 임의의 i에 대해서 i의 부분집합에 해당하는 모든 비트들은 어차피 0~(i-1)을 순회하는 동안 확인되기 때문에 순서가 꼬이지 않음   
> 
> ### 최적화코드 $O(N 2^{N-1})$
> ```cpp
> vector<ld> dp(1 << n, INVALID_VALUE);
> dp[0] = INIT_VALUE;
> 
> int endBit = ~-(1 << n);
> for (int bit = 0; bit < (1 << n); bit++) {
>     int cnt = __builtin_popcount(bit);
>     int zeroBitFinder = bit;
>     while (zeroBitFinder != endBit) {
>         int newBit = ~zeroBitFinder & (zeroBitFinder + 1);
>         int i = 31 - __builtin_clz(newBit);
>         dp[bit | newBit] = best(dp[bit | newBit], func(dp[bit], i, cnt));
>         zeroBitFinder |= (zeroBitFinder + 1);
>     }
> }
> 
> cout << dp.back();
> ```
> gcc builtin `__builtin_popcount`와 `__builtin_clz`는 $O(1)$이므로 굉장히 빠름
> 
> 기본 코드에선 bit에서 0비트의 위치를 찾기 위해 i=0~n을 전부 순회하며 확인했지만 애초에 0비트만 순회하도록 최적화 가능   
> 
> `~x & (x + 1)`는 x의 최우측 0비트를 찾는 비트트릭   
> 펜윅트리에서 최우측 1비트를 찾을 때 쓰는 `x & -x`에 `x` 대신 `x+1`을 대입한 것으로 이해하면 편함
> 
> 결과적으로 popcount가 k개인 nCk개의 비트들에 대해 각각 k개씩의 불필요한 순회를 줄일 수 있으므로 총 $\displaystyle\sum_{k=0}^{n-1}k\binom{n}{k} = n 2^{n-1} - 1$ 번의 연산을 이득봄.   
> 기본코드의 연산횟수가 $O(N 2^N)$이므로 시간복잡도 절반으로 단축 가능   

### 문제
### [007](https://www.acmicpc.net/problem/3056)   
```cpp
vector<ld> dp(1 << n, 0);
dp[0] = 1;

int endBit = ~-(1 << n);
for (int bit = 0; bit < (1 << n); bit++) {
    int cnt = __builtin_popcount(bit);

    int zeroBitFinder = bit;
    while (zeroBitFinder != endBit) {
        int newBit = ~zeroBitFinder & (zeroBitFinder + 1);
        int i = 31 - __builtin_clz(newBit);
        dp[bit | newBit] = max(dp[bit | newBit], dp[bit] * v[i][cnt] * 0.01);
        zeroBitFinder |= (zeroBitFinder + 1);
    }
}

cout << fixed << setprecision(6) << dp.back() * 100;
```

### [할 일 정하기 1](https://www.acmicpc.net/problem/1311)
```cpp
const int INF = 1e9;
vector<int> dp(1 << n, INF);
dp[0] = 0;

int endBit = ~-(1 << n);
for (int bit = 0; bit < (1 << n); bit++) {
    int cnt = __builtin_popcount(bit);
    int zeroBitFinder = bit;
    while (zeroBitFinder != endBit) {
        int newBit = ~zeroBitFinder & (zeroBitFinder + 1);
        int i = 31 - __builtin_clz(newBit);
        dp[bit | newBit] = min(dp[bit | newBit], dp[bit] + v[i][cnt]);
        zeroBitFinder |= (zeroBitFinder + 1);
    }
}

cout << dp.back();
```
### [박성원](https://www.acmicpc.net/problem/1086)
```cpp
vector dp(1 << n, vector<ll>(k));
dp[0][0] = 1;

int endBit = ~-(1 << n);
for (int bit = 0; bit < (1 << n); bit++) {
    int zeroBitFinder = bit;
    while (zeroBitFinder != endBit) {
        int newBit = ~zeroBitFinder & (zeroBitFinder + 1);
        int i = 31 - __builtin_clz(newBit);
        
        for (int rem = 0; rem < k; rem++) {
            int nextRem = (rem * pow10[strs[i].size()] + v[i]) % k;
            dp[bit | newBit][nextRem] += dp[bit][rem];
        }
        
        zeroBitFinder |= (zeroBitFinder + 1);
    }
}

ll p = dp.back()[0], q = 1;
```
k로 나눈 나머지를 저장하는 차원이 하나 더 존재하므로 zeroBitFinder 순회문 안에 추가 반복문 필요