#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int n;
	cin >> n;

	int sz = 1;
	while (sz < n) sz <<= 1;
	
	vector<int> tree(sz << 1), lazy(sz << 1);
	for (int i = 0; i < n; i++) cin >> tree[sz + i];
	for (int i = sz - 1; i; i--) tree[i] = tree[i << 1] ^ tree[i << 1 | 1];

	auto propagate = [&](int node, int s, int e) {
		if (lazy[node]) {
			int cnt = e - s + 1;
			if (cnt & 1) tree[node] ^= lazy[node];
			if (s != e) {
				lazy[node << 1] ^= lazy[node];
				lazy[node << 1 | 1] ^= lazy[node];
			}
			lazy[node] = 0;
		}
	};

	function<void(int, int, int, int, int, int)> update = [&](int node, int s, int e, int l, int r, int k) {
		propagate(node, s, e);
		if (l <= s && e <= r) {
			lazy[node] ^= k;
			propagate(node, s, e);
			return;
		}
		if (l > e || s > r) return;

		int m = s + e >> 1;
		update(node << 1, s, m, l, r, k);
		update(node << 1 | 1, m + 1, e, l, r, k);
		tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
	};

	function<int(int, int, int, int, int)> query = [&](int node, int s, int e, int l, int r) {
		propagate(node, s, e);
		if (l <= s && e <= r) return tree[node];
		if (l > e || s > r) return 0;

		int m = s + e >> 1;
		return query(node << 1, s, m, l, r) ^ query(node << 1 | 1, m + 1, e, l, r);
	};

	int q;
	for (cin >> q; q--;) {
		int op;
		cin >> op;

		if (op == 1) {
			int i, j, k;
			cin >> i >> j >> k;
			update(1, 0, sz - 1, i, j, k);
		}
		else {
			int i, j;
			cin >> i >> j;
			cout << query(1, 0, sz - 1, i, j) << "\n";
		}
	}

	return 0;
}
