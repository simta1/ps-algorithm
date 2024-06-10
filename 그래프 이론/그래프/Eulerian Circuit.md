[카테고리](/README.md)
### Hierholzer's algorithm (Undirected Graph)
```cpp
class Graph {
private:
    struct Edge {
        int next = 0, cnt = 0, rdjIdx = 0;
    };

    int n;
    vector<vector<Edge> > adj;
    vector<int> degree, eulerCircuit;

    void dfs(int cur) {
        while (!adj[cur].empty()) {
            auto &[next, cnt, rdjIdx] = adj[cur].back();
            if (cnt == 0) {
                adj[cur].pop_back();
                continue;
            }

            --adj[cur].back().cnt;
            --adj[next][rdjIdx].cnt;
            dfs(next);
        }

        eulerCircuit.push_back(cur);
    }

    bool checkDegree() {
        for (int i = 1; i <= n; i++) {
            if (degree[i] & 1) return false;
        }
        return true;
    }

    bool haveOnlyOneComponent() {
        vector<bool> visited(n + 1, false);
        visited[1] = true;

        queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto [next, _, __] : adj[cur]) if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) return false;
        }

        return true;
    }

public:
    Graph(int n) : n(n), adj(n + 1), degree(n + 1) {}

    void addEdge(int u, int v, int cnt) {
        if (!cnt) return;

        adj[u].push_back(Edge{v, cnt, int(adj[v].size())});
        adj[v].push_back(Edge{u, cnt, int(adj[u].size() - 1)});

        degree[u] += cnt;
        degree[v] += cnt;
    }

    bool circuitExist() {
        return checkDegree() && haveOnlyOneComponent();
    }

    vector<int> getEulerCircuit() {
        dfs(1);
        return eulerCircuit;
    }
};
```
## 단방향 간선, 테스트 안 된 코드
### Hierholzer's algorithm (Directed Graph)
```cpp
class Graph {
private:
    int n;
    vector<vector<pair<int, int> > > adj;
    vector<int> inDegree, outDegree, eulerCircuit;

    void dfs(int cur) {
        while (!adj[cur].empty()) {
            auto &[next, cnt] = adj[cur].back();
            // if (cnt == 0) {
            //     adj[cur].pop_back();
            //     continue;
            // }

            // --adj[cur].back().cnt;

            if (--adj[cur].back().cnt == 0) adj[cur].pop_back();
            dfs(next);
        }

        eulerCircuit.push_back(cur);
    }

    bool checkDegree() {
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] != outDegree[i]) return false;
        }
        return true;
    }

    bool haveOnlyOneComponent() {
        vector<bool> visited(n + 1, false);
        visited[1] = true;

        queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto [next, _, __] : adj[cur]) if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) return false;
        }

        return true;
    }

public:
    Graph(int n) : n(n), adj(n + 1), inDegree(n + 1), outDegree(n + 1) {}

    void addEdge(int u, int v, int cnt) {
        if (!cnt) return;

        adj[u].push_back({v, cnt});
        outDegree[u] += cnt;
        inDegree[v] += cnt;
    }

    bool circuitExist() {
        return checkDegree() && haveOnlyOneComponent();
    }

    vector<int> getEulerCircuit() {
        dfs(1);
        reverse(eulerCircuit.begin(), eulerCircuit.end());
        return eulerCircuit;
    }
};
```
### 시간복잡도 
$O(E)$   

### 주의사항
dfs에서 다쓴 간선은 아예 벡터에서 pop해주는 게 속도향상에 좋다.   
```cpp
// 느린 코드 (2684ms)
void dfs(int cur) {
    for (auto &[next, cnt, rdjIdx] : adj[cur]) if (cnt) {
        --cnt;
        --adj[next][rdjIdx].cnt;
        dfs(next);
    }

    eulerCircuit.push_back(cur);
}

// 빠른 코드 (588ms)
void dfs(int cur) {
    while (!adj[cur].empty()) {
        auto &[next, cnt, rdjIdx] = adj[cur].back();
        if (cnt == 0) {
            adj[cur].pop_back();
            continue;
        }

        --adj[cur].back().cnt;
        --adj[next][rdjIdx].cnt;
        dfs(next);
    }

    eulerCircuit.push_back(cur);
}

방향그래프에선 마지막에 얻어진 결과를 뒤집어야 된다.   
```
### 사용관련
홀수 차수 정점 2개 존재 시 오일러 경로를 구하려면 두 홀수 차수 정점을 cnt=1인 가상간선으로 이어주고 회로를 찾은 뒤 가상간선 삭제   

### 백준문제
[오일러 회로](https://www.acmicpc.net/problem/1199) - 양방향 그래프   
[수열 복원](https://www.acmicpc.net/problem/1591) - 단방향   

### 원리
오일러 회로는(Eulerian Circuit)는 오일러 경로(Eulerian Path) 중 시작점과 끝점이 같은 경우   

홀수 차수 정점 2개 : 오일러 경로만 존재   
홀수 차수 정점 0개 : 오일러 회로 존재   

### 참고문헌
https://m.blog.naver.com/kks227/220800097205?referrerCode=1   