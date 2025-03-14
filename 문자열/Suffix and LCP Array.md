[카테고리](/README.md)
## Suffix Array, LCP Array
### Suffix Array (Mander-Myers)
```cpp
template <typename Container> // Container = string or vector<>
pair<vector<int>, vector<int> > getSuffixArray(const Container &st) {
    int n = st.size();
    vector<int> sa(n), rank(n), tmp(n);
    for (int i = 0; i < n; i++) sa[i] = i, rank[i] = st[i];
    if constexpr (is_same_v<Container, vector<typename Container::value_type>>) for (auto e : rank) assert(e > 0); // rank[i]에 양수만 들어가야됨 // Container=vector<int>같은거면 확인

    vector<int> cnt(max<int>(n, *max_element(st.begin(), st.end())) + 1, 0);

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

    for (auto &e : rank) --e; // 1-based -> 0-based // 0<=i<n에 대해 rank[sa[i]] == i임 // sa[idx]=i -> st[i:]가 idx번째 접미사 // rank[i]=idx 즉, st[i:]가 몇번째 접미사인지 rank[i]에 저장됨
    return {sa, rank};
}
```
### LCP Array (Kasai's algorithm)
```cpp
template <typename Container> // Container = string or vector<>
vector<int> getLCPArray(const Container &st, const vector<int> &sa, const vector<int> &rank) {
    int n = st.size();
    assert(n >= 1);

    vector<int> lcp(n - 1);
    for (int i = 0, h = 0; i < n; ++i, h -= !!h) if (rank[i]) {
        for (int j = sa[rank[i] - 1]; j + h < n && i + h < n && st[j + h] == st[i + h];) ++h;
        lcp[rank[i] - 1] = h;
    }
    return lcp;
} // lcp[i]는 sa[i]와 sa[i + 1]의 최장 공통 접두사 // 따라서 lcp배열의 크기는 n-1임
```

