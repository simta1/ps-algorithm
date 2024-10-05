[카테고리](/README.md)
## 기하학 헤더
### 자료형
```cpp
using ld = double;
```
오차 범위에 따라 double과 long double을 변경하기 쉽도록 ld 사용
### Point, Cross Product, CCW
```cpp
template <typename T>
struct Point {
    T x, y;

    Point() = default;
    Point(T x, T y) : x(x), y(y) {}
    template <typename U> Point(const Point<U> &other) : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)) {}

    bool operator<(const Point &other) const { return x == other.x ? y < other.y : x < other.x; }
    bool operator<=(const Point &other) const { return x == other.x ? y <= other.y : x <= other.x; }
    bool operator==(const Point &other) const { return x == other.x && y == other.y; }
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
### Distance
```cpp
template <typename T>
T distPP(const Point<T> &p1, const Point<T> &p2) { // distance from P(point) to P(point)
    return sqrtl((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

template <typename T>
T distLP(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3) { // distance from L(line, p1p2) to P(point, p3)
    assert (!(p1 == p2)); // p1 != p2
    return crossProduct(p2 - p1, p3 - p1) / distPP(p1, p2);
}
```
### Area
```cpp
template <typename T>
inline ld getTriangleArea(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
    return 0.5l * fabsl(a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
}

template <typename T>
inline ld getRectangleArea(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3, const Point<T> &p4) {
    return getTriangleArea(p1, p2, p3) + getTriangleArea(p1, p4, p3);
}

ld heron(ld a, ld b, ld c) { // 헤론
    ld s = ld(0.5) * (a + b + c);
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

ld brahmagupta(ld a, ld b, ld c, ld d) { // 브라마굽타, 사각형 네 꼭짓점이 공원점일 때
    ld s = ld(0.5) * (a + b + c + d);
    return sqrt((s - a) * (s - b) * (s - c) * (s - d));
}

ld getSegmentCircleArea(ld r, ld len) { // 활꼴 넓이, r : 반지름, len : 활꼴 길이
    ld cosTheta = 1 - ld(len * len) / (2 * r * r);
    ld sinTheta = sqrt(1 - cosTheta * cosTheta); // > 0
    ld theta = acos(cosTheta);
    return ld(0.5) * r * r * (theta - sinTheta);
}
```

### isBetween
```cpp
template <typename T>
bool isBetween(Point<T> a, Point<T> b, Point<T> c) {
    return min(a.x, c.x) <= b.x && b.x <= max(a.x, c.x) && min(a.y, c.y) <= b.y && b.y <= max(a.y, c.y);
}
```

### triangle
```cpp
ld getOtherSideLength(ld a, ld b, ld cosTheta) { // cos II
    return sqrt(a * a + b * b - 2 * a * b * cosTheta);
}

ld getCosTheta(ld x, ld y, ld z) { // x 맞은편 각도
    return (y * y + z * z - x * x) / 2 / y / z;
}
```

### isOnPL
```cpp
```

### 회전변환
```cpp
void rotate2D(ld &x, ld &y, ld theta) { // 반시계방향으로 theta만큼 회전
    tie(x, y) = pair<ld, ld>{cos(theta) * x + sin(theta) * y, -sin(theta) * x + cos(theta) * y};
}
```
<!-- TODO rotate3D추가해야 됨, 3D에서 z에 아무값넣어보내면 2D로도 쓸수있으니 3D만들고 나서 2D삭제하면 될 듯 -->

### 구현 주의사항
좌표들을 곱셈하기 때문에 overflow 고려할 땐 좌표의 최대값의 제곱을 기준으로 판단

### 문제
[CCW](https://www.acmicpc.net/problem/11758) - CCW   
[쓰레기 슈트](https://www.acmicpc.net/problem/4225) - distance   

### 원리
p1p2와 p3 사이 거리(수선의 발이 선분 위에 있을 때)   
$(y_2 - y_1)(x - x_1) - (x_2 - x_1)(y - y_1) = 0$   
$(x_3, y_3)$에서 거리
$\frac{|(y_2 - y_1)(x_3 - x_1) - (x_2 - x_1)(y_3 - y_1)|}{\sqrt{(y_2 - y_1) ^ 2 + (x_2 - x_1) ^ 2}} = \frac{|cp(p3 - p1, p2 - p1)|}{dist(p_1, p_2)}$