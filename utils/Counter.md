[카테고리](/README.md)
## Counter
```cpp
// https://www.acmicpc.net/problem/13028
template <int N, int THRESHOLD = 1>
class Counter {
private:
    vector<int> cnt;
    int kind;

public:
    Counter() : cnt(10, 0), kind(0) {}

    void push(int a) {
        kind += (++cnt[a] == THRESHOLD);
    }

    void pop(int a) {
        kind -= (cnt[a]-- == THRESHOLD);
    }

    int getKind() {
        return kind;
    }
};
```

### Counter ( + 최대 빈도수 계산)
```cpp
// https://www.acmicpc.net/problem/12986
class Counter {
private:
    vector<int> cntElement, cntOccurrence;
    int maxCntElement;

public:
    void push(int idx) {
        int &cnt = cntElement[v[idx]];
        if (cnt) --cntOccurrence[cnt];
        ++cnt;
        ++cntOccurrence[cnt];
        maxCntElement = max(maxCntElement, cnt);
    }

    void pop(int idx) {
        int &cnt = cntElement[v[idx]];
        if (--cntOccurrence[cnt] == 0 && cnt == maxCntElement) --maxCntElement;
        --cnt;
        ++cntOccurrence[cnt];
    }
    
    int query() {
        return maxCntElement;
    }
};
```
