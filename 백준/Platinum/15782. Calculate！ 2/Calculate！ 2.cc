#include <bits/stdc++.h>
using namespace std;

struct LazySeg {
	int sz;
	vector<int> tree, lazy;

	LazySeg(int n) {
		sz = 1;
		while (sz < n) sz <<= 1;
		tree.resize(sz << 1);
		lazy.resize(sz << 1);
	}

	void propagate(int node, int s, int e) {
		if (lazy[node]) {
			if (e - s + 1 & 1) tree[node] ^= lazy[node];
			if (s != e) {
				lazy[node << 1] ^= lazy[node];
				lazy[node << 1 | 1] ^= lazy[node];
			}
			lazy[node] = 0;
		}
	}

	void update(int node, int s, int e, int l, int r, int k) {
		propagate(node, s, e);
		if (l <= s && e <= r) {
			lazy[node] = k;
			propagate(node, s, e);
			return;
		}
		if (l > e || s > r) return;

		int m = s + e >> 1;
		update(node << 1, s, m, l, r, k);
		update(node << 1 | 1, m + 1, e, l, r, k);
		tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
	}

	void update(int l, int r, int k) {
		update(1, 0, sz - 1, l - 1, r - 1, k);
	}

	int query(int node, int s, int e, int l, int r) {
		propagate(node, s, e);
		if (l <= s && e <= r) return tree[node];
		if (l > e || s > r) return 0;

		int m = s + e >> 1;
		return query(node << 1, s, m, l, r) ^ query(node << 1 | 1, m + 1, e, l, r);
	}

	int query(int l, int r) {
		return query(1, 0, sz - 1, l - 1, r - 1);
	}
};

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > adj(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int dfsn = 0;
	vector<int> in(n + 1), out(n + 1);
	function<void(int, int)> dfs = [&](int cur, int par) {
		in[cur] = ++dfsn;
		for (auto next : adj[cur]) if (next != par) dfs(next, cur);
		out[cur] = dfsn;
	};
	dfs(1, -1);

	LazySeg seg(n);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		seg.update(in[i], in[i], x);
	}

	while (m--) {
		int op;
		cin >> op;

		if (op == 1) {
			int x;
			cin >> x;
			cout << seg.query(in[x], out[x]) << "\n";
		}
		else {
			int x, y;
			cin >> x >> y;
			seg.update(in[x], out[x], y);
		}
	}

	return 0;
}