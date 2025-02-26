[카테고리](/README.md)
## Small To Large
```cpp
template <typename Container>
class SmallToLarge {
private:
    vector<Container> sets;
    vector<int> idx;

public:
    SmallToLarge(int n) : sets(n + 1), idx(n + 1) { iota(idx.begin(), idx.end(), 0); }
    Container& operator[](int a) { return sets[idx[a]]; } // 1-based
    const Container& operator[](int a) const { return sets[idx[a]]; } // 1-based

    void moveElements(int from, int to) { // 1-based // from에 있는 걸 to로 옮기고 from은 공집합으로 만듦
        int &i = idx[to];
        int &j = idx[from];
        if (i == j) return;

        if (sets[i].size() < sets[j].size()) swap(i, j);
        
        if constexpr (std::is_same_v<Container, set<typename Container::value_type> >) {
            sets[i].insert(sets[j].begin(), sets[j].end()); // Container가 set인 경우
        }
        else if constexpr (std::is_same_v<Container, map<typename Container::key_type, typename Container::mapped_type> >) {
            for (auto &[key, val] : sets[j]) sets[i][key] += val; // Container가 map인 경우
        }
        else {
            // sets[j]의 원소를 sets[i]로 옮기기
            assert(false); // Container가 set, map이 아닌 경우 assert(false)지우고 직접 원소 옮기는 코드 작성
        }

        sets[j].clear();
    }
};
```
### Small To Large + [DSU](/자료구조/기타/DSU.md)
```cpp
template <typename Container>
class SmallToLargeWithDSU : public DisjointSet, public SmallToLarge<Container> {
public:
    SmallToLargeWithDSU(int n) : DisjointSet(n), SmallToLarge<Container>(n) {}

    Container& operator[](int a) {
        return SmallToLarge<Container>::operator[](find(a));
    }
    // const Container& operator[](int a) const는 find(a)가 const가 아니라서 못 함

    void merge(int a, int b) { // a와 b를 하나로 합침, 이후 a와 b에 접근하면 합쳐진 곳으로 접근됨
        if (!isConnected(a, b)) {
            SmallToLarge<Container>::moveElements(find(a), find(b));
            DisjointSet::merge(b, a); // smallToLarge::moveElements()와 매개변수 순서를 반대로 둬야 함. b에서 a로 원소를 옮기므로 이후 find()함수가 a를 리턴하도록 해야 되고 이를 위해선 DSU::merge(b, a)처럼 순서가 바껴야 됨
        }
    }
};
```
### 시간복잡도
$b$집합의 모든 원소를 $a$집합으로 옮기는 `moveElements(a, b)`는 $O(min(a, b))$번의 원소 이동이 필요. (`SmallToLargeWithDSU::merge(a, b)`도 마찬가지)   

집합 $k$개가 있고 초기집합들에 존재하는 원소의 총 개수가 $N$이라 할 때 두 집합을 합치는 연산을 $(k - 1)$번 진행해 한 집합으로 합치기 위해선 $O(N \log{N})$번의 원소 이동이 필요.   

원소이동의 시간복잡도는 Container에 따라 달라지겠지만 `set<T>` 사용할 때 기준 원소 이동의 시간복잡도는 $O(\log{N})$임   

### 사용설명
[뭉쳐야 산다](https://www.acmicpc.net/problem/28277) 예시코드   
```cpp
// ex) https://www.acmicpc.net/problem/28277 풀이
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, q;
    cin >> n >> q;
    
    SmallToLarge<set<int> > stol(n);
    for (int i = 1; i <= n; i++) {
        int m, x;
        for (cin >> m; m-- && cin >> x;) stol[i].insert(x);
    }
    
    while (q--) {
        int op;
        cin >> op;
        
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            stol.moveElements(b, a);
        }
        else {
            int a;
            cin >> a;
            cout << stol[a].size() << "\n";
        }
    }
    
    return 0;
}
```

### 문제
[뭉쳐야 산다](https://www.acmicpc.net/problem/28277)   
[트리의 색깔과 쿼리](https://www.acmicpc.net/problem/17469) - Small To Large + DSU   
[물류창고](https://www.acmicpc.net/problem/28296) - Small To Large + DSU(여기선 SmallToLarge를 set대신 map으로 구현)   

### 원리
작은 집합의 원소를 큰 집합으로 이동시키기 때문에, 어떤 원소가 집합이 합쳐지면서 다른 집합으로 이동했을 경우 그 원소가 속한 집합의 크기는 2배 이상으로 증가   
따라서 각각의 원소는 최대 $\log{N}$번 다른 집합으로 이동   
원소의 수가 총 $N$개라면 집합을 전부 합치기까지 원소의 이동은 총 $O(N \log{N})$번 발생   

### 참고링크
https://00ad-8e71-00ff-055d.tistory.com/197   