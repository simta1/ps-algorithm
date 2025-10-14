#include <bits/stdc++.h>
using namespace std;

struct Seg {
	int sz;
	vector<int> tree;

	Seg(int n) {
		sz = 1;
		while (sz < n) sz <<= 1;
		tree.resize(sz << 1);
	}

	void update(int i, int add) {
		tree[--i |= sz] += add;
		while (i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}

	int query(int l, int r) {
		int res = 0;
		for (--l |= sz, --r |= sz; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) res += tree[l++];
			if (~r & 1) res += tree[r--];
		}
		return res;
	}
};

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

	Seg fromUp(n), fromDown(n);

	bool down = true;
	while (m--) {
		int op;
		cin >> op;

		if (op == 1) {
			int i, w;
			cin >> i >> w;

			if (down) {
				fromUp.update(in[i], w);
				if (out[i] + 1 <= n) fromUp.update(out[i] + 1, -w);
			}
			else {
				fromDown.update(in[i], w);
			}
		}
		else if (op == 2) {
			int i;
			cin >> i;
			cout << fromUp.query(1, in[i]) + fromDown.query(in[i], out[i]) << "\n";
		}
		else down = !down;
	}

	return 0;
}