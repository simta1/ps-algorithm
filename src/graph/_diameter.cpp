auto bfs = [&](int s) {
    vector<int> dist(n + 1, -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (auto nxt : adj[cur]) if (!~dist[nxt]) {
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    return dist;
};

auto d1 = bfs(1);
int a = max_element(d1.begin(), d1.end()) - d1.begin();
auto da = bfs(a);
int b = max_element(da.begin(), da.end()) - da.begin();
auto db = bfs(b);
int D = da[b];
