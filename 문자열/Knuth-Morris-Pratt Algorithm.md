[카테고리](/README.md)
### KMP
```cpp
vector<int> kmp(string st, string pattern) {
    int n = st.size();
    int m = pattern.size();

    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) j = pi[j - 1];
        if (pattern[i] == pattern[j]) pi[i] = ++j;
    }
    
    vector<int> res;
    for(int i = 0, j = 0; i < n; i++){
        while(j > 0 && st[i] != pattern[j]) j = pi[j - 1];
        if (st[i] == pattern[j]) {
            if(j == m - 1) {
                res.push_back(i - m + 1);
                j = pi[j];
            }
            else ++j;
        }
    }
    
    return res;
}
```
### 시간복잡도 
$O(N+M)$   
N, M은 각각 text, pattern의 길이

### 백준문제
[찾기](https://www.acmicpc.net/problem/1786)