[카테고리](/README.md)
##### [Disjoint Set](/자료구조/기타/Disjoint%20Set.md)
```cpp
class DisjointSet {
private:
    vector<int> parent;

    int find(int a) {
        if (parent[a] != a) parent[a] = find(parent[a]);
        return parent[a];
    }

public:
    DisjointSet(int n) : parent(n + 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    void merge(int a, int b) {
        parent[find(a)] = find(b);
    }

    bool isConnected(int a, int b) {
        return find(a) == find(b);
    }
};
```
### MST (Kruskal's algorithm)
```cpp
template <typename T>
class Graph {
private:
    struct Edge {
        int s, e;
        T cost;

        Edge(int s, int e, T cost) : s(s), e(e), cost(cost) {}
    };

    struct Compare {
        bool operator()(const Edge &bottom, const Edge &top) const {
            return bottom.cost > top.cost;
        }
    };

    int n;
    priority_queue<Edge, vector<Edge>, Compare> edges;

public:
    Graph(int n) : n(n) {}

    void addEdge(int u, int v, int w) {
        edges.push({u, v, w});
    }

    T MST() {
        T res = 0;
        DisjointSet ds(n + 1);

        while (!edges.empty()) {
            auto [u, v, cost] = edges.top();
            edges.pop();

            if (!ds.isConnected(u, v)) {
                ds.merge(u, v);
                res += cost;
            }
        }
        
        return res;
    }
};
```
### 시간복잡도 
$O(E~logE)$   

### 백준문제
[최소 스패닝 트리](https://www.acmicpc.net/problem/1197)   