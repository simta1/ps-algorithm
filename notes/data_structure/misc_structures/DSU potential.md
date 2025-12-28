[카테고리](/README.md)
## Union Find with Potential
```cpp
template <typename T>
class DisjointSet {
private:
    vector<int> parent;
    vector<T> weight;

    int find(int a) {
        if (parent[a] == a) return a;
        find(parent[a]); // calculate weight[parent[a]]
        weight[a] += weight[parent[a]];
        return parent[a] = find(parent[a]);
    }

public:
    DisjointSet(int n) : parent(n + 1), weight(n + 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    void merge(int a, int b, T w) { // b = a + w
        int ra = find(a);
        int rb = find(b);

        if (ra > rb) {
            swap(ra, rb);
            swap(a, b);
            w *= -1;
        }
        
        weight[rb] = weight[a] + w - weight[b];
        parent[rb] = ra;
    }

    bool isConnected(int a, int b) {
        return find(a) == find(b);
    }

    T getDiff(int a, int b) {
        return weight[b] - weight[a];
    }
};
```
### 시간복잡도
$O(\alpha(N))$   

### 구현 주의사항
`int find(int a)`함수에서 `find(parent[a])` 재귀호출하는 거 까먹으면 안 됨   


### 사용설명
!isConnected(a, b)라면 a와 b를 비교할 수 없음.
getDiff쓰기 전에 isConnected(a, b)인지 확인하고 써야 됨


### 문제
[교수님은 기다리지 않는다](https://www.acmicpc.net/problem/3830)   
[H. The Third Letter](https://codeforces.com/gym/552209/problem/H)   

### 참고링크
https://ioqoo.tistory.com/34   
https://cp-algorithms.com/data_structures/disjoint_set_union.html#support-distances-up-to-representative   
https://nyaannyaan.github.io/library/data-structure/union-find-with-potential.hpp.html   