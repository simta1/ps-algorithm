#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Seg {
	int sz = 1;
	vector<ll> tree;

	Seg(int n) {
		while (sz < n) sz <<= 1;
		tree.resize(sz << 1);
	}

	void update(int i, ll add) {
		tree[--i |= sz] += add;
		while (i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}

	ll query(int l, int r) {
		ll res = 0;
		for (--l |= sz, --r |= sz; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) res += tree[l++];
			if (~r & 1) res += tree[r--];
		}
		return res;
	}
};

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int n;
	cin >> n;

	Seg a(n), b(n), c(n);
	for (int _ = n; _--;) {
		int x;
		cin >> x;

		if (x + 1 <= n) {
			c.update(x, b.query(x + 1, n));
			b.update(x, a.query(x + 1, n));
		}
		a.update(x, 1);
	}

	cout << c.query(1, n);

	return 0;
}
