#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int n;
	cin >> n;

	int sz = 1;
	while (sz < n) sz <<= 1;
	vector<int> tree(sz << 1);
	for (int i = 0; i < n; i++) tree[i | sz] = 1;
	for (int i = sz - 1; i; i--) tree[i] = tree[i << 1] + tree[i << 1 | 1];

	vector<int> pos(n + 1);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pos[x] = i;
	}

	auto update = [&](int i, int add) {
		tree[i |= sz] += add;
		while (i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
	};

	auto query = [&](int l, int r) {
		int res = 0;
		for (l |= sz, r |= sz; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) res += tree[l++];
			if (~r & 1) res += tree[r--];
		}
		return res;
	};

	for (int i = 1; i <= n; i++) {
		int cnt = i + 1 >> 1;
		if (i & 1) {
			cout << query(0, pos[cnt]) - 1 << "\n";
			update(pos[cnt], -1);
		}
		else {
			cout << query(pos[n + 1 - cnt], n - 1) - 1 << "\n";
			update(pos[n + 1 - cnt], -1);
		}
	}

	return 0;
}