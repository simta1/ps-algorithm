[카테고리](/README.md)
## z
```cpp
template <typename Container> // Container = string or vector<>
vector<int> getZ(const Container &st) {
    vector<int> z(st.size());
    for (int i = 1, p = 0; i < st.size(); ++i) { // p는 0<=j<i인 j들 중 j + z[j] - 1가 가장 큰 j
        if (i <= p + z[p] - 1) z[i] = min(p + z[p] - 1 - i + 1, z[i - p]);
        while (i + z[i] < st.size() && st[z[i]] == st[i + z[i]]) ++z[i];
        if (p + z[p] - 1 < i + z[i] - 1) p = i;
    }
    z[0] = st.size();
    return z;
} // z[i] = lcp(st, st[i:])
```
### 시간복잡도
$O(N)$   

### 문제
[문자열과 쿼리](https://www.acmicpc.net/problem/13713)   

### 참고링크
https://sgc109.tistory.com/208   