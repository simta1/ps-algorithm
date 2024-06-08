[카테고리](/README.md)
### Fail Function
```cpp
vector<int> getPi(const string &st) {
    vector<int> pi(st.size());

    for (int i = 1, j = 0; i < st.size(); i++) {
        while (j > 0 && st[i] != st[j]) j = pi[j - 1];
        if (st[i] == st[j]) pi[i] = ++j;
    }
    
    return pi;
}
```
### KMP
```cpp
vector<int> kmp(const string &st, const string &pattern) {
    int n = st.size();
    int m = pattern.size();

    auto pi = getPi(pattern);
    
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

### 사용관련
st가 cyclic string이라면 st2 = st + st로 이어붙인 뒤 kmp(st2, pattern) 사용

### 백준문제
[찾기](https://www.acmicpc.net/problem/1786)   
[시계 사진들](https://www.acmicpc.net/problem/10266) - cyclic   

### 참고문헌
https://bowbowbow.tistory.com/6