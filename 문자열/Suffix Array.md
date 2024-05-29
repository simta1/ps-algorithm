[카테고리](/README.md)
### Suffix Array (Mander-Myers)
```cpp
vector<int> getSuffixArray(const string &st) {
    int n = st.size();
    vector<int> sa(n), group(n);
    iota(sa.begin(), sa.end(), 0);
    for (int i = 0; i < n; i++) group[i] = st[i];

    vector<int> cnt(max(n, 256) + 1, 0); // 아스키코드 최대값 포함 가능하게 선언
    vector<int> sorted(n);
    vector<int> nextGroup(n);

    auto countingSort = [&](int t) {
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < n; i++) ++cnt[sa[i] + t < n ? group[sa[i] + t] : 0];
        for (int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) sorted[--cnt[sa[i] + t < n ? group[sa[i] + t] : 0]] = sa[i];
        sa = sorted;
    };

    for (int t = 1; ; t <<= 1) {
        countingSort(t);
        countingSort(0);

        nextGroup[sa[0]] = 1;
        for (int i = 1; i < n; i++) nextGroup[sa[i]] = nextGroup[sa[i - 1]] +  (group[sa[i - 1]] != group[sa[i]] || group[sa[i - 1] + t] != group[sa[i] + t]);
        group = nextGroup;

        if (group[sa.back()] == n) break;
    }

    return sa;
}
```
### LCP Array (Kasai's algorithm)
```cpp
vector<int> getLCPArray(const string &st, const vector<int> &sa) {
    int n = st.size();
    vector<int> rank(n), lcp(n);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;

    for (int i = 0, h = 0; i < n; i++, h -= !!h) if (rank[i]) {
        int idx = rank[i];
        while (st[sa[idx - 1] + h] == st[sa[idx] + h]) ++h;
        lcp[rank[i]] = h;
    }

    return lcp;
}
```
### 시간복잡도 
suffixArray $O(N~logN)$   
lcp $O(N)$   
suffixArray $O(N)$ 알고리즘도 있지만 복잡해서 잘 안쓴다고 한다.

### 주의사항
group의 원소는 0 초과의 값을 가져야 된다.   
countingSort에서 group[a + t] 접근할 때 인덱스 초과하면 0으로 바꿔서 cnt[0]에 저장하므로 group이 0을 가지면 안 된다.   
nextGroup[sa[0]] = 1로 초기화하는 것도 같은 이유   

### 사용관련
lcp[i]는 sa[i]와 sa[i - 1]의 최장 공통 접두사   
lcp[0]은 그냥 쓰레기값

### 백준문제
[Suffix Array](https://www.acmicpc.net/problem/9248)

### 원리
rank는 sa배열에 대한 역함수. st[i:]가 sa에서 몇 번째인지 저장   
가장 긴 접미사부터 계산해가는 과정에서 필요함   
아래 코드는 모두 동치
```cpp
h = max(h - 1, 0)
if (h) --h;
h -= bool(h);
h -= !!h;
```

### 참고문헌
https://blog.naver.com/kks227/221028710658
https://loosie.tistory.com/798   
https://blog.myungwoo.kr/57   
https://koosaga.com/125   