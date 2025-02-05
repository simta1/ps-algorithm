[카테고리](/README.md)
## 2-SAT
```cpp
class CNF {
private:
    int n;
    vector<vector<int> > adj;
    vector<int> sccn;

    int getNode(int a) { // -1, 1, -2, 2, -3, 3, -4, 4, ... -> 1, 2, 3, 4, 5, 6, 7, 8, ...
        return abs(a) * 2 - (a < 0);
    }

    void findSCC() {
        vector<int> dfsn(2 * n + 1, 0);
        stack<int> s;

        int dfsi = 0, scci = 0;
        function<int(int)> dfs = [&](int cur) -> int {
            int low = dfsn[cur] = ++dfsi;
            s.push(cur);

            for (auto next : adj[cur]) if (!~sccn[next]) low = min(low, dfsn[next] ? dfsn[next] : dfs(next));

            if (low == dfsn[cur]) {
                while (1) {
                    int node = s.top();
                    s.pop();
                    sccn[node] = scci;
                    if (node == cur) break;
                }
                ++scci;
            }

            return low;
        };
        for (int i = 1; i <= 2 * n; i++) if (!dfsn[i]) dfs(i);

        for (int i = 1; i <= 2 * n; i++) sccn[i] = scci - 1 - sccn[i];
    }

public:
    CNF(int n) : n(n), adj(2 * n + 1), sccn(2 * n + 1, -1) {}

    void add2SAT(int a, int b) { // a or b가 true
        adj[getNode(-a)].push_back(getNode(b));
        adj[getNode(-b)].push_back(getNode(a));
    }

    // 전부 1-based
    void add1SAT(int a) { adj[getNode(-a)].push_back(getNode(a)); } // a가 true
    void addAtLeast2SAT(int a, int b, int c) { add2SAT(a, b); add2SAT(b, c); add2SAT(c, a); } // a, b, c 중 2개 이상이 true
    void addExactly1SAT(int a, int b) { add2SAT(a, b); add2SAT(-a, -b); } // a, b 중 정확히 하나만 true
    void addEqual2SAT(int a, int b) { add2SAT(a, -b); add2SAT(-a, b); } // a == b 가 true
    void addNotEqualSAT(int a, int b) { add2SAT(a, b); add2SAT(-a, -b); } // a != b 가 true
    void add22SAT(int a1, int a2, int b1, int b2) { add2SAT(a1, b1); add2SAT(a1, b2); add2SAT(a2, b1); add2SAT(a2, b2); } // (a1 and a2) or (b1 and b2)가 true
    void addNMSAT(const vector<int> &as, const vector<int> &bs) { for (auto &a : as) for (auto &b : bs) add2SAT(a, b); } // (a1 and a2 and ... and aN) or (b1 and b2 and ... and bM)가 true
    
    bool solve() {
        findSCC();
        for (int i = 1; i <= n; i++) if (sccn[getNode(i)] == sccn[getNode(-i)]) return false;
        return true;
    }

    bool getSolution(int i) { // 1-based
        return sccn[getNode(-i)] < sccn[getNode(i)]; // false -> true 꼴이 되어야 하므로 x가 true라면 !x -> x 
    }
};
```
### 시간복잡도 
$O(V + E)$   

### 표기
$\lor$은 OR, $\land$는 AND, $\lnot$은 NOT을 나타낸다.

### 사용설명
$a$가 true여야 한다면 `add1SAT(a)` 사용   
$a \lor b$가 true여야 한다면 `add2SAT(a, b)` 사용   
$a, b, c$ 중 2개 이상이 true여야 한다면 `addAtLeast2SAT(a, b, c)` 사용   
false, true는 각각 -, +부호로 표현   
```cpp
// (!x1 or x2) 
graph.add2SAT(-1, 2);

// (!x2 or !x3)
graph.add2SAT(-2, -3);
```
### 문제
[2-SAT - 4](https://www.acmicpc.net/problem/11281)   
[아이돌](https://www.acmicpc.net/problem/3648) - add2SAT, add1SAT    
[TV Show Game](https://www.acmicpc.net/problem/16367) - addAtLeast2SAT   
[막대기](https://www.acmicpc.net/problem/2519) - add2SAT, addAtLeast2SAT   

### 원리
false -> true 꼴이 되어야 함   
x -> !x 라면 x = false   
!x -> x 라면 x = true   
따라서 x가 true일 조건은 !x -> x   

$a, b, c$ 중 2개 이상이 true인 것은 $(a \lor b) \land (b \lor c) \land (c \lor a)$가 true인 것과 동치임   

### 참고링크
https://blog.leejseo.com/61   