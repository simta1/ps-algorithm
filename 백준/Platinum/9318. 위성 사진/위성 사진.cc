#include <bits/stdc++.h>
using namespace std;

struct Node {
	int cnt = 0, len = 0;
};

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	constexpr int N = 1'000'000;
	int sz = 1;
	while (sz < N) sz <<= 1;

	int TC;
	for (cin >> TC; TC--;) {
		int n;
		cin >> n;

		vector<Node> tree(sz << 1);

		function<void(int, int, int, int, int, int)> update = [&](int node, int s, int e, int l, int r, int add) {
			if (l > e || s > r) return;
			if (l <= s && e <= r) {
				tree[node].cnt += add;
			}
			else {
				int m = s + e >> 1;
				update(node << 1, s, m, l, r, add);
				update(node << 1 | 1, m + 1, e, l, r, add);
			}

			if (tree[node].cnt) tree[node].len = e - s + 1;
			else if (s == e) tree[node].len = 0;
			else tree[node].len = tree[node << 1].len + tree[node << 1 | 1].len;
		};

		vector<tuple<int, int, int, int> > v;
		v.reserve(n * 2);
		for (int _ = n; _--;) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			v.emplace_back(x1, y1, y2, 1);
			v.emplace_back(x2, y1, y2, -1);
		}
		sort(v.begin(), v.end());

		long long ans = 0, dx = 0;
		for (int i = 0, j = 0; i < v.size(); i = j) {
			ans += dx * tree[1].len;

			j = i + 1;
			while (j < v.size() && get<0>(v[j]) == get<0>(v[i])) ++j;

			for (int k = i; k < j; k++) {
				auto [x, y1, y2, add] = v[k];
				update(1, 0, sz - 1, y1, y2 - 1, add);
			}
			if (j != v.size()) dx = get<0>(v[j]) - get<0>(v[i]);
		}
		cout << ans << "\n";
	}

	return 0;
}
