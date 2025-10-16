#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;
void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

struct Seg {
	int sz;
	vector<int> tree;

	Seg(int n) {
		sz = 1;
		while (sz < n) sz <<= 1;
		tree.resize(sz << 1);
	}

	void update(int i, int val) {
		add(tree[i |= sz], val);
		while (i >>= 1) add(tree[i], val);
	}

	int query(int l, int r) {
		int res = 0;
		for (l |= sz, r |= sz; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) add(res, tree[l++]);
			if (~r & 1) add(res, tree[r--]);
		}
		return res;
	}
};

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int n;
	cin >> n;

	Seg sum(200'000), cnt(200'000);

	ll ans = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		
		ll cur = 0;
		if (x) {
			cur += ll(x) * cnt.query(0, x - 1) - sum.query(0, x - 1);
			cur = (cur % MOD + MOD) % MOD;
		}
		if (x + 1 < 200'000) {
			cur += sum.query(x + 1, 199'999) - ll(x) * cnt.query(x + 1, 199'999);
			cur = (cur % MOD + MOD) % MOD;
		}
		if (i) ans = ans * cur % MOD;

		sum.update(x, x);
		cnt.update(x, 1);
	}
	cout << ans;

	return 0;
}