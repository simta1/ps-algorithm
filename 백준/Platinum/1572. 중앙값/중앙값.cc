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
		tree[i |= sz] += add;
		while (i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}

	int query(int l, int r) {
		int res = 0;
		for (l |= sz, r |= sz; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) res += tree[l++];
			if (~r & 1) res += tree[r--];
		}
		return res;
	}

	int findKth(int node, int s, int e, int k) {
		if (s == e) return s;

		int m = s + e >> 1;
		if (tree[node << 1] >= k) return findKth(node << 1, s, m, k);
		return findKth(node << 1 | 1, m + 1, e, k - tree[node << 1]);
	}
};

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (auto &e : v) cin >> e;

	Seg seg(65537);
	for (int i = 0; i < k - 1; i++) seg.update(v[i], 1);

	long long ans = 0;
	for (int i = k - 1; i < n; i++) {
		seg.update(v[i], 1);
		ans += seg.findKth(1, 0, seg.sz - 1, k + 1 >> 1);
		seg.update(v[i - k + 1], -1);
	}
	cout << ans;

	return 0;
}