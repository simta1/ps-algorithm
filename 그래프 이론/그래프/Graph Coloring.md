[카테고리](/README.md)
### Graph Coloring
```cpp
class Graph {
private:
    int n;
    vector<vector<int> > adj;
    vector<int> colors;

    bool valid(int cur, int color) {
        for (auto next : adj[cur]) {
            if (colors[next] == color) return false;
        }

        return true;
    }

    bool canColor(int k, int cur, int color) {
        if (!valid(cur, color)) return false;
        colors[cur] = color;

        if (cur == n) return true;

        for (int i = 0; i < k; i++) {
            if (canColor(k, cur + 1, i)) return true;
        }

        colors[cur] = -1;
        return false;
    };


public:
    Graph(int n) : n(n), adj(n + 1), colors(n + 1, -1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int getChromaticNumber() {
        int res = 1;
        while (!canColor(res, 1, 0)) res++;
        return res;
    }
};
```
### 시간복잡도 
canColor(k) : $k^{n - 1}$ + 백트래킹

### 주의사항
colors[cur] = -1; 백트래킹 까먹으면 안 됨

### 백준문제
[Coloring Graphs](https://www.acmicpc.net/problem/24782)   

### 참고문헌
https://www.geeksforgeeks.org/graph-coloring-applications/   
https://dad-rock.tistory.com/692   

### 비슷하지만 훨씬 느린 코드
색칠을 시작하는 정점에 대해서는 한가지 색깔만 확인해봐도 되는데 아래 코드는 시작 정점에 대해서도 k개의 색깔을 모두 확인하므로 시간복잡도 $k^n$ + 백트래킹이 되서 훨씬 느리다.   
```cpp
class Graph {
private:
    int n;
    vector<vector<int> > adj;
    vector<int> colors;

    bool valid(int cur, int color) {
        for (auto next : adj[cur]) {
            if (colors[next] == color) return false;
        }

        return true;
    }

    bool canColor(int k, int cur) {
        if (cur == n + 1) return true;

        for (int color = 0; color < k; color++) if (valid(cur, color)) {
            colors[cur] = color;
            if (canColor(k, cur + 1)) return true;
        }
        colors[cur] = -1;

        return false;
    };


public:
    Graph(int n) : n(n), adj(n + 1), colors(n + 1, -1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    int getChromaticNumber() {
        int res = 1;
        while (!canColor(res, 1)) res++;
        return res;
    }
};
```