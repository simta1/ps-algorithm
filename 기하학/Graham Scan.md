[카테고리](/README.md)
### Graham Scan
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
int ccw(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3) {
    T cp = crossProduct(p2 - p1, p3 - p1);
    return (cp > 0) - (cp < 0);
}

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
```
### 시간복잡도 
$O(N~logN)$   

### 주의사항


### 사용관련


### 백준문제
[]()

### 원리