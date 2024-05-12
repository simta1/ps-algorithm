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

### 주의사항
문제 조건에 따라 추가 간선을 잘 설정해야 된다.   
[아이돌](https://www.acmicpc.net/problem/3648) 문제의 경우 상근이가 무조건 진출할 수 있도록 해야하므로   
findSCC()하기 전 adj[getNode(-1)].push_back(getNode(1)); 를 추가해서 1이 무조건 true이도록 해야 된다.   

getNode()함수의 코드를 return (abs(a) - 1) * 2 + (a > 0); 대신 return (abs(a) - 1) * 2 + (a < 0);로 바꿔면 findSCC에서 무조건 -i가 i보다 먼저 dfs()되므로 간선을 딱히 추가하지 않고도 해결할 수 있지만 이런 방법보다는 직접 간선을 추가함으로써 조건을 명시해주는 것이 더욱 확실하고 안전하다.   
getNode()함수의 순서를 조작하는 방법은 실수할 확률이 높고 혹시나 제출이 맞더라도 틀왜맞 코드가 되기 쉽다.

### 백준문제
[2-SAT - 4](https://www.acmicpc.net/problem/11281)

### 원리
false -> true 꼴이 되야 함   
x -> !x 라면 x = false   
!x -> x 라면 x = true   

x가 true일 조건은 !x -> x   
sccNumber에 저장된 값은 위상정렬의 순서와 반대이므로 sccNumber(x) < sccNumber(!x) 