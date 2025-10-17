#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	array<int, 11> v;
	for (auto &e : v) cin >> e;

	int n, ans = 0;
	for (cin >> n; n--;) {
		int b;
		double l;
		int s;
		cin >> b >> l >> s;

		if (l >= 2.0 && s >= 17) ans += v[b];
	}

	cout << ans;

	return 0;
}
