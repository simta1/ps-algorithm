[카테고리](/README.md)
## Hopcroft-Karp
```cpp
class BipartiteGraph {
private:
    int n1, n2;
    vector<vector<int> > adj;
    vector<int> matchL, matchR, level, adjStartIdx;

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
                if (!~matchR[r]) flag = true; // return true; 하면 안 됨 (level배열 전부 계산하기 전에 return하면 안되니까)
                else if (!~level[matchR[r]]) {
                    level[matchR[r]] = level[l] + 1;
                    q.push(matchR[r]);
                }
            }
        }
        return flag;
    };

    bool dfs(int l) {
        for (int &i = adjStartIdx[l]; i < adj[l].size(); i++) {
            int r = adj[l][i];
            if (!~matchR[r] || level[matchR[r]] == level[l] + 1 && dfs(matchR[r])) {
                matchL[l] = r;
                matchR[r] = l;
                return true;
            }
        }
        return false;
    }

public:
    BipartiteGraph(int n1, int n2) : n1(n1), n2(n2), adj(n1 + 1), matchL(n1 + 1, -1), matchR(n2 + 1, -1), level(n1 + 1), adjStartIdx(n1 + 1) {}

    void addEdge(int l, int r) { // 1-based
        adj[l].push_back(r);
    }

    int bipartiteMatching() { // Hopcroft-Karp
        int res = 0;
        
        while (bfs()) {
            fill(adjStartIdx.begin(), adjStartIdx.end(), 0);
            for (int l = 1; l <= n1; l++) res += (!~matchL[l] && dfs(l));
        }

        return res;
    }

    pair<vector<int>, vector<int> > minimumVertexCover() {
        bipartiteMatching();
        
        vector<bool> visitedL(n1 + 1), visitedR(n2 + 1);
        function<void(int)> visit = [&](int l) {
            visitedL[l] = true;

            for (auto r : adj[l]) if (~matchR[r] && !visitedR[r] && !visitedL[matchR[r]]) {
                visitedR[r] = true;
                visit(matchR[r]);
            }
        };
        
        for (int l = 1; l <= n1; l++) if (!~matchL[l]) visit(l);
        
        vector<int> mvcL, mvcR;
        for (int l = 1; l <= n1; l++) if (!visitedL[l]) mvcL.push_back(l);
        for (int r = 1; r <= n2; r++) if (visitedR[r]) mvcR.push_back(r);
        return {mvcL, mvcR};
    }

    pair<vector<bool>, vector<bool> > getIsMvc() {
        vector<bool> isMvcL(n1 + 1, 1), isMvcR(n2 + 1);
        function<void(int)> visit = [&](int l) {
            isMvcL[l] = false;

            for (auto r : adj[l]) if (~matchR[r] && !isMvcR[r] && isMvcL[matchR[r]]) {
                isMvcR[r] = true;
                visit(matchR[r]);
            }
        };
        
        for (int l = 1; l <= n1; l++) if (!~matchL[l]) visit(l);
        
        return {isMvcL, isMvcR};
    }
};
```
### 시간복잡도
$O(E \sqrt V)$   

### 구현 주의사항
`dfs()`함수에서 디닉에서 했던 것처럼 adjStartIdx[l] 배열 사용해서 방문체크 반드시 해야 함.   
안할 경우 [$O(VE)$ 이분매칭](/그래프%20이론/네트워크%20플로우/이분매칭.md)보다 느려지는 반례 존재
```cpp
// 엄청 느린 코드
bool dfs(int l) {
    for (auto r : adj[l]) {
    // ...

// 맞는 코드
bool dfs(int l) {
    for (int &i = adjStartIdx[l]; i < adj[l].size(); i++) {
        int r = adj[l][i];
        // ...
```


### 문제
[System Engineer](https://www.acmicpc.net/problem/3736)   
[Garden](https://www.acmicpc.net/problem/20252)   
[등번호](https://www.acmicpc.net/problem/1733) - 호프크로프트 카프 빠른 구현체로 풀린다는데 10% 시간초과로 아직 못품, 이상하게도 오히려 [`O(VE) 이분매칭`](/그래프%20이론/네트워크%20플로우/이분매칭.md)쓰면 32%까지 감   
[범죄 파티](https://www.acmicpc.net/problem/13166) - [`O(VE) 이분매칭`](/그래프%20이론/네트워크%20플로우/이분매칭.md)이 호프크로프트보다 빠름.. 왜일까   
[빠른 플로우 알고리즘이 필요한 문제들 - koosaga](https://www.acmicpc.net/workbook/view/882)   

### 참고링크
https://m.blog.naver.com/kks227/220816033373   
https://gazelle-and-cs.tistory.com/35   
https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm   