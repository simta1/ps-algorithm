[카테고리](/README.md)
### Permutation Cycle Decomposition
```cpp
class PermutationCycleDecomposition {
private:
    vector<int> adj;
    
    int trueValue;
    vector<int> visited;

    vector<int> cyclesPos, cyclePos;
    vector<vector<int> > cycles;
    vector<int> cycle;

public:
    PermutationCycleDecomposition(const vector<int> &v) : adj(v), trueValue(0), visited(v.size()), cyclesPos(v.size()), cyclePos(v.size()) {} // 0-based

    void updateSwap(int a, int b) { // 0-based
        swap(adj[a], adj[b]);
    }

    void init() {
        cycles.clear();
        ++trueValue;

        for (int i = 0; i < adj.size(); i++) if (visited[i] != trueValue) {
            cycle.clear();
            for (int cur = i; visited[cur] != trueValue; cur = adj[cur]) {
                visited[cur] = trueValue;
                cyclesPos[cur] = cycles.size();
                cyclePos[cur] = cycle.size();
                cycle.push_back(cur);
            }
            cycles.push_back(cycle);
        }
    }

    int query(int idx, int n) { // 0-based, f^n(idx)
        const auto &cycle = cycles[cyclesPos[idx]];
        return cycle[(cyclePos[idx] + n) % cycle.size()];
    }
};
```
### 시간복잡도 
$O(N)$   

### 구현설명
vector cycle은 init()에서 cycles만들 때 사용하는 임시 배열   
init() 함수 안에서 선언해도 되지만 [순열 사이클과 쿼리](https://www.acmicpc.net/problem/27878) 처럼 init() 많이 해야되는 경우에는 array doubling으로 인한 시간이 생각보다 엄청 커져서 그냥 필드에 선언함

### 백준문제
[순열 사이클](https://www.acmicpc.net/problem/10451)   
[순열 사이클과 쿼리](https://www.acmicpc.net/problem/27878)   