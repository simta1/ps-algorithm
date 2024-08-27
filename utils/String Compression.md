[카테고리](/README.md)
## 문자열 압축
### pair\<char, int\>
```cpp
vector<pair<char, int> > compress(const string &st) {
    vector<pair<char, int> > res;
    int n = st.length();
    
    for (int i = 0; i < n;) {
        int cnt = 0;
        while (i < n && st[i] == st[i]) ++cnt, ++i;
        res.push_back({st[i], cnt});
    }
    
    return res;
}
```
### pair\<int\>
```cpp
vector<int> compress(const string &st) {
    vector<int> res;
    int n = st.length();
    
    for (int i = 0; i < n;) {
        int cnt = 0;
        while (i < n && st[i] == st[i]) ++cnt, ++i;
        res.push_back(cnt);
    }
    
    return res;
}
```