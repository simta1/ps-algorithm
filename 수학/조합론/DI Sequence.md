[카테고리](/README.md)
## Valid Permutations for DI Sequence
```cpp
template <typename T>
T countPermutations(int n, const string &st, const T MOD) { // st는 "><<><<"처럼 부등호로만 이루어져있어야 됨
    assert(n == st.size() + 1);
    
    vector dp(n, vector<T>(n)); // dp[i][j] : i+1개의 서로 다른 수를 배열했을 때 마지막 숫자가 j(0-based)인 경우의 수
    dp[0][0] = 1; // 길이 1인 순열 -> "0" 하나
    
    auto add = [&](T &a, T b) {
        a += b;
        if (a >= MOD) a -= MOD;
    };

    for (int i = 1; i < n; ++i) {
        vector<T> pfs(dp[i - 1]);
        // 메모리 부족하면 dp를 1차원으로 토글링 비슷하게 하면 되는데 그냥 가독성을 위해 2차원으로 짰음
        for (int j = 1; j < pfs.size(); j++) add(pfs[j], pfs[j - 1]);

        for (int j = 0; j <= i; ++j) {
            if (st[i - 1] == '<') dp[i][j] = (j ? pfs[j - 1] : 0); // dp[i - 1][0] + ... + dp[i - 1][j - 1]
            else dp[i][j] = (pfs[i - 1] - (j ? pfs[j - 1] : 0) + MOD) % MOD; // dp[i - 1][j] + ... + dp[i - 1][i - 1]
        }
    }

    T res = 0;
    for (int j = 0; j < n; ++j) add(res, dp[n - 1][j]);
    return res;
}
```
### 지그재그 순열(Alternating Permutaion)
```cpp
template <typename T>
T countZigzagPermu(int n, const T MOD) {
    if (n == 1) return 1;
    
    string a, b;
    for (int i = 1; i < n; i++) a += "><"[i & 1];
    for (int i = 1; i < n; i++) b += "<>"[i & 1];
    return (countPermutations(n, a, MOD) + countPermutations(n, b, MOD)) % MOD;
}
```
### 시간복잡도
$O(N^2)$   

### 사용설명
예를 들어 `countPermutations(5, "<<><", MOD)`는 $v[0] \lt v[1] \lt v[2] \gt v[3] \lt v[4]$를 만족하는 순열의 경우의 수를 MOD로 나눈 나머지 계산   

### 문제
[903. Valid Permutations for DI Sequence](https://leetcode.com/problems/valid-permutations-for-di-sequence/description/) - `countPermutations()`   
[지그재그 서기](https://www.acmicpc.net/problem/1146) - 지그재그 순열   
[홍준이의 친위대](https://www.acmicpc.net/problem/3948) - 지그재그 순열   

### 원리
`st[i - 1] == '>'`일 때가 헷갈릴 수 있는데 고민해보면 아래처럼 계산 가능   
```cpp
// dp[i][j] 계산해야 되고 st[i - 1] == '>'일 때
for (int k = j + 1; k <= i; ++k) add(dp[i][j], dp[i - 1][k - 1]);

// 위랑 같은 코드임
for (int k = j; k < i; ++k) add(dp[i][j], dp[i - 1][k]);

// 같은 코드 2
dp[i][j] = (pfs[i - 1] - (j ? pfs[j - 1] : 0) + MOD) % MOD;
```

### 참고링크
지그재그 순열의 개수를 구하는 유명한 점화식이 따로 있는 듯 한데 어차피 $O(N^2)$이라 `countPermutations()`로 커버됨   
굳이 지그재그 순열에 대해서만 다루는 점화식을 알 필요는 없을 듯 한데 나중에 궁금할 수도 있으니 링크만 걸어둠   
https://oeis.org/A000111   
https://nicotina04.tistory.com/75   
https://www.geeksforgeeks.org/euler-zigzag-numbers-alternating-permutation/   