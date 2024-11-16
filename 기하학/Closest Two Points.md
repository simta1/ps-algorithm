[카테고리](/README.md)
## 가장 가까운 두 점(Closest Two Points)
### [기하학 헤더](/기하학/Geometry%20Header.md)
<details>
<summary>Point</summary>

```cpp
template <typename T>
struct Point {
    T x, y;
    
    bool operator<(const Point &other) const { return tie(x, y) < tie(other.x, other.y); }
    Point operator-(const Point &other) const { return {x - other.x, y - other.y}; }
};
```
</details>

### Closest Two Points
```cpp
template <typename T>
T distSquare(const Point<T> &p1, const Point<T> &p2) {
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

template <typename T>
T getClosestTwoPoints(vector<Point<T> > points) {
    assert(points.size() > 1);

    sort(points.begin(), points.end(), [&](const Point<T> &a, const Point<T> &b) { return a.x < b.x; });

    auto square = [&](T a) { return a * a; };
    function<T(int, int)> dnc = [&](int s, int e) -> T {
        if (s + 1 == e) return distSquare(points[s], points[e]);
        if (s + 2 == e) return min({
            distSquare(points[s], points[s + 1]),
            distSquare(points[s + 1], points[e]),
            distSquare(points[e], points[s])
        });

        int m = s + e >> 1;
        T res = min(dnc(s, m), dnc(m + 1, e));

        vector<Point<T> > midPoints;
        for (int i = s; i <= e; i++) {
            if (square(points[m - 1].x - points[i].x) <= res || square(points[m].x - points[i].x) <= res) midPoints.push_back(points[i]);
        }
        sort(midPoints.begin(), midPoints.end(), [&](const Point<T> &a, const Point<T> &b) { return a.y < b.y; });

        for (int i = 0; i < midPoints.size() - 1; i++) {
            for (int j = i + 1; j < midPoints.size(); j++) {
                if (square(midPoints[i].y - midPoints[j].y) >= res) break;
                res = min(res, distSquare(midPoints[i], midPoints[j]));
            }
        }

        return res;
    };

    return dnc(0, points.size() - 1);
}
```
### 시간복잡도 
$O(N ~log^2 N)$   

### 사용설명
original points가 바껴도 된다면 vector<Point<T> > &points로 참조 사용   

### 문제
[가장 가까운 두 점](https://www.acmicpc.net/problem/2261)   

### 참고링크
https://daisylum.tistory.com/22   
https://hackids.tistory.com/61