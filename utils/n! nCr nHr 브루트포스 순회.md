[카테고리](/README.md)
## 경우의 수 브루트포스 순회
### n! brute force
```cpp
vector<int> idx(n);
iota(idx.begin(), idx.end(), 0);

int cnt = 0;
do {
    for (int i = 0; i < n; i++) {
        // v[i]대신 v[idx[i]]로 접근
    }
} while (next_permutation(idx.begin(), idx.end()));
```

### nCr brute force
```cpp
vector<bool> select(n, false);
fill(select.begin(), select.begin() + r, true);

do {
    for (int i = 0; i < n; i++) if (selected[i]) {
        // v[i] 사용
    }
} while (prev_permutation(select.begin(), select.end()));
```
초기배열이 내림차순이므로 prev_permutation() 사용

### nHr brute force
```cpp
vector<int> tmp(n + r - 1, 0);
fill(tmp.begin(), tmp.begin() + r, 1);

do {
    vector<int> count(n, 0);
    int idx = 0;

    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] == 1) ++count[idx];
        else ++idx;
    }

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        // v[i]를 count[i]개씩 사용
    }
} while (prev_permutation(tmp.begin(), tmp.end()));
```
nHr을 prev_permutation으로 구현할 경우 tmp배열에서 count배열을 계산하는 과정에서 n+r-1Cr의 시간복잡도에 추가로 (n+r-1)이 곱해짐   
따라서 그냥 백트래킹이 더 낫지 않나 싶을수도 있지만,   
애초에 브루트포스 문제로 만들어낸 조합을 출력만 해도 O(N)씩은 곱해지는거라 O(N)에 O(n+r-1)더해진다고 생각하면 전체 시간복잡도에는 차이가 없음   
무엇보다 재귀함수 없어서 디버깅하기도 좀 더 편함   