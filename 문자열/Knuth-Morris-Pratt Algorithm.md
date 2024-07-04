[카테고리](/README.md)
### Fail Function (string)
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
### KMP (string)
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
### Fail Function (vector\<T>)
```cpp
template <typename T>
vector<int> getPi(const vector<T> &st) {
    vector<int> pi(st.size());

    for (int i = 1, j = 0; i < st.size(); i++) {
        while (j > 0 && st[i] != st[j]) j = pi[j - 1];
        if (st[i] == st[j]) pi[i] = ++j;
    }

    return pi;
}
```
### KMP (vector\<T>)
```cpp
template <typename T>
vector<int> kmp(const vector<T> &st, const vector<T> &pattern) {
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
n - pi.back()으로 최소주기 계산 가능   
ex) st = "abaab"   
pi.back() = 2, 뒤에서 2번째 지점에서부터 중복이 시작됨 => 즉 앞에서 3개가 가능한 최소 주기   
$\therefore$ n - pi.back() = 3   

cyclic string에서도 검색 가능   
st가 cyclic string이라면 st2 = st + st로 이어붙인 뒤 kmp(st2, pattern) 사용

### 백준문제
[찾기](https://www.acmicpc.net/problem/1786)   
[광고](https://www.acmicpc.net/problem/1305) - 최소 주기 계산   
[Slot Machines](https://www.acmicpc.net/problem/14959) - 최소 주기 계산   
[시계 사진들](https://www.acmicpc.net/problem/10266) - cyclic   

### 참고문헌
https://hyeo-noo.tistory.com/182   
https://bowbowbow.tistory.com/6