[카테고리](/README.md)
## Valid Permutations for DI Sequence
```cpp
template <typename T>
T countPermutations(int n, const string &st, const T MOD) { // st는 "><<><<"처럼 부등호로만 이루어져있어야 됨
	assert(n == st.size() + 1);

	auto add = [&](T &a, T b) {
		a += b;
		if (a >= MOD) a -= MOD;
	};

	vector dp(n, vector<T>(n)); // dp[i][j] : i+1개의 서로 다른 수를 배열했을 때 j(0-based)번째로 작은 수가 마지막에 오는 경우의 수
	dp[0][0] = 1; // 길이 1인 순열 -> "0" 하나
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; ++j) {
			T sum = j ? dp[i - 1][j - 1] : 0;
			dp[i][j] = st[i - 1] == '<' ? sum
										: ((dp[i - 1][i - 1] + MOD - sum) % MOD);
		}
		for (int j = 1; j <= i; j++) add(dp[i][j], dp[i][j - 1]);
	}

	return dp[n - 1][n - 1];
}
```
### 시간복잡도
$O(N^2)$   

### 사용설명
예를 들어 `countPermutations(5, "<<><", MOD)`는 $v[0] \lt v[1] \lt v[2] \gt v[3] \lt v[4]$를 만족하는 순열의 경우의 수를 MOD로 나눈 나머지 계산   

### 문제
[903. Valid Permutations for DI Sequence](https://leetcode.com/problems/valid-permutations-for-di-sequence/description/)   
[지그재그 서기](https://www.acmicpc.net/problem/1146)   
[홍준이의 친위대](https://www.acmicpc.net/problem/3948)   
[T - Permutation](https://atcoder.jp/contests/dp/tasks/dp_t)   

### 참고링크
지그재그 순열의 개수를 구하는 유명한 점화식이 따로 있는 듯 한데 어차피 $O(N^2)$임(아래 링크 참고)   
https://oeis.org/A000111   
https://nicotina04.tistory.com/75   
https://www.geeksforgeeks.org/euler-zigzag-numbers-alternating-permutation/   
