[카테고리](/README.md)
### Floyd-Warshall
```cpp
template <typename T>
class Graph {
private:
    int n;
    const T INF;
    vector<vector<T> > dist;

public:
    Graph(int n) : n(n), INF(numeric_limits<T>::max() >> 1), dist(n + 1, vector<T>(n + 1, INF)) {
        for (int i = 1; i <= n; i++) dist[i][i] = 0;
    }

    void addEdge(int u, int v, T w) { // 1-based
        dist[u][v] = min(dist[u][v], w);
        // dist[v][u] = min(dist[v][u], w);
    }

    bool floydWarshall() {
        for (int m = 1; m <= n; m++) {
            for (int s = 1; s <= n; s++) {
                for (int e = 1; e <= n; e++) {
                    dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (dist[i][i] < 0) return false;
        }
        
        return true;
    }
};
```
### 시간복잡도 
시간복잡도 O(V^3)   
음수 가중치 존재 시에도 사용 가능

### 주의사항
dist[s][m] + dist[m][e]를 계산할 때 overflow를 방지하려면 INF는 numeric_limits::max() / 2 이하의 값 사용   

### 사용관련
간선이 양방향일 경우 addEdge()에서 주석 해제   
floydWarshall()는 음수 간선 순환 발생 시(비용을 무한히 줄일 수 있는 경우) false 리턴   

### 백준문제
[플로이드](https://www.acmicpc.net/problem/11404)