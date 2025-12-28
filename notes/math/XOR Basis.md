[카테고리](/README.md)
## XOR Basis
```cpp
template <typename T>
vector<T> getXorBasis(const vector<T> &v) {
    vector<T> basis;
    for (auto e : v) {
        for (auto b : basis) e = min(e, e ^ b);
        if (e) basis.push_back(e);
    }
    return basis;
}

template <typename T>
T getMaxXorSum(const vector<T> &v) {
    T res = 0;
    for (auto b : getXorBasis(v)) res = max(res, res ^ b);
    return res;
}
```

### 시간복잡도
$O(KN)$   
K는 비트 수: int면 4, long long이면 8   

### 문제
[Xor Maximization](https://www.acmicpc.net/problem/11191)   

### 참고링크
https://velog.io/@dnr6054/Subset-XOR-Maximization   
https://www.geeksforgeeks.org/xor-basis-algorithm/   
https://koosaga.com/132   