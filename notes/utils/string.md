[카테고리](/README.md)
## 문자열 관련 utils
### trim
```cpp
string trim(const string &st) {
    size_t first = st.find_first_not_of(" \t\n\r");
    if (first == string::npos) return "";
    size_t last = st.find_last_not_of(" \t\n\r");
    return st.substr(first, last - first + 1);
}
```

### 연속한 공백 제거
```cpp
line = regex_replace(line, regex(" +"), " ");
```