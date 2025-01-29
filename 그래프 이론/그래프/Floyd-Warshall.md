[카테고리](/README.md)
## Floyd-Warshall
```cpp
template <typename cost_t, typename sum_t> // cost_t는 간선의 가중치를 담을 수 있는 자료형, sum_t는 max(cost_t) * (n - 1) 를 담을 수 있는 자료형
tuple<bool, sum_t, vector<vector<sum_t> > > floydWarshall(int n, const vector<vector<pair<int, cost_t> > > &adj, sum_t justForSumType) {
    const sum_t INF = numeric_limits<sum_t>::max() >> 1;
    vector dist(n + 1, vector<sum_t>(n + 1, INF));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (int u = 1; u <= n; u++) for (auto [v, w] : adj[u]) dist[u][v] = min(dist[u][v], w);

    for (int m = 1; m <= n; m++) {
        for (int s = 1; s <= n; s++) {
            for (int e = 1; e <= n; e++) {
                dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
            }
        }
    }

    bool hasNegCycle = false; // 음수 간선 순환 존재하는지
    for (int i = 1; i <= n; i++) hasNegCycle |= (dist[i][i] < 0);
    return {hasNegCycle, INF, dist};
}
```

### 시간복잡도 
$O(V^3)$   
음수 가중치 존재 시에도 사용 가능   

### 구현 주의사항
`dist[s][m] + dist[m][e]`를 계산할 때 overflow를 방지하려면 INF는 `numeric_limits<T>::max() / 2` 이하의 값 사용   

### 문제
[플로이드](https://www.acmicpc.net/problem/11404)   

### 도달가능성 여부를 유지한 채로 최소의 도로만 남기기
```cpp
vector<vector<int> > reduceGraph(int n, const vector<vector<int> > &adj) {
    vector dist(n + 1, vector<bool>(n + 1));
    for (int u = 1; u <= n; u++) for (auto v : adj[u]) dist[u][v] = true;

    for (int i = 1; i <= n; i++) dist[i][i] = false;

    for (int m = 1; m <= n; m++) {
        for (int s = 1; s <= n; s++) {
            for (int e = 1; e <= n; e++) {
                if (dist[s][e] && dist[s][m] && dist[m][e]) dist[s][e] = false;
            }
        }
    }
    
    vector<vector<int> > reduced(n + 1);
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (dist[u][v]) reduced[u].push_back(v);
        }
    }

    return reduced;
}
```
__백준문제__ [도시 계획](https://www.acmicpc.net/problem/11097)   