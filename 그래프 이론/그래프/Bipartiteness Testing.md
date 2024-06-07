[카테고리](/README.md)
### Bipartiteness Testing
```cpp
class Graph {
private:
    int n;
    vector<vector<int> > adj;
    vector<char> visited;
    const char visitChanger = 3;

    bool bfs(int start) {
        visited[start] = 1;
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : adj[cur]) {
                if (!visited[next]) {
                    visited[next] = visitChanger - visited[cur];
                    q.push(next);
                }
                else {
                    if (visited[next] == visited[cur]) return false;
                }
            }
        }

        return true;
    }

public:
    Graph(int n) : n(n), adj(n + 1), visited(n + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isBipartite() {
        for (int i = 1; i <= n; i++) if (!visited[i]) {
            if (!bfs(i)) return false;
        }
        return true;
    }
};
```
### 시간복잡도 
bfs 한 번. $O(V+E)$   

### 주의사항
visited배열의 값은 0, 1, 2 뿐이므로 int보다 작은 자료형 쓰는 게 더 빠르지만 같은 자료형의 visitChanger를 선언해서 사용해야 효과를 볼 수 있음   
그냥 코드에 매직넘버로 3 사용하면 뺄셈할 때마다 형변환 일어나서 오히려 더 느려짐   
```cpp
// 느린 코드
visited[next] = 3 - visited[cur]; // 정수 리터럴은 기본적으로 int 취급, 형변환 일어나서 속도 저하

// 빠른 코드
visited[next] = visitChanger - visited[cur];
```

### 백준문제
[이분 그래프](https://www.acmicpc.net/problem/1707)