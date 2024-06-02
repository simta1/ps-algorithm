[카테고리](/README.md)
### Bipartite Matching
```cpp
class BipartiteGraph {
private:
    vector<vector<int> > adj;
    vector<int> visited, assign;
    int trueValue;

    bool dfs(int person) {
        for (int &work : adj[person]) if (visited[work] != trueValue) {
            visited[work] = trueValue;
            if (!~assign[work] || dfs(assign[work])) {
                assign[work] = person;
                return true;
            }
        }
        return false;
    }

public:
    BipartiteGraph(int n1, int n2) : adj(n1 + 1), visited(n2 + 1, 0), assign(n2 + 1, -1) {}

    void addEdge(int a, int b) { // 1-based
        adj[a].push_back(b);
    }

    int bipartiteMatching() {
        int res = 0;
        trueValue = 1;
        for (int i = 1; i < adj.size(); i++, trueValue++) res += dfs(i);
        return res;
    }
};
```
### 시간복잡도 
$O(VE)$   

### 주의사항
trueValue = 1을 for문 안에 써서 for (int i = 1, trueValue = 1, ... ) 로 하면 안 된다.   
클래스 멤버 trueValue와 별개의 또 다른 trueValue가 된다.    

### 사용관련
n1, n2는 이분 그래프의 각 부분의 개수   

### 백준문제
[열혈강호](https://www.acmicpc.net/problem/11375)