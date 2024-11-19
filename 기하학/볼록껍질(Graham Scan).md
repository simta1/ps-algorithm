[카테고리](/README.md)
## 볼록 껍질(Convex Hull)
### [기하학 헤더](/기하학/Geometry%20Header.md)
<details>
<summary>Point, Cross Product, CCW</summary>

```cpp
template <typename T>
struct Point {
    T x, y;
    
    bool operator<(const Point &other) const { return tie(x, y) < tie(other.x, other.y); }
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

### Graham Scan
```cpp
template <typename T>
vector<Point<T> > getConvexHull(vector<Point<T> > points) { // points 원본 배열 바껴도 괜찮으면 &points로 받기
    assert (points.size() >= 3);
    
    swap(points[0], *min_element(points.begin(), points.end()));
    sort(points.begin() + 1, points.end(), [&](const Point<T> &a, const Point<T> &b) {
        int dir = ccw(points[0], a, b);
        return dir ? dir > 0 : a < b;
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

### 구현 주의사항
좌표들을 곱셈하기 때문에 overflow 고려할 땐 좌표의 최대값의 제곱을 기준으로 판단   
중간에 덧셈 뺄셈 때문에 값이 생각보다 더 커져서 그냥 제곱한 값이 1e8정도만 되도 long long 쓰는 게 낫다.

### 사용설명
original points가 바껴도 된다면 `vector<Point<T> > &points`로 참조 사용   

### 문제
[볼록 껍질](https://www.acmicpc.net/problem/1708)   