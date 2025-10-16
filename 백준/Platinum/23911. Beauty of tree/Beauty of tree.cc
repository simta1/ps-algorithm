#include <bits/stdc++.h>
using namespace std;
using ld = double;

int f(const vector<int> &v, int low, int upp) {
	return upper_bound(v.begin(), v.end(), upp) - lower_bound(v.begin(), v.end(), low);
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		int n, a, b;
		cin >> n >> a >> b;

		vector<vector<int> > chd(n + 1);
		for (int i = 2; i <= n; i++) {
			int par;
			cin >> par;
			chd[par].push_back(i);
		}

		int dfsn = 0;
		vector<int> in(n + 1), out(n + 1), depth(n + 1);
		function<void(int, int)> dfs = [&](int cur, int dep) {
			in[cur] = ++dfsn;
			depth[cur] = dep;
			for (auto next : chd[cur]) dfs(next, dep + 1);
			out[cur] = dfsn;
		};
		dfs(1, 0);

		vector<vector<int> > av(a), bv(b);
		for (int i = 1; i <= n; i++) {
			av[depth[i] % a].push_back(in[i]);
			bv[depth[i] % b].push_back(in[i]);
		}

		for (auto &r : av) sort(r.begin(), r.end());
		for (auto &r : bv) sort(r.begin(), r.end());

		ld ans = 0;
		for (int i = 1; i <= n; i++) {
			int acnt = f(av[depth[i] % a], in[i], out[i]);
			int bcnt = f(bv[depth[i] % b], in[i], out[i]);
			ld pa = ld(acnt) / n;
			ld pb = ld(bcnt) / n;
			ans += pa + pb - pa * pb;
		}

		cout << "Case #" << tc << ": " << ans << "\n";
	}

	return 0;
}