### $O((N+M)\log(N+M))$ LCS(최장공통 부분 문자열)
```cpp
template <typename Container> // Container = string or vector<>
Container LCString(const Container &a, const Container &b, typename Container::value_type dummy) { // 최장 공통 부분 문자열(최장 공통 부분 수열 아님) // dummy는 Container에 없는 문자 -> ex) char이면 '#' 같은 거
    Container st(a.size() + 1 + b.size(), dummy);
    for (int i = 0; i < a.size(); i++) st[i] = a[i];
    for (int i = 0; i < b.size(); i++) st[a.size() + 1 + i] = b[i];
    
    auto [sa, rank] = getSuffixArray(st);
    auto lcp = getLCPArray(st, sa, rank);
    
    int idx = -1, len = 0;
    for (int i = 0; i < lcp.size(); i++) if ((int(a.size() - sa[i]) ^ int(a.size() - sa[i + 1])) < 0) { // sa[i]<a.size()<sa[i+1] or sa[i+1]<a.size()<sa[i]
        if (len < lcp[i]) {
            len = lcp[i];
            idx = i;
        }
    }

    if (!~idx) return Container(0, 0);
    return Container(st.begin() + sa[idx], st.begin() + sa[idx] + lcp[idx]);
}
```
a.size(), sa[i], sa[i + 1]의 대소관계 비교는 [사이값 확인](/ps-snippet/C++/기타/Idea.md#사이값-확인) 문서 참고   

### 가장 긴 반복 부분 문자열, 서로 다른 부분 문자열의 개수, k번 이상 등장하는 서로 다른 부분 문자열의 개수([Deque trick](/기타/Deque%20Trick.md) 필요), k번 이상 등장하는 가장 긴 부분 문자열([Deque trick](/기타/Deque%20Trick.md) 필요)
```cpp
template <typename Container> // Container = string or vector<>
Container longestRepeatedSubstring(const Container &st, const vector<int> &sa, const vector<int> &lcp) {
    if (st.size() == 1) return Container(0, 0);
    int i = max_element(lcp.begin(), lcp.end()) - lcp.begin();
    return Container(st.begin() + sa[i], st.begin() + sa[i] + lcp[i]);
}

long long countDistinctSubstrings(const string &st, const vector<int> &lcp) {
    long long n = st.size();
    return n * (n + 1) / 2 - accumulate(lcp.begin(), lcp.end(), 0LL);
}

vector<int> dequeTrickMin(int len, const vector<int> &v) { // res[i]는 v[max(0, i - len + 1)]~v[i]의 최솟값 // 즉, 정확히 길이가 len인 구간의 최솟값은 res[len-1:n)에 저장됨
    vector<int> res(v.size());
    deque<int> dq;

    for (int i = 0; i < v.size(); i++) {
        while (!dq.empty() && v[dq.back()] > v[i]) dq.pop_back();
        dq.push_back(i);
        if (i - dq.front() + 1 > len) dq.pop_front();
        res[i] = v[dq.front()];
    }
    
    return res;
}

long long countDistinctSubstringsRepeatedAtLeastK(const vector<int> &lcp, int k) { // k번 이상 등장하는 반복 부분 문자열 종류의 수
    assert(k >= 2); // k=1일 땐  n * (n + 1) / 2 - accumulate(lcp.begin(), lcp.end(), 0LL);
    if (lcp.size() + 1 < k) return 0; // 문자열 길이는 lcp.size()+1

    auto rmq = dequeTrickMin(k - 1, lcp); // sa배열 k개의 최장공통접두사가 필요하므로 lcp배열에선 k-1개씩 뽑아서 min값을 구하면 됨
    long long res = rmq[k - 2];
    for (int i = k - 1; i < lcp.size(); i++) res += max(0, rmq[i] - rmq[i - 1]);
    return res;
}

template <typename Container> // Container = string or vector<>
Container longestSubstringRepeatedAtLeastK(const Container &st, const vector<int> &sa, const vector<int> &lcp, int k) { // k번 이상 등장하는 부분 문자열 중 가장 긴 부분 문자열
    if (k == 1) return st;
    if (st.size() < k) return Container(0, 0);

    auto rmq = dequeTrickMin(k - 1, lcp); // sa배열 k개의 최장공통접두사가 필요하므로 lcp배열에선 k-1개씩 뽑아서 min값을 구하면 됨
    int i = max_element(rmq.begin() + k - 2, rmq.end()) - rmq.begin();
    return Container(st.begin() + sa[i], st.begin() + sa[i] + rmq[i]);
}
```
### 시간복잡도
suffix array $O(N \log{N})$   
(suffix 배열이 주어져 있을 때) lcp array $O(N)$   

suffix array를 $O(N)$에 구하는 알고리즘도 있지만 복잡해서 잘 쓰지 않는 듯   

### 구현 주의사항
group의 원소는 0 초과의 값을 가져야 된다.   
`countingSort`에서 `rank[sa[i] + t]`에 접근할 때 인덱스 초과하면 0으로 바꿔서 `cnt[0]`에 저장하므로 이 0과 구별하기 위해선 rank배열의 값은 0을 가지면 안 된다.   
`tmp[sa[0]] = 1`로 초기화하는 것도 같은 이유다.   
`getSuffixArray()`가 끝난 후 rank배열을 0-based로 바꿔주는 게 이후 lcp배열의 계산이나 여러 응용에 훨씬 편하다.   

### 사용설명
> 접미사 순서대로 출력하고 싶으면 아래코드 사용   
> ```cpp
> for (auto i : sa) cout << st.substr(i) << "\n";
> ```

i번째 접미사부터 j번째 접미사까지의 최장공통접두사의 길이는 `min(lcp[i], ..., lcp[j - 1])`이기 때문에 lcp배열에서 RMQ 구하면 됨   
RMQ는 전처리 $O(N\log{N})$ 쿼리 $O(1)$의 구현을 사용할 때도 있고, `countDistinctSubstringsRepeatedAtLeastK()`에서처럼 길이가 정해진 구간에 대해서만 계산하는 경우엔 Deque Trick으로 모든 구간에 대해 $O(N)$으로 계산할 수도 있음([RMQ](/기타/RMQ.md) 참고)   

`st[i:]`와 `st[j:]`의 최장공통접두사의 길이는 `rank[i]`번째 접미사부터 `rank[j]`번째 접미사까지의 최장공통접두사의 길이를 구하면 됨.   
```cpp
if (i == j) return n - i;

RMQ rmq(lcp);
int idx1 = rank[i];
int idx2 = rank[j];
if (idx1 > idx2) swap(idx1, idx2);
return rmq.query(idx1, idx2 - 1); // idx1 <= idx2 - 1은 i!=j라서 항상 만족함
```

### 문제
[Suffix Array](https://www.acmicpc.net/problem/9248)   
[최장 공통 부분 문자열](https://www.acmicpc.net/problem/9249) - `LCString()`   
[반복 부분문자열](https://www.acmicpc.net/problem/1605) - `longestRepeatedSubstring()`   
[Repeated Substrings](https://www.acmicpc.net/problem/16415) - `longestRepeatedSubstring()`   
[서로 다른 부분 문자열의 개수 2](https://www.acmicpc.net/problem/11479) - `countDistinctSubstrings()`   
[반복되는 부분 문자열](https://www.acmicpc.net/problem/10413) - `countDistinctSubstringsRepeatedAtLeastK(k=2)`   
[Milk Patterns](https://www.acmicpc.net/problem/6206) - `longestSubstringRepeatedAtLeastK()`   
[문자열과 쿼리](https://www.acmicpc.net/problem/13713) - rank 쓰는 문제, lcp에서 rmq 계산 필요   
[Prefix와 Suffix](https://www.acmicpc.net/problem/13576) - rank 쓰는 문제, lcp에서 rmq 계산 필요   
[Stammering Aliens](https://www.acmicpc.net/problem/3864) - lcp에서 min rmq, sa에서 max rmq   

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
https://infossm.github.io/blog/2021/07/18/suffix-array-and-lcp/   
https://m.blog.naver.com/jqkt15/221795956351 - 반복 부분 문자열의 개수   