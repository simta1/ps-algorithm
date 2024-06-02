[카테고리](/README.md)
### KMP
```cpp
vector<int> kmp(const string &st, const string &pattern) {
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

### 사용관련
앞뒤가 이어진 원형 구조의 문자열에서 검색하고 싶다면 st2 = st + st로 이어붙인 뒤 st2에서 검색   

### 백준문제
[찾기](https://www.acmicpc.net/problem/1786)   
[시계 사진들](https://www.acmicpc.net/problem/10266) - 원형   

### 참고문헌
https://bowbowbow.tistory.com/6