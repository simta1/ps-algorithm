[카테고리](/README.md)
### MST
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int cost, s, e;

    Edge(int cost, int s, int e) : cost(cost), s(s), e(e) {}
};

struct Compare {
    bool operator()(const Edge &bottom, const Edge &top) const {
        return bottom.cost > top.cost;
    }
};

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

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    priority_queue<Edge, vector<Edge>, Compare> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push(Edge(c, a, b));
    }

    DisjointSet ds(n + 1);
    int ans = 0;

    while (!edges.empty()) {
        auto [cost, u, v] = edges.top();
        edges.pop();
        
        if (!ds.isConnected(u, v)) {
            ds.merge(u, v);
            ans += cost;
        }
    }

    cout << ans;
    return 0;
}
```
어차피 edge들만 저장하면 되는데 Graph 클래스까지 만들기 귀찮다.   
언젠간 리팩토링해서 다시 올리지 않을까

### 시간복잡도 
$O(N~logN)$   

### 백준문제
[최소 스패닝 트리](https://www.acmicpc.net/problem/1197)