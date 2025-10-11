[카테고리](/README.md)
## Rerooting
[$O(N\log{N})$ The Ultimate Reroot Template](https://codeforces.com/blog/entry/124286)

### 구현 주의사항
adj배열을 0-based로 해야 됨   

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
그냥 $O(N^2)$코드 짜고 Ultimate Reroot Template의 `base`, `merge_into`, `finalize_merge`부분만 바꿔주면 $O(N\log{N})$으로 계산됨   

### 문제
[건물 폭파](https://www.acmicpc.net/problem/33582)   

### 참고링크
https://codeforces.com/blog/entry/124286   
