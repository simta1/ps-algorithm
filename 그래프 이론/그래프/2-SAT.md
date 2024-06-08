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
        int res = visited[cur] = order++;
        s.push(cur);

        for (int next : adj[cur]) {
            if (!~visited[next]) res = min(res, dfs(next));
            else if (!~sccNumber[next]) res = min(res, visited[next]);
        }

        if (res == visited[cur]) {
            while (1) {
                int node = s.top();
                s.pop();
                sccNumber[node] = id;
                if (node == cur) break;
            }
            ++id;
        }

        return res;
    }

    void findSCC() {
        order = id = 0;

        for (int i = 0; i < 2 * n; i++) if (!~visited[i]) {
            dfs(i);
        }
    }

public:
    Graph(int n) : n(n), adj(2 * n), visited(2 * n, -1), sccNumber(2 * n, -1) {}

    void addEdge(int a, int b) { // 1-based
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

    bool getValue(int i) { // 1-based
        return sccNumber[getNode(i)] < sccNumber[getNode(-i)];
    }
};
```
### 시간복잡도 
$O(V + E)$   

### 사용관련
CNF에서 or로 연결된 부분들을 addEdge하여 사용
addEdge에서 false, true는 각각 -, +부호로 표현
```cpp
// (!x1 or x2) 
graph.addEdge(-1, 2);

// (!x2 or !x3)
graph.addEdge(-2, -3);
```

true를 강제하고 싶은 값이 있다면 추가 간선을 설정해주면 된다.   
x가 true여야 된다면 adj[getNode(-x)].push_back(getNode(x));를 추가하면 된다.   
이 방식으로 1-sat과 2-sat이 혼합된 경우도 해결할 수 있다.   

### 백준문제
[2-SAT - 4](https://www.acmicpc.net/problem/11281)   
[아이돌](https://www.acmicpc.net/problem/3648) - 1-sat 포함   

### 원리
false -> true 꼴이 되야 함   
x -> !x 라면 x = false   
!x -> x 라면 x = true   

x가 true일 조건은 !x -> x   
sccNumber에 저장된 값은 위상정렬의 순서와 반대이므로 sccNumber(x) < sccNumber(!x) 