#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	int sz = 1;
	while (sz < n) sz <<= 1;
	using ll = long long;
	vector<ll> tree(sz << 1);

	auto update = [&](int i, int val) {
		tree[--i |= sz] = val;
		while (i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
	};

	auto query = [&](int l, int r) {
		if (l > r) swap(l, r);
		ll res = 0;
		for (--l |= sz, --r |= sz; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) res += tree[l++];
			if (~r & 1) res += tree[r--];
		}
		return res;
	};

	while (m--) {
		int op, a, b;
		cin >> op >> a >> b;

		if (op) update(a, b);
		else cout << query(a, b) << "\n";
	}

	return 0;
}