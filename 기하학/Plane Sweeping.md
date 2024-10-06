[카테고리](/README.md)
## Plane Sweeping
```cpp
struct Line {
    int x, y1, y2, val;
    bool operator<(const Line &other) const { return x < other.x; }
};

template <typename T, typename R>
R rectTotalArea(vector<tuple<T, T, T, T> > &rects, R res) { // tuple -> {x1, y1, x2, y2}
    T mnY = numeric_limits<T>::max(), mxY = numeric_limits<T>::min();
    for (auto [x1, y1, x2, y2] : rects) {
        mnY = min({mnY, y1, y2});
        mxY = max({mxY, y1, y2});
    }

    const int offset = -mnY;
    vector<int> ys(mxY + offset + 1);

    vector<Line> v;
    v.reserve(2 * rects.size());
    
    for (auto [x1, y1, x2, y2] : rects) {
        y1 += offset;
        y2 += offset;
        
        v.push_back({x1, y1, y2, 1});
        v.push_back({x2, y1, y2, -1});
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0, j, dx = 0; i < v.size(); dx = v[j].x - v[i].x, i = j) {
        int cnt = 0;
        for (auto y : ys) cnt += !!y;
        res += R(dx) * cnt;

        j = i;
        while (j < v.size() && v[j].x == v[i].x) {
            for (int y = v[j].y1; y < v[j].y2; y++) ys[y] += v[j].val;
            ++j;
        }
    }
    
    return res;
}
```
### 시간복잡도
$O(N Y)$   
Y는 y좌표 최댓값   

### 구현 주의사항


### 사용설명
좌표의 범위가 int더라도 넓이는 ll이 될 수 있기에 std::accumulate처럼 리턴 타입을 나타내기 위한 매개변수를 추가로 받도록 했다.   
앞으로도 자주 애용하게 될 방식이 아닐까 싶다.   

### 문제
[행사장 대여 (Large)](https://www.acmicpc.net/problem/14733) - O(N * Y) 가능   
[화성 지도](https://www.acmicpc.net/problem/3392)   
[직사각형](https://www.acmicpc.net/problem/7626) - O(NlogN) 필요

### 참고링크