[카테고리](/README.md)
## Suffix Array, LCP Array
### Suffix Array (Mander-Myers)
```cpp
vector<int> getSuffixArray(const string &st) {
    int n = st.size();
    vector<int> sa(n), rank(n), tmp(n);
    for (int i = 0; i < n; i++) sa[i] = i, rank[i] = st[i];

    vector<int> cnt(max(n, 256) + 1, 0); // 아스키코드 최대값 포함 가능하게 선언

    auto countingSort = [&](int t) {
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; i++) ++cnt[sa[i] + t < n ? rank[sa[i] + t] : 0];
        for (int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) tmp[--cnt[sa[i] + t < n ? rank[sa[i] + t] : 0]] = sa[i];
        swap(sa, tmp);
    };

    for (int t = 1; ; t <<= 1) {
        countingSort(t);
        countingSort(0);

        tmp[sa[0]] = 1;
        for (int i = 1; i < n; i++) tmp[sa[i]] = tmp[sa[i - 1]] +  (rank[sa[i - 1]] != rank[sa[i]] || rank[sa[i - 1] + t] != rank[sa[i] + t]);
        swap(rank, tmp);

        if (rank[sa.back()] == n) break;
    }

    return sa;
}
```
### LCP Array (Kasai's algorithm)
```cpp
vector<int> getLCPArray(const string &st, const vector<int> &sa) {
    int n = st.size();
    assert(n >= 1);
    vector<int> rank(n), lcp(n + 1); // 분명 인덱스를 n-1까지밖에 사용 안해서 lcp(n)으로 해도 될 거 같은데 테케 여러개 주어지는 문제에서 lcp(n)쓰면 에러남. 왜지?
    for (int i = 0; i < n; i++) rank[sa[i]] = i; // sa[idx]=i -> st[i:]가 idx번째 접미사 // rank[i]=idx 즉, st[i:]가 몇번째 접미사인지 rank[i]에 저장

    for (int i = 0, h = 0; i < n; ++i, h -= !!h) if (rank[i]) {
        for (int j = sa[rank[i] - 1]; j + h < n && i + h < n && st[j + h] == st[i + h];) ++h;
        lcp[rank[i]] = h;
    }

    return lcp;
} // lcp[i]는 sa[i]와 sa[i - 1]의 최장 공통 접두사, lcp[0]은 그냥 쓰레기값

string longestRepeatedSubstring(const string &st, const vector<int> &sa, const vector<int> &lcp) {
    int i = max_element(lcp.begin() + 1, lcp.end()) - lcp.begin();
    return st.substr(sa[i], lcp[i]);
}

long long countDistinctSubstrings(const string &st, const vector<int> &lcp) {
    long long n = st.size();
    return n * (n + 1) / 2 - accumulate(lcp.begin() + 1, lcp.end(), 0LL);
}
```
### 시간복잡도
suffixArray $O(N \log{N})$   
lcp $O(N)$   
suffixArray $O(N)$ 알고리즘도 있지만 복잡해서 잘 안쓴다고 함   

### 구현 주의사항
group의 원소는 0 초과의 값을 가져야 된다.   
countingSort에서 group[a + t] 접근할 때 인덱스 초과하면 0으로 바꿔서 cnt[0]에 저장하므로 이 0과 구별하기 위해선 group배열의 값은 0을 가지면 안 된다.   
tmp[sa[0]] = 1로 초기화하는 것도 같은 이유   

### 문제
[Suffix Array](https://www.acmicpc.net/problem/9248)   
[반복 부분문자열](https://www.acmicpc.net/problem/1605) - `longestRepeatedSubstring()`   
[Repeated Substrings](https://www.acmicpc.net/problem/16415) - `longestRepeatedSubstring()`   

### 원리
rank는 sa배열에 대한 역함수. 즉, st[i:]가 sa에서 몇 번째인지 저장   
가장 긴 접미사부터 계산해가는 과정에서 필요함   
아래 코드는 모두 동치   
```cpp
h = max(h - 1, 0);
if (h) --h;
h -= bool(h);
h -= !!h;
```

### 참고링크
https://blog.naver.com/kks227/221028710658   
https://loosie.tistory.com/798   
https://blog.myungwoo.kr/57   
https://koosaga.com/125   