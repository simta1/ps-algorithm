[카테고리](/README.md)
### DisjointSet
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
### DisjointSet (countSets 추가)
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

    void merge(int a, int b) { // 1-based
        a = find(a);
        b = find(b);

        if (a < b) swap(a, b);
        parent[a] = b;
    }

    bool isConnected(int a, int b) { // 1-based
        return find(a) == find(b);
    }

    int countSets() { // 1-based
        int cnt = 0;
        for (int i = 1; i < parent.size(); i++) cnt += (parent[i] == i);
        return cnt;        
    }
};
```
### 시간복잡도 
$O(\alpha(N))$   
$\alpha$는 inverse Ackermann function으로 O(4)정도로 생각하면 된다. 대충 2↑↑(n + 3)의 역함수다.

### 주의사항
countSets 쓸 때는 merge에서 if (a < b) swap(a, b);가 필요하다. 버리는 값으로 0을 사용하고 merge(0, x)을 할 때 parent[0] = x가 되어 countSets의 값이 실제보다 1 커지는 경우를 막는다.

### 사용관련
이전에 왜 저렇게 countSets()를 구현했는지 모르겠는데 그냥 cnt=0으로 한 뒤 merge호출 될 때마다 cnt += !isConnected()로 몇 번 합쳐졌는지 계산해 두면 n - cnt로 알 수 있다. 그래도 혹시 언젠가 필요할 지도 모르니 이전에 적어놓은 코드도 안 지우고 남겨뒀다.   

### 백준문제
[집합의 표현](https://www.acmicpc.net/problem/1717)