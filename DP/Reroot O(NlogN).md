[카테고리](/README.md)
## Rerooting
### $O(N\log{N})$ The Ultimate Reroot Template (코드포스에서 그대로 가져왔음 : https://codeforces.com/blog/entry/124286)
```cpp
namespace reroot { // https://codeforces.com/blog/entry/124286
    const auto exclusive = [](const auto &a, const auto &base, const auto &merge_into, int vertex) {
        int n = a.size();
        using Aggregate = decay_t<decltype(base)>;
        vector<Aggregate> b(n, base);
        for (int bit = __lg(n); bit >= 0; --bit) {
            for (int i = n - 1; i >= 0; --i) b[i] = b[i >> 1];
            int sz = n - (n & !bit);
            for (int i = 0; i < sz; ++i) {
                int index = (i >> bit) ^ 1;
                b[index] = merge_into(b[index], a[i], vertex, i);
            }
        }
        return b;
    };
    // MergeInto : Aggregate * Value * Vertex(int) * EdgeIndex(int) -> Aggregate
    // Base : Vertex(int) -> Aggregate
    // FinalizeMerge : Aggregate * Vertex(int) * EdgeIndex(int) -> Value
    const auto rerooter = [](const auto& adj, const auto& base, const auto& merge_into, const auto& finalize_merge) {
        int n = (int)adj.size();
        using Aggregate = decay_t<decltype(base(0))>;
        using Value = decay_t<decltype(finalize_merge(base(0), 0, 0))>;
        vector<Value> root_dp(n), dp(n);
        vector<vector<Value>> edge_dp(n), redge_dp(n);
        
        vector<int> bfs, parent(n);
        bfs.reserve(n);
        bfs.push_back(0);
        for (int i = 0; i < n; ++i) {
            int u = bfs[i];
            for (auto v : adj[u]) {
                if (parent[u] == v) continue;
                parent[v] = u;
                bfs.push_back(v);
            }
        }
        
        for (int i = n - 1; i >= 0; --i) {
            int u = bfs[i];
            int p_edge_index = -1;
            Aggregate aggregate = base(u);
            for (int edge_index = 0; edge_index < (int)adj[u].size(); ++edge_index) {
                int v = adj[u][edge_index];
                if (parent[u] == v) {
                    p_edge_index = edge_index;
                    continue;
                }
                aggregate = merge_into(aggregate, dp[v], u, edge_index);
            }
            dp[u] = finalize_merge(aggregate, u, p_edge_index);
        }
        
        for (auto u : bfs) {
            dp[parent[u]] = dp[u];
            edge_dp[u].reserve(adj[u].size());
            for (auto v : adj[u]) edge_dp[u].push_back(dp[v]);
            auto dp_exclusive = exclusive(edge_dp[u], base(u), merge_into, u);
            redge_dp[u].reserve(adj[u].size());
            for (int i = 0; i < (int)dp_exclusive.size(); ++i) redge_dp[u].push_back(finalize_merge(dp_exclusive[i], u, i));
            root_dp[u] = finalize_merge(n > 1 ? merge_into(dp_exclusive[0], edge_dp[u][0], u, 0) : base(u), u, -1);
            for (int i = 0; i < (int)adj[u].size(); ++i) {
                dp[adj[u][i]] = redge_dp[u][i];
            }
        }

        return make_tuple(move(root_dp), move(edge_dp), move(redge_dp));
    };
} // namespace reroot

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    vector<vector<int> > adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    assert(false, "adj배열을 0-based로 해야 됨");

    // function<int(int, int)> dfs = [&](int cur, int par) -> int {
    //     int res = base(cur); // base
    //     for (auto next : adj[cur]) if (next != par) {
    //         res = merge_into(res, dfs(next, cur), cur, edge_index); // merge_into
    //     }
    //     return finalize_merge(res, cur, edge_index); // finalize_merge
    // };
    // vector<T> reroot_result(n);
    // for (int i = 0; i < n; i++) reroot_result[i] = dfs(i, -1);
    // 위의 O(N^2) 코드를 O(NlogN)으로 변환
    
    using Aggregate = int;
    using Value = int;

    // ex) 모든 v에 대해 v가 루트일 때의 {트리의 높이+1}값 구하기
    auto base = [&](int vertex) -> Aggregate {
        return 0; // 여기만 수정해서 사용하면 됨
    };
    auto merge_into = [&](Aggregate vertex_dp, Value neighbor_dp, int vertex, int edge_index) -> Aggregate {
        return max(vertex_dp, neighbor_dp); // 여기만 수정해서 사용하면 됨
    };
    auto finalize_merge = [&](Aggregate vertex_dp, int vertex, int edge_index) -> Value {
        return vertex_dp + 1; // 여기만 수정해서 사용하면 됨
    };

    auto [reroot_result, edge_dp, redge_dp] = reroot::rerooter(adj, base, merge_into, finalize_merge);
    
    for (auto e : reroot_result) cout << e << " ";

    return 0;
}
```
### 시간복잡도
$O(N \log{N})$   

### 구현 주의사항
코드포스 구현 그대로 가져온거라 평소 내 구현과 다름. adj배열을 0-based로 해야 됨   

### 사용설명
```cpp
function<int(int, int)> dfs = [&](int cur, int par) -> int {
    int res = base(cur); // base
    for (auto next : adj[cur]) if (next != par) {
        res = merge_into(res, dfs(next, cur), cur, edge_index); // merge_into
    }
    return finalize_merge(res, cur, edge_index); // finalize_merge
};
vector<T> reroot_result(n);
for (int i = 0; i < n; i++) reroot_result[i] = dfs(i, -1);
```
그냥 무지성으로 $O(N^2)$코드 짜고 Ultimate Reroot Template의 `base`, `merge_into`, `finalize_merge`부분만 바꿔주면 $O(N\log{N})$으로 계산됨   
(모르겠으면 https://codeforces.com/blog/entry/124286 참고)   

### 문제
[건물 폭파](https://www.acmicpc.net/problem/33582)   

### 참고링크
https://codeforces.com/blog/entry/124286   