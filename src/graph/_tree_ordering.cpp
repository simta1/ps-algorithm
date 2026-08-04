vector<int> p(n + 1, -1), order;
order.push_back(root);
for (int index = 0; index < n; ++index) {
    int cur = order[index];
    for (int next : graph[cur]) if (next != p[cur]) {
        p[next] = cur;
        order.push_back(next);
    }
}
