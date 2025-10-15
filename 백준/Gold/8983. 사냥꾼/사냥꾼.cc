#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int m, n, l;
	cin >> m >> n >> l;

	vector<int> v(m);
	for (auto &e : v) cin >> e;
	sort(v.begin(), v.end());

	int ans = 0;
	for (int _ = n; _--;) {
		int x, y;
		cin >> x >> y;

		if (y > l) continue;

		int len = l - y;
		ans += upper_bound(v.begin(), v.end(), x + len) != lower_bound(v.begin(), v.end(), x - len);
	}

	cout << ans;

	return 0;
}