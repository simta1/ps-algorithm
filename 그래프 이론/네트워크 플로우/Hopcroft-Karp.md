[카테고리](/README.md)
## Hopcroft-Karp
```cpp
class BipartiteGraph {
private:
    vector<vector<int> > adj;
    vector<int> level, adjStartIdx, assign;
    vector<bool> used;

    void bfs() { // level graph
        queue<int> q;
        for (int i = 1; i < adj.size(); i++) {
            if (!used[i]) {
                level[i] = 0;
                q.push(i);
            }
            else level[i] = -1;
        }

        while (!q.empty()) {
            int person = q.front();
            q.pop();
            for (auto work : adj[person]) {
                if (~assign[work] && !~level[assign[work]]) {
                    level[assign[work]] = level[person] + 1;
                    q.push(assign[work]);
                }
            }
        }
    };

    bool dfs(int person) {
        for (int &i = adjStartIdx[person]; i < adj[person].size(); i++) {
            auto work = adj[person][i];
            if (!~assign[work] || level[assign[work]] == level[person] + 1 && dfs(assign[work])) {
                used[person] = true;
                assign[work] = person;
                return true;
            }
        }
        return false;
    }

public:
    BipartiteGraph(int n1, int n2) : adj(n1 + 1), level(n1 + 1), adjStartIdx(n1 + 1), used(n1 + 1, 0), assign(n2 + 1, -1) {}

    void addEdge(int a, int b) { // 1-based
        adj[a].push_back(b);
    }

    int bipartiteMatching() {
        int res = 0;
        
        while (1) {
            bfs();
            fill(adjStartIdx.begin(), adjStartIdx.end(), 0);

            int flow = 0;
            for (int i = 1; i < adj.size(); i++) flow += (!used[i] && dfs(i));
            if (flow == 0) break;
            res += flow;
        }

        return res;
    }
};
```
### 시간복잡도
$O(E \sqrt V)$   

### 구현 주의사항


### 사용설명


### 문제
[System Engineer](https://www.crocus.co.kr/744) - [`O(VE) 빠른 구현체`](/그래프%20이론/네트워크%20플로우/이분매칭.md)로도 풀리긴 한다.

### 참고링크
https://m.blog.naver.com/kks227/220816033373   
https://gazelle-and-cs.tistory.com/35   
https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm   