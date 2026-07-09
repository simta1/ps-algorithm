int dfsi = 0;
void ett(int cur, int par) {
    in[cur] = ++dfsi;
    for (int next : adj[cur]) if (next != par) ett(next, cur);
    out[cur] = dfsi;
}
bool is_ancestor(int u, int v) { return in[u] <= in[v] && in[v] <= out[u]; }