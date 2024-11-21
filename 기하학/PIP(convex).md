[카테고리](/README.md)
## 볼록다각형 내부의 점 판정(Point In Convex Polygon)
### [기하학 헤더](/기하학/Geometry%20Header.md)
<details>
<summary>Point, Cross Product, CCW, isBetween, isOnPL</summary>

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

template <typename T>
bool isBetween(Point<T> a, Point<T> b, Point<T> c) {
    return min(a.x, c.x) <= b.x && b.x <= max(a.x, c.x) && min(a.y, c.y) <= b.y && b.y <= max(a.y, c.y);
}

template <typename T>
bool isOnPL(Point<T> p, Point<T> l1, Point<T> l2) { // p가 l1 l2위에 있는지
    return ccw(p, l1, l2) == 0 && isBetween(l1, p, l2);
}
```
</details>

### Point in Convex Polygon
```cpp
template <typename T>
int PICP(const Point<T> &point, const vector<Point<T> > &polygon, int dir=0) { // -1 : 내부, 0 : 경계, 1 : 외부
    int n = polygon.size();
    assert(n >= 3);

    if (!dir) { // dir은 polygon에서 점들이 주어진 방향(반시계 : 1, 시계 : -1, 모르는 경우(default) : 0)   
        int i = 2;
        while (!dir) dir = ccw(polygon[0], polygon[1], polygon[i++]);
    }
    assert(dir != 0); // dir = 0이면 모든 점이 일직선 위에 존재

    if (ccw(polygon[0], polygon[1], point) * dir < 0) return 1;
    if (ccw(polygon[0], polygon[n - 1], point) * dir > 0) return 1;

    if (isOnPL(point, polygon[0], polygon[1])) return 0;
    if (isOnPL(point, polygon[0], polygon[n - 1])) return 0;

    int lo = 1, hi = n;
    while (lo + 1 < hi) {
        int mid = lo + hi >> 1;
        if (ccw(polygon[0], polygon[mid], point) * dir >= 0) lo = mid;
        else hi = mid;
    }

    if (hi == n) return 1; // polygon[0], polygon[n - 1], point가 일직선인 경우

    return -ccw(polygon[lo], polygon[hi], point) * dir;
}
```
### 시간복잡도 
$O(logN)$   

### 사용설명
오목다각형에선 사용 불가   
나눗셈 없이 ccw로 구현해서 Point\<int> 등 정수형에서도 오차 없이 작동

dir은 polygon에서 점들이 주어진 방향(반시계 : 1, 시계 : -1, 모르는 경우(default) : 0)   
dir모르는 경우 그냥 checkPoint(polygon, point)로 호출   

### 문제
[미스테리 싸인](https://www.acmicpc.net/problem/20670) - 점이 다각형 경계 위에 있는 경우는 안 주어짐, 테스트용으로는 별로   
[점 분리](https://www.acmicpc.net/problem/3878)

### 참고링크
https://velog.io/@vkdldjvkdnj/boj09875   
https://anz1217.tistory.com/107