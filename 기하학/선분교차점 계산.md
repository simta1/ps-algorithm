[카테고리](/README.md)
## 선분교차점 계산
### [기하학 헤더](/기하학/Geometry%20Header.md)
<details>
<summary>Point, Cross Product</summary>

```cpp
template <typename T>
struct Point {
    T x, y;

    bool operator<(const Point &other) const { return x == other.x ? y < other.y : x < other.x; }
    bool operator<=(const Point &other) const { return x == other.x ? y <= other.y : x <= other.x; }
    bool operator==(const Point &other) const { return x == other.x && y == other.y; }
    Point operator-(const Point &other) const { return {x - other.x, y - other.y}; }
};

template <typename T>
T crossProduct(const Point<T> &p1, const Point<T> &p2) {
    return (p1.x * p2.y - p2.x * p1.y);
}
```
</details>

### Line-Line Intersection Calculate
```cpp
template <typename T>
void printIntersection(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3, const Point<T> &p4) {
    T cp = crossProduct(p2 - p1, p4 - p3);

    if (cp == 0) { // 평행
        if (max(p1, p2) == min(p3, p4)) cout << p2.x <<  " " << p2.y;
        else if (max(p3, p4) == min(p1, p2)) cout << p1.x << " " << p1.y;
        // else : 교점 무수히 많음
    }
    else {
        T x = (crossProduct(p1, p2) * (p3.x - p4.x) - crossProduct(p3, p4) * (p1.x - p2.x)) / cp;
        T y = (crossProduct(p1, p2) * (p3.y - p4.y) - crossProduct(p3, p4) * (p1.y - p2.y)) / cp;
        cout << x << " " << y;
    }
}
```
### 다각형 겹치는 교점 찾을 때
```cpp
template <typename T>
bool isBetween(Point<T> a, Point<T> b, Point<T> c) {
    return min(a.x, c.x) <= b.x && b.x <= max(a.x, c.x) && min(a.y, c.y) <= b.y && b.y <= max(a.y, c.y);
}

template <typename T>
void getInetersectionLL(vector<Point<T> > &points, Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4) {
    T cp = crossProduct(p2 - p1, p4 - p3);

    if (cp == 0) { // 평행
        if (p2 < p1) swap(p1, p2);
        if (p4 < p3) swap(p3, p4);

        if (p2 == p3) points.push_back(p2);
        else if (p4 == p1) points.push_back(p4);
        else if (ccw(p1, p2, p3) == 0) {
            if (p2 < p3 || p4 < p1) return;
            
            vector<Point<T> > v = {p1, p2, p3, p4};
            sort(v.begin(), v.end());
            points.push_back(v[1]);
            points.push_back(v[2]);
        }
    }
    else {
        T x = (crossProduct(p1, p2) * (p3.x - p4.x) - crossProduct(p3, p4) * (p1.x - p2.x)) / cp;
        T y = (crossProduct(p1, p2) * (p3.y - p4.y) - crossProduct(p3, p4) * (p1.y - p2.y)) / cp;
        Point<T> res;
        res.x = x;
        res.y = y;
        if (isBetween(p1, res, p2) && isBetween(p3, res, p4)) points.push_back(res);
    }
}
```
### 시간복잡도 
$O(1)$   

### 구현 주의사항
좌표들을 곱셈하기 때문에 overflow 고려할 땐 좌표의 최대값의 제곱을 기준으로 판단

### 문제
[선분 교차 3](https://www.acmicpc.net/problem/20149)

### 원리
$\left ( \frac{y2-y1}{x2-x1} \right )(x-x1)+y1=\left ( \frac{y4-y3}{x4-x3} \right )(x-x3)+y3$   

$(y2-y1)(x4-x3)(x-x1)+(y1-y3)(x2-x1)(x4-x3)=(y4-y3)(x2-x1)(x-x3)$   

식 잘 정리하면   
$x = \frac{cp(p1, p2) (x3-x4) - cp(p3, p4) (x1-x2)}{cp(p2-p1, p4-p3)}$   

$y = \frac{cp(p1, p2) (y3-y4) - cp(p3, p4) (y1-y2)}{cp(p2-p1, p4-p3)}$