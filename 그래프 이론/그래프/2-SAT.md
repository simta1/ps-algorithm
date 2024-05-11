[카테고리](/README.md)
### 2-SAT
```cpp
class Graph {
private:
    int n, order, id;
    vector<vector<int> > adj;
    vector<int> visited, sccNumber;
    stack<int> s;

    int getNode(int a) {
        return (abs(a) - 1) * 2 + (a > 0);
    }

    int dfs(int cur) {
        int ret = visited[cur] = order++;
        s.push(cur);

        for (int next : adj[cur]) {
            if (!~visited[next]) ret = min(ret, dfs(next));
            else if (!~sccNumber[next]) ret = min(ret, visited[next]);
        }

        if (ret == visited[cur]) {
            while (1) {
                int node = s.top();
                s.pop();
                sccNumber[node] = id;
                if (node == cur) break;
            }
            ++id;
        }

        return ret;
    }

    void findSCC() {
        order = id = 0;

        for (int i = 0; i < 2 * n; i++) if (!~visited[i]) {
            dfs(i);
        }
    }

public:
    Graph(int n) : n(n), adj(2 * n), visited(2 * n, -1), sccNumber(2 * n, -1) {}

    void addEdge(int a, int b) {
        adj[getNode(-a)].push_back(getNode(b));
        adj[getNode(-b)].push_back(getNode(a));
    }

    bool check() {
        findSCC();

        for (int i = 1; i <= n; i++) {
            if (sccNumber[getNode(i)] == sccNumber[getNode(-i)]) return false;
        }
        return true;
    }

    bool getValue(int i) {
        return sccNumber[getNode(i)] < sccNumber[getNode(-i)];
    }
};
```
### 시간복잡도 
$O(V + E)$   

### 백준문제
[2-SAT - 4](https://www.acmicpc.net/problem/11281)

### 원리
false -> true 꼴이 되야 함   
x -> !x 라면 x = false   
!x -> x 라면 x = true   

x가 true일 조건은 !x -> x   
sccNumber에 저장된 값은 위상정렬의 순서와 반대이므로 sccNumber(x) < sccNumber(!x) 