#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<int> parent(n + 1);
	for (int i = 1; i <= n; i++) cin >> parent[i];

	vector<int> dp(n + 1);
	while (m--) {
		int i, w;
		cin >> i >> w;
		dp[i] += w;
	}

	for (int i = 2; i <= n; i++) dp[i] += dp[parent[i]];

	for (int i = 1; i <= n; i++) cout << dp[i] << " ";

	return 0;
}
