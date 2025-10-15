#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int m, n, l;
	cin >> m >> n >> l;

	vector<int> v(m);
	for (auto &e : v) cin >> e;

	int ans = 0;
	for (int _ = n; _--;) {
		ll x, y;
		cin >> x >> y;

		if (y > l) continue;

		int len = l - y;
		ans += upper_bound(v.begin(), v.end(), x + len) != lower_bound(v.begin(), v.end(), x - len);
	}

	cout << ans;

	return 0;
}
