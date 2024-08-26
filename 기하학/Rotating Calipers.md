[카테고리](/README.md)
## Rotating Calipers
### [기하학 헤더](/기하학/Geometry%20Header.md)
<details>
<summary>Point, Cross Product, CCW</summary>

```cpp
template <typename T>
struct Point {
    T x, y;
    
    bool operator<(const Point<T>  &other) const { return x == other.x ? y < other.y : x < other.x; }
    Point operator-(const Point &other) const { return {x - other.x, y - other.y}; }
};

template <typename T>
T crossProduct(const Point<T> &p1, const Point<T> &p2) {
    return (p1.x * p2.y - p2.x * p1.y);
}

template <typename T>
int ccw(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3) { // -1 : 시계, 0 : 일직선, 1 : 반시계
    T cp = crossProduct(p2 - p1, p3 - p1);
    return (cp > 0) - (cp < 0);
}
```
</details>

### Rotating Calipers
```cpp
template <typename T>
vector<Point<T> > getConvexHull(vector<Point<T> > points) {
    swap(points[0], *min_element(points.begin(), points.end()));
    sort(points.begin() + 1, points.end(), [&](const Point<T> &a, const Point<T> &b) {
        int dir = ccw(points[0], a, b);
        if (!dir) return a < b;
        else return dir > 0;
    });

    vector<Point<T> > v;
    for (auto &point : points) {
        while (v.size() >= 2 && ccw(v[v.size() - 2], v[v.size() - 1], point) <= 0) v.pop_back();
        v.push_back(point);
    }

    return v;
}

template <typename T>
T distSquare(const Point<T> &p1, const Point<T> &p2) {
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

template <typename T>
T getDiameterSquare(const vector<Point<T> > &points) {
    vector<Point<T> > v = getConvexHull(points);

    T diameter = 0;
    int n = v.size(), a = 0, b = 1;

    while (a < n && b < 2 * n) {
        diameter = max(diameter, distSquare(v[a % n], v[b % n]));
        if (crossProduct(v[(a + 1) % n] - v[a % n], v[(b + 1) % n] - v[b % n]) >= 0) ++b;
        else ++a;
    }
    return diameter;
}
```
### 시간복잡도 
$O(N~logN)$   
회전하는 캘리퍼스 자체는 $O(N)$이지만 볼록껍질이 미리 주어져야 하므로 볼록 껍질을 계산하는 시간을 포함하면 $O(N~logN)$이다.

### 구현 주의사항
template T가 정수형일 수도 있으므로 거리를 비교할 때 sqrt()를 쓰지 말고 distSquare()로  거리의 제곱을 기준으로 비교한다.
getDiameterSquare()도 제곱된 값을 리턴한다.

### 문제
[가장 먼 두 점](https://www.acmicpc.net/problem/2049)