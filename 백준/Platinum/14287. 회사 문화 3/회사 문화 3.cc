#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > chd(n + 1);
	for (int i = 1; i <= n; i++) {
		int par;
		cin >> par;
		if (i > 1) chd[par].push_back(i);
	}

	int dfsn = 0;
	vector<int> in(n + 1), out(n + 1);
	function<void(int)> dfs = [&](int cur) {
		in[cur] = ++dfsn;
		for (auto next : chd[cur]) dfs(next);
		out[cur] = dfsn;
	};
	dfs(1);

	int sz = 1;
	while (sz < n) sz <<= 1;
	vector<int> tree(sz << 1);

	auto update = [&](int i, int add) {
		tree[--i |= sz] += add;
		while (i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
	};

	auto query = [&](int l, int r) {
		int res = 0;
		for (--l |= sz, --r |= sz; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) res += tree[l++];
			if (~r & 1) res += tree[r--];
		}
		return res;
	};

	while (m--) {
		int op;
		cin >> op;

		if (op == 1) {
			int i, w;
			cin >> i >> w;
			update(in[i], w);
		}
		else {
			int i;
			cin >> i;
			cout << query(in[i], out[i]) << "\n";
		}
	}

	return 0;
}