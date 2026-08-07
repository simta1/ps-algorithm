int get_sz(int cur, int par) {
    sz[cur] = 1;
    for (auto nxt : adj[cur]) if (nxt != par) sz[cur] += get_sz(nxt, cur);
    return sz[cur];
}
int get_ct(int cur, int par) { // O(N)
    for (auto nxt : adj[cur]) if (nxt != par && sz[nxt] * 2 > n) return get_ct(nxt, cur);
    return cur;
}
