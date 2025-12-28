[카테고리](/README.md)
## 문자열 압축
### pair\<char, int\>
```cpp
vector<pair<char, int> > compress(const string &st) {
    vector<pair<char, int> > res;
    int n = st.length();
    
    for (int i = 0, j; i < n; i = j) {
        j = i + 1;
        while (j < n && st[i] == st[j]) ++j;
        res.emplace_back(st[i], j - i);
    }
    
    return res;
}
```
### pair\<int\>
```cpp
vector<int> compress(const string &st) {
    vector<int> res;
    int n = st.size();
    
    for (int i = 0, j; i < n; i = j) {
        j = i + 1;
        while (j < n && st[i] == st[j]) ++j;
        res.push_back(j - i);
    }

    return res;
}
```