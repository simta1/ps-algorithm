[카테고리](/README.md)
## BCC(Biconnected Components, 이중 연결 요소)
```cpp
vector<vector<pair<int, int> > > getBCC(int n, const vector<vector<int> > &adj) {
    vector<int> dfsn(n + 1, 0);
    stack<pair<int, int> > edgeStack;
    vector<vector<pair<int, int> > > bccs;

    int dfsi = 0;
    function<int(int, int)> dfs = [&](int cur, int parent) -> int {
        int low = dfsn[cur] = ++dfsi;

        for (auto next : adj[cur]) if (next != parent) {
            if (dfsn[next] < dfsn[cur]) edgeStack.emplace(cur, next);
            
            if (!dfsn[next]) {
                int nextLow = dfs(next, cur);
                low = min(low, nextLow);

                if (nextLow >= dfsn[cur]) {
                    vector<pair<int, int> > bcc;
                    while (!edgeStack.empty()) {
                        auto [u, v] = edgeStack.top();
                        edgeStack.pop();
                        bcc.emplace_back(u, v);
                        if ((u == cur && v == next) || (u == next && v == cur)) break;
                    }
                    bccs.push_back(bcc);
                }
            }
            else low = min(low, dfsn[next]);
        }

        return low;
    };
    for (int i = 1; i <= n; i++) if (!dfsn[i]) dfs(i, -1);

    return bccs;
}
```

### 시간복잡도
$O(V + E)$   

### 구현 주의사항
`if (dfsn[next] < dfsn[cur]) edgeStack.emplace(cur, next);`에서 if문 확인 해줘야 간선이 중복되어 들어가지 않음   

### 문제
[Cactus? Not cactus?](https://www.acmicpc.net/problem/10891)   

### 참고링크
https://blog.naver.com/kks227/220802704686   
https://ps.mjstudio.net/bcc#%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98   