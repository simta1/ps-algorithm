[카테고리](/README.md)
### DisjointSet (path compression)
```cpp
class DisjointSet { // path compression only
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
### DisjointSet (path compression + union by rank)
```cpp
class DisjointSet { // path compression + union by rank
private:
    vector<int> parent, rank;

    int find(int a) {
        if (parent[a] != a) parent[a] = find(parent[a]);
        return parent[a];
    }

public:
    DisjointSet(int n) : parent(n + 1), rank(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (rank[a] > rank[b]) swap(a, b);
        parent[a] = b;
        rank[b] += rank[a] == rank[b];
    }

    bool isConnected(int a, int b) {
        return find(a) == find(b);
    }
};
```
### 시간복잡도 
$O(\alpha(N))$   
$\alpha$는 inverse Ackermann function으로 아무리 커도 O(4)정도로 생각하면 된다. 대충 2↑↑(n + 3)의 역함수다.

### 주의사항
find(int a)에서
return a;하면 안 된다.
return a;하고 싶으면 if문 안에서도 리턴해야된다.
```cpp
if (parent[a] != a) return parent[a] = find(parent[a]);
return a;
```

union by rank를 추가할 경우 merge함수에서 if (a == b) return;이 포함되어야 된다. path compression만 있을 때는 a == b여도 상관없지만, union by rank를 사용하는 경우 이후 rank를 업데이트하는 과정이 있으므로 if (a == b) return;을 해야 rank가 효율적으로 계산된다.   

### 사용관련
솔직히 rank by union 안 쓰고 path compression만 해도 시간이 비슷하게 나온다. 오히려 rank by union쓰면 메모리만 2배로 쓰고 코드만 길어지기에 웬만하면 path compression만 사용하는 게 나은 듯 싶다.
예외적으로 rollback이 필요한 경우엔 path compression을 사용할 수 없어 rank by union를 쓴다.

int cnt = 0;을 선언한 뒤 merge호출 될 때마다 cnt += !isConnected()로 몇 번 합쳐졌는지 계산해 두면 (n - cnt)로 집합의 개수도 알 수 있다.

### 백준문제
[집합의 표현](https://www.acmicpc.net/problem/1717)

### 시간복잡도 관련..
path compression만 해도 시간복잡도 O(1)아닌가 싶었는데 착각이었다. path compression만 했을 때 시간복잡도 확인용 코드.
```cpp
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    int cnt;

    int _find(int a) {
        ++cnt;
        if (parent[a] != a) parent[a] = _find(parent[a]);
        return parent[a];
    }

public:
    DisjointSet(int n) : parent(n + 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int a) {
        cnt = 0;
        int res = _find(a);
        cout << "find(" << a << ") : " << cnt << "\n";
        return res;
    }

    void merge(int a, int b) {
        parent[find(a)] = find(b);
    }

    bool isConnected(int a, int b) {
        return find(a) == find(b);
    }
};


int main() {
    int n = 10;
    DisjointSet ds(n);

    for (int i = 1; i < n; ++i) ds.merge(i - 1, i);

    ds.find(0); // 10 출력됨, worst-case에서 find()함수가 O(N)되는 상황 존재
    ds.find(0); // 2 출력됨, 두번째 호출부턴 경로압축되어 빨라짐

    return 0;
}
```