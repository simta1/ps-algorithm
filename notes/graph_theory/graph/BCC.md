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
### BCC에 포함된 간선 정보로부터 포함된 정점 찾기
```cpp
vector<int> getNodeOfBCC(int n, const vector<pair<int, int> > &bcc) {
    static int trueValue = 1;
    static vector<int> visited(n + 1);
    if (visited.size() < n + 1) visited.resize(n + 1); // 테스트케이스 여러 개인 문제면 n 바뀔 수 있음
    
    vector<int> res;
    for (auto [u, v] : bcc) {
        if (visited[u] != trueValue) res.push_back(u);
        if (visited[v] != trueValue) res.push_back(v);
        visited[u] = visited[v] = trueValue;
    }
    
    ++trueValue;
    return res;

/*  int E = bcc.size(), V = getNodeOfBCC(n, bcc).size();라 할 때
    E >= V라면 사이클을 이루는 BCC (E = V라면 단순사이클, E>V라면 해당 BCC의 모든 정점을 지나는 사이클에 chord가 존재)
    E < V라면 (E=0, V=1) 혹은 단절선(E=1, V=2) 뿐임     */
}
```
그냥 set 사용해서 간단히 구현할 수도 있지만 너무 느리다.   
trueValue변수에 대한 설명은 [자주쓰는 변수명](/C++/기타/Variable%20Name.md#truevalue) 참고.   
static변수는 한 번만 초기화되므로 trueValue의 이점이 그대로 적용된다.   

### 시간복잡도
$O(V + E)$   

### 구현 주의사항
`getBCC()`에서 `if (dfsn[next] < dfsn[cur]) edgeStack.emplace(cur, next);`에서 if문 확인 해줘야 간선이 중복되어 들어가지 않음   

### 개념정리
2개 이상의 BCC에 포함되는 정점은 단절점이다.(역도 성립)   
$V=2$, $E=1$라면 해당 BCC는 단절선이다.(역도 성립)   

```cpp
// ex) BCC 사용해서 단절점, 단절선 개수 세기
int cutVertexes = 0, bridges = 0;

auto bccs = getBCC(n, adj);
vector<int> cnt(n + 1);

for (auto &bcc : bccs) {
    auto nodes = getNodeOfBCC(n, bcc);
    int V = nodes.size();
    int E = bcc.size();

    for (auto e : nodes) criticalNodes += (++cnt[e] == 2);
    bridges += (V == 2 && E == 1);
}

cout << cutVertexes << "\n"; // 단절점 개수 
cout << bridges << "\n"; // 단절선 개수 
```

### 문제
[Critical Structures](https://www.acmicpc.net/problem/20264)   
[Minimum Spanning Cactus](https://www.acmicpc.net/problem/23314)   

### 참고링크
https://blog.naver.com/kks227/220802704686   
https://ps.mjstudio.net/bcc#%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98   