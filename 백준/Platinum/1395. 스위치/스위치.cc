#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	int sz = 1;
	while (sz < n) sz <<= 1;

	vector<int> tree(sz * 2);
	vector<bool> lazy(sz * 2);

	function<void(int, int, int)> propagate = [&](int node, int s, int e) {
		if (lazy[node]) {
			tree[node] = e - s + 1 - tree[node];
			if (s != e) {
				lazy[node << 1] = !lazy[node << 1];
				lazy[node << 1 | 1] = !lazy[node << 1 | 1];
			}
			lazy[node] = false;
		}
	};

	function<void(int, int, int, int, int)> update = [&](int node, int s, int e, int l, int r) {
		propagate(node, s, e);
		if (l > e || s > r) return;

		if (l <= s && e <= r) {
			lazy[node] = true;
			propagate(node, s, e);
			return;
		}

		int m = s + e >> 1;
		update(node << 1, s, m, l, r);
		update(node << 1 | 1, m + 1, e, l, r);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	};

	function<int(int, int, int, int, int)> query = [&](int node, int s, int e, int l, int r) {
		propagate(node, s, e);
		if (l > e || s > r) return 0;
		if (l <= s && e <= r) return tree[node];

		int m = s + e >> 1;
		return query(node << 1, s, m, l, r) + query(node << 1 | 1, m + 1, e, l, r);
	};

	while (m--) {
		int op, l, r;
		cin >> op >> l >> r;

		if (op == 0) update(1, 0, sz - 1, l - 1, r - 1);
		else cout << query(1, 0, sz - 1, l - 1, r - 1) << "\n";
	}

	return 0;
}