[카테고리](/README.md)
## permutation
### prev_permutation, next_permutation
next방향으로 갈수록 내림차순

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