[카테고리](/README.md)
## String Compression $O(N)$
### pair\<char, int\>
```cpp
vector<pair<char, int> > compress(const string &st) {
    vector<pair<char, int> > res;
    int n = st.length();
    
    for (int i = 0; i < n;) {
        char ch = st[i];
        int cnt = 0;
        while (i < n && st[i] == ch) ++cnt, ++i;
        res.push_back({ch, cnt});
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
        char ch = st[i];
        int cnt = 0;
        while (i < n && st[i] == ch) ++cnt, ++i;
        res.push_back(cnt);
    }
    
    return res;
}
```