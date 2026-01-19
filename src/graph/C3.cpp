void getC3(const vector<vector<int> &adj) { // sum_E{min(deg(u), deg(v))} = O(m sqrt(m))
    vector<vector<int> > dag(adj.size());
    for (int u = 0; u < adj.size(); u++) {
        for (auto v : adj[u]) {
            if (adj[u].size() < adj[v].size() || (adj[u].size() == adj[v].size() && u < v)) dag[u].push_back(v);
        }
    } // dag에서 차수는 전부 O(sqrt(m)) 이하
    vector<int> mark(adj.size());
    for (int i = 0; i < adj.size(); i++) {
        for (auto j : adj[i]) mark[j] = i;
        for (auto j : dag[i]) {
            for (auto k : dag[j]) {
                if (mark[k] == i) cout << i << " " << j << " " << k << "\n";
            }
        }
    }
}