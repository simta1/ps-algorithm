[Offline Incremental SCC](/그래프%20이론/그래프/Offline%20Incremental%20SCC.md)   
[카테고리](/README.md)
## SCC(Strongly Connected Component)
### Tarjan's algorithm
```cpp
pair<vector<vector<int> >, vector<int> > getSCC(int n, const vector<vector<int> > &adj) { //  auto [sccs, sccn] = getSCC(n, adj);로 사용 // sccs에는 위상정렬된 순서로 {scc1{}, scc2{}, ... } 저장되어 있음
    vector<int> dfsn(n + 1, 0), sccn(n + 1, -1);
    stack<int> s;

    int dfsi = 0, scci = 0;
    function<int(int)> dfs = [&](int cur) -> int {
        int low = dfsn[cur] = ++dfsi;
        s.push(cur);

        for (auto next : adj[cur]) if (!~sccn[next]) low = min(low, dfsn[next] ? dfsn[next] : dfs(next));

        if (low == dfsn[cur]) {
            while (1) {
                int node = s.top();
                s.pop();
                sccn[node] = scci;
                if (node == cur) break;
            }
            ++scci;
        }

        return low;
    };
    for (int i = 1; i <= n; i++) if (!dfsn[i]) dfs(i);

    vector<vector<int> > sccs(scci);
    for (int i = 1; i <= n; i++) sccs[sccn[i] = scci - 1 - sccn[i]].push_back(i);
    return {sccs, sccn};
}
```
### 시간복잡도 
$O(V + E)$   

### 구현 주의사항
타잔 알고리즘으로 SCC를 구할 경우 위상정렬의 역순이 되므로 sccNumber의 값이 클수록 위상정렬 시 앞 쪽에 위치   

self-loop나 parallel edge있어도 잘 작동하므로 딱히 고려할 필요 없음

### 문제
[Strongly Connected Component](https://www.acmicpc.net/problem/2150)   