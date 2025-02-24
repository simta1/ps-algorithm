[카테고리](/README.md)
## small to large
```cpp
template <typename T>
class SmallToLarge {
private:
    vector<set<T> > sets;
    vector<int> idx;

public:
    SmallToLarge(int n) : sets(n + 1), idx(n + 1) { iota(idx.begin(), idx.end(), 0); }
    set<T>& operator[](int a) { return sets[idx[a]]; }
    const set<T>& operator[](int a) const { return sets[idx[a]]; }

    void merge(int a, int b) { // b에 있는 걸 a로 옮기고 b는 공집합으로 만듦
        int &i = idx[a];
        int &j = idx[b];
        if (i == j) return;

        if (sets[i].size() < sets[j].size()) swap(i, j);
        sets[i].insert(sets[j].begin(), sets[j].end());
        sets[j].clear();
    }
};
```
### 시간복잡도
$b$집합의 모든 원소를 $a$집합으로 옮기는 `merge(a, b)`의 시간복잡도는 $O(min(a, b))$   

집합 $k$개가 있고 초기집합들에 존재하는 원소의 총 개수가 $N$이라 할 때 두 집합을 합치는 연산을 $(k - 1)$번 진행해 한 집합으로 합치기 위해선 $O(N \log{N})$번의 원소 이동이 필요하다.   

### 사용설명
[뭉쳐야 산다](https://www.acmicpc.net/problem/28277) 예시코드
```cpp
// ex) https://www.acmicpc.net/problem/28277 풀이
SmallToLarge<int> stol(n);
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
        stol.merge(a, b);
    }
    else {
        int a;
        cin >> a;
        cout << stol[a].size() << "\n";
    }
}
```

### 문제
[뭉쳐야 산다](https://www.acmicpc.net/problem/28277)   

### 원리
작은 집합의 원소를 큰 집합으로 이동시키기 때문에, 어떤 원소가 집합이 합쳐지면서 다른 집합으로 이동했을 경우 그 원소가 속한 집합의 크기는 2배 이상으로 증가   
따라서 각각의 원소는 최대 $\log{N}$번 다른 집합으로 이동   
원소의 수가 총 $N$개라면 집합을 전부 합치기까지 원소의 이동은 총 $O(N \log{N})$번 발생   

### 참고링크
https://00ad-8e71-00ff-055d.tistory.com/197   