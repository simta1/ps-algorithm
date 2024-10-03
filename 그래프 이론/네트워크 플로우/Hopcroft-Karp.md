[카테고리](/README.md)
## Hopcroft-Karp
```cpp
class BipartiteGraph {
private:
    int n1, n2;
    vector<vector<int> > adj;
    vector<int> matchL, matchR, checkedR, level;
    int trueValue;

    bool bfs() { // level graph
        queue<int> q;
        for (int l = 1; l <= n1; l++) {
            if (!~matchL[l]) {
                level[l] = 0;
                q.push(l);
            }
            else level[l] = -1;
        }

        bool flag = false;
        while (!q.empty()) {
            int l = q.front();
            q.pop();
            for (auto r : adj[l]) {
                if (!~matchR[r]) flag = true;
                else if (!~level[matchR[r]]) {
                    level[matchR[r]] = level[l] + 1;
                    q.push(matchR[r]);
                }
            }
        }
        return flag;
    };

    bool dfs(int l) {
        for (auto r : adj[l]) if (checkedR[r] != trueValue) {
            checkedR[r] = trueValue;
            if (!~matchR[r] || level[matchR[r]] == level[l] + 1 && dfs(matchR[r])) {
                matchL[l] = r;
                matchR[r] = l;
                return true;
            }
        }
        return false;
    }

public:
    BipartiteGraph(int n1, int n2) : n1(n1), n2(n2), adj(n1 + 1), matchL(n1 + 1, -1), matchR(n2 + 1, -1), checkedR(n2 + 1, 0), level(n1 + 1) {}

    void addEdge(int l, int r) { // 1-based
        adj[l].push_back(r);
    }

    int bipartiteMatching() { // Hopcroft-Karp
        int res = 0;
        
        trueValue = 1;
        while (bfs()) {
            for (int l = 1; l <= n1; l++) res += (!~matchL[l] && dfs(l));
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
[빠른 플로우 알고리즘이 필요한 문제들 - koosaga](https://www.acmicpc.net/workbook/view/882)   

### 참고링크
https://m.blog.naver.com/kks227/220816033373   
https://gazelle-and-cs.tistory.com/35   
https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm   