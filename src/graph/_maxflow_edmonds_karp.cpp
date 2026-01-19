struct Graph {
	struct Edge { int to, rev, c, oc; };
	vector<vector<Edge> > adj;
    vector<Edge *> pedge;
	Graph(int n) : adj(n), pedge(n) {} // 0-based
    void addEdge(int u, int v, int c) {
        adj[u].push_back({v, adj[v].size(), c, c});
        adj[v].push_back({u, adj[u].size() - 1, 0, 0});
    }
    int maxFlow(int s, int t) { // edmonds karp // O(V E^2)
        int res = 0;
        while (1) {
            fill(pedge.begin(), pedge.end(), nullptr);
            queue<int> q;
            q.push(s);
            bool found = false;
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                for (auto &e : adj[cur]) if (!pedge[e.to] && e.c > 0) {
                    pedge[e.to] = &e;
                    q.push(e.to);
                }
                if (pedge[t]) break;
            }
            if (!pedge[t]) break;
            int flow = numeric_limits<int>::max();
            for (int cur = t; cur != s;) {
                auto &e = *pedge[cur];
                flow = min(flow, e.c);
                cur = adj[e.to][e.rev].to;
            }
            for (int cur = t; cur != s;) {
                auto &e = *pedge[cur];
                e.c -= flow;
                adj[e.to][e.rev].c += flow;
                cur = adj[e.to][e.rev].to;
            }
            res += flow;
        }
        return res;
    }
};
