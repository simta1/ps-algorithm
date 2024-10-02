[카테고리](/README.md)
## Dinic (Dinitz)
```cpp
template <bool directed, typename F>
class Graph {
private:
    struct Edge {
        int next;
        F cap, flow;
        int rev; // reverseEdgeIdx;
        
        Edge(int next, F cap, int rev) : next(next), cap(cap), flow(0), rev(rev) {}
    };
    
    F INF;
    int n, proxySource;
    vector<vector<Edge> > adj;
    vector<int> level, work;

    bool bfs(int s, int e) { // level graph
        fill(level.begin(), level.end(), -1);

        queue<int> q;
        q.push(s);
        level[s] = 0;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto [next, cap, flow, rev] : adj[cur]) if (!~level[next] && flow < cap) {
                level[next] = level[cur] + 1;
                q.push(next);
            }
        }

        return ~level[e];
    };

    F dfs(int cur, int e, F fflow) {
        if (cur == e) return fflow;
        
        for (int &i = work[cur]; i < adj[cur].size(); i++) {
            auto [next, cap, flow, rev] = adj[cur][i];
            if (level[next] == level[cur] + 1 && flow < cap) {
                F df = dfs(next, e, min(fflow, cap - flow));
                if (df > 0) {
                    adj[cur][i].flow += df;
                    adj[next][rev].flow -= df;
                    return df;
                }
            }
        }

        return 0;
    }
        
public:
    Graph(int n) : n(n), proxySource(n + 1), adj(n + 2), level(n + 2), work(n + 2) {
        INF = numeric_limits<F>::max();
    }
    
    void addEdge(int a, int b, F cap = 1) { // 1-based
        if (cap == -1) cap = INF;
        
        adj[a].push_back(Edge(b, cap, adj[b].size()));
        if constexpr (directed) adj[b].push_back(Edge(a, 0, adj[a].size() - 1)); // 단방향 간선일 때 residual graph
        else adj[b].push_back(Edge(a, cap, adj[a].size() - 1)); // 무방향 간선일 때 residual graph
    }

    F maxFlow(int s, int e) { // 1-based // Dinic
        // proxySource -> s 단방향 연결
        adj[proxySource].push_back(Edge(s, INF, adj[s].size()));
        adj[s].push_back(Edge(proxySource, 0, adj[proxySource].size() - 1));

        // Dinic
        F res = 0;
        
        while (bfs(proxySource, e)) {
            fill(work.begin(), work.end(), 0);

            while (1) {
                F f = dfs(proxySource, e, INF);
                if (f == 0) break;
                res += f;
            }
        }

        // proxySOurce -> s 연결 제거
        adj[proxySource].pop_back();
        adj[s].pop_back();

        return res != INF ? res : -1;
    }
};
```
### 정점분할
```cpp
template <bool directed, typename F>
class VertexSplitedGraph {
private:
    Graph<true, F> graph;
    
    int in(int a) { return 2 * a - 1; } // 1-based
    int out(int a) { return 2 * a; } // 1-based

public:
    VertexSplitedGraph(int n) : graph(2 * n) {
        for (int i = 1; i <= n; i++) graph.addEdge(in(i), out(i), 1); // 각 정점 지날 수 있는 횟수 // k번까지 지날 수 있다면 1 대신 k 사용
    }

    void addEdge(int a, int b, F cap = 1) { // 1-based
        graph.addEdge(out(a), in(b), cap);
        if constexpr (!directed) graph.addEdge(out(b), in(a), cap);
    }

    F maxFlow(int s, int e) { // 1-based
        return graph.maxFlow(out(s), in(e));
    }
};
```
### 시간복잡도 
$O(V^2 E)$   

### 구현 주의사항
>`vector<vector<F>>`로 cap, flow를 2차원 배열에 저장하는 건 가끔 n 엄청 큰 문제에서 메모리 초과날 때 있어서 별로임   
그렇다고 map 쓰기엔 꽤 느려서 그냥 Edge구조체에 같이 저장하는 게 가장 나은 듯 함   

> 무한간선이 포함된 그래프일 경우 최대유량 구할 때 INF에 다른 수가 더해지면서 오버플로우 날 가능성이 있음   
이를 방지하고자 proxySource를 선언한뒤 proxySource -> e로 무한간선 하나를 이어준 뒤 proxySource -> sink로의 최대유량을 계산함   
이러면 애초에 유량이 inf를 초과해서 흐를 수 없으므로 오버플로우 날 수가 없음

### 사용설명
> 무한간선이라면 addEdge(a, b, -1) 사용
maxFlow(s, e)는 최대유량이 무한하다면 -1 리턴함

> 정점분할의 경우 각 정점을 1번만 방문 가능한 경우를 기준으로 코드 짬. 방문 제한 횟수가 k번이라면 `VertexSplitedGraph::addEdge()`에서 1 대신 k 사용(주석 참고)

### 문제
[도시 왕복하기 1](https://www.acmicpc.net/problem/17412) - 단방향 간선   
[간선 끊어가기 2](https://www.acmicpc.net/problem/14286) - 양방향 간선   
[도시 왕복하기 2](https://www.acmicpc.net/problem/2316) - 양방향 간선, 정점분할   
[학교 가지마!](https://www.acmicpc.net/problem/1420) - 양방향 간선, 정점분할, 무한간선   

### 참고링크
https://blog.naver.com/PostView.naver?blogId=jqkt15&logNo=222070243236&categoryNo=51&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView&userTopListOpen=true&userTopListCount=5&userTopListManageOpen=false&userTopListCurrentPage=1&photoView=5   
https://blog.naver.com/kks227/220812858041   
https://www.crocus.co.kr/1088   