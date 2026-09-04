vector<pair<int, int> > getBridges(int n, const vector<vector<int> > &adj) { // O(V + E)
    vector<int> dfsn(n + 1);
    vector<pair<int, int> > res;
    int dfsi = 0;
    auto dfs = [&](auto &&dfs, int cur, int par) -> int {
        int low = dfsn[cur] = ++dfsi;
        for (auto nxt : adj[cur]) if (nxt != par) {
            if (!dfsn[nxt]) {
                int nextLow = dfs(dfs, nxt, cur);
                low = min(low, nextLow);
                if (nextLow > dfsn[cur]) res.emplace_back(cur, nxt);
            }
            else low = min(low, dfsn[nxt]);
        }
        return low;
    };
    for (int i = 1; i <= n; i++) if(!dfsn[i]) dfs(dfs, i, -1);
    for (auto &[a, b] : res) if (a > b) swap(a, b);
    return res;
}
