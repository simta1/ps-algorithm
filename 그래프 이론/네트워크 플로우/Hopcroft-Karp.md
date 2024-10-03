[카테고리](/README.md)
## Hopcroft-Karp
```cpp
class BipartiteGraph {
private:
    vector<vector<int> > adj;
    vector<int> level, assign, visited;
    vector<int> assignp;
    int trueValue;

    bool bfs() { // level graph
        queue<int> q;
        for (int i = 1; i < adj.size(); i++) {
            if (!~assignp[i]) {
                level[i] = 0;
                q.push(i);
            }
            else level[i] = -1;
        }

        bool flag = false;
        while (!q.empty()) {
            int person = q.front();
            q.pop();
            for (auto work : adj[person]) {
                if (!~assign[work]) flag = true;
                else if (!~level[assign[work]]) {
                    level[assign[work]] = level[person] + 1;
                    q.push(assign[work]);
                }
            }
        }
        return flag;
    };

    bool dfs(int person) {
        if (visited[person] == trueValue) return 0;
        visited[person] = trueValue;

        for (auto work : adj[person]) {
            if (!~assign[work] || level[assign[work]] == level[person] + 1 && dfs(assign[work])) {
                assignp[person] = work;
                assign[work] = person;
                return true;
            }
        }
        return false;
    }

public:
    BipartiteGraph(int n1, int n2) : adj(n1 + 1), level(n1 + 1), visited(n1 + 1, 0), assignp(n1 + 1, -1), assign(n2 + 1, -1) {}

    void addEdge(int a, int b) { // 1-based
        adj[a].push_back(b);
    }

    int bipartiteMatching() { // Hopcroft-Karp
        int res = 0;
        
        trueValue = 1;
        while (bfs()) {
            for (int i = 1; i < adj.size(); i++) res += (!~assignp[i] && dfs(i));
            ++trueValue;
        }

        return res;
    }
};
```
### 시간복잡도
$O(E \sqrt V)$   

### 문제
[System Engineer](https://www.acmicpc.net/problem/3736) - [`O(VE) 이분매칭`](/그래프%20이론/네트워크%20플로우/이분매칭.md)로도 풀리긴 함   
[등번호](https://www.acmicpc.net/problem/1733) - 호프크로프트 카프 빠른 구현체로 풀린다는데 시간초과나서 못 풀고 있음   

### 참고링크
https://m.blog.naver.com/kks227/220816033373   
https://gazelle-and-cs.tistory.com/35   
https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm   