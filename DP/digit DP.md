[카테고리](/README.md)
## Digit Dp
### 상한이 있는 경우(tight 사용)
```cpp
ll digitSum(ll n) {
	if (n <= 0) return 0;

	vector<int> digits;
	while (n) {
		digits.push_back(n % 10);
		n /= 10;
	}
	reverse(digits.begin(), digits.end());

	int len = digits.size();
	vector cnt(len + 1, vector<ll>(2));
	cnt[0][1] = 1;
	for (int i = 0; i < len; i++) {
		for (int tight = 0; tight < 2; tight++) {
			for (int d = 0; d <= (tight ? digits[i] : 9); d++) {
				cnt[i + 1][tight && d == digits[i]] += cnt[i][tight];
			}
		}
	}

	vector dp(len + 1, vector<ll>(2));
	dp[0][1] = 0;
	for (int i = 0; i < len; i++) {
		for (int tight = 0; tight < 2; tight++) {
			for (int d = 0; d <= (tight ? digits[i] : 9); d++) {
				dp[i + 1][tight && d == digits[i]] += cnt[i][tight] * d + dp[i][tight];
			}
		}
	}

	return dp[len][0] + dp[len][1];
}
```
### leading Zero 고려(started 사용)
```cpp
vector dp(len + 1, vector(2, vector<ll>(2)));
dp[0][1][0] = 1; // tight=true, started=false

for (int i = 0; i < len; i++) {
	for (int tight = 0; tight < 2; tight++) {
		for (int started = 0; started < 2; started++) {
			for (int d = 0; d <= (tight ? digits[i] : 9); d++) {
				// dp전파가 started 여부와 관련없는 경우
				dp[i + 1][tight && d == digits[i]][started || d] += dp[i][tight][started];

				// dp의 다른 차원들이 started 여부에 따라 조건분기가 필요한 경우
				if (started || d) {
					dp[i + 1][tight && d == (st[i] & 15)][true] += dp[i][tight][started];
				}
				else {
					dp[i + 1][tight && d == (st[i] & 15)][false] += dp[i][tight][started];
				}
			}
		}
	}
}
```

### 특정 조건을 만족하는 수의 개수 계산
```
// ex) 0을 포함하는 n 이하 수들의 개수
int len = st.size();

vector dp(len + 1, vector(2, vector(2, vector<ll>(2)))); // dp[pos][tight][started][hasZero]
dp[0][1][0][0] = 1;

for (int i = 0; i < len; i++) {
	for (int tight = 0; tight < 2; tight++) {
		for (int started = 0; started < 2; started++) {
			for (int hasZero = 0; hasZero < 2; hasZero++) {
				for (int d = 0; d <= (tight ? (st[i] & 15) : 9); d++) {
					dp[i + 1][tight && d == (st[i] & 15)][started || d][hasZero || (started && d == 0)] += dp[i][tight][started][hasZero];
				}
				
			}
		}
	}
}

return dp[len][0][1][1] + dp[len][1][1][1];
```

### 구현 주의사항
```cpp
// dp state에 자릿수의 곱이 포함된 경우
// ex) dp[pos][tight][started][mul]
dp[0][1][0][1] = 1; // 초기값 설정 시 곱셈의 항등원인 mul=1로 설정해야 함

// dp state에 곱이 포함되어 있는 경우 started여부에 따라 조건분기 필요
if (started || d) {
	dp[i + 1][tight && d == (st[i] & 15)][true][mul * d] += dp[i][tight][started][mul];
}
else {
	dp[i + 1][tight && d == (st[i] & 15)][false][mul] += dp[i][tight][started][mul];
}
```

### 문제
[농부 비니](https://www.acmicpc.net/problem/20957) - `dp[pos]`   
[자리합](https://www.acmicpc.net/problem/5425) - `dp[pos][tight]`   
[Special Numbers](https://www.acmicpc.net/problem/30861) - `dp[pos][tight][started][hasZero]`   
