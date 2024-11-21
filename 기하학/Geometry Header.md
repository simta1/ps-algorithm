[카테고리](/README.md)
## 기하학 헤더
### 자료형
```cpp
using ld = double;
```
오차 범위에 따라 double과 long double을 변경하기 쉽도록 자료형으로 `ld` 사용
### Point, Cross Product, CCW
```cpp
template <typename T>
struct Point {
    T x, y;

    Point() = default;
    Point(T x, T y) : x(x), y(y) {}
    template <typename U> Point(const Point<U> &other) : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)) {}

    bool operator<(const Point &other) const { return tie(x, y) < tie(other.x, other.y); }
    bool operator<=(const Point &other) const { return tie(x, y) <= tie(other.x, other.y); }
    bool operator==(const Point &other) const { return tie(x, y) == tie(other.x, other.y); }
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
ccw 쓸 때 좌표 최대값의 제곱의 8배정도까지 나올 수 있으니 오버플로우 고려할 때 넉넉하게 하는 게 좋음   
왠만하면 int는 안쓰는 게 나은 듯, 왠만하면 `ll`이나 `ld`사용하는 걸 추천   

### Distance
<details>
<summary>식 정리 과정</summary>

p1p2와 p3 사이 거리(수선의 발이 선분 위에 있을 때)   

$(y_2 - y_1)(x - x_1) - (x_2 - x_1)(y - y_1) = 0$   

$(x_3, y_3) \text{에서 거리} = \dfrac{|(y_2 - y_1)(x_3 - x_1) - (x_2 - x_1)(y_3 - y_1)|}{\sqrt{(y_2 - y_1) ^ 2 + (x_2 - x_1) ^ 2}} = \dfrac{|cp(p3 - p1, p2 - p1)|}{dist(p_1, p_2)}$
</details>

```cpp
template <typename T>
inline ld distPP(const Point<T> &p1, const Point<T> &p2) {
    return sqrtl((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

template <typename T>
inline T distSquarePP(const Point<T> &p1, const Point<T> &p2) {
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}

template <typename T>
ld distLP(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3) { // distance from L(line, p1p2) to P(point, p3)
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
inline T getTriangleAreaDouble(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
    return abs(a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
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

### isBetween, isOnPL
```cpp
template <typename T>
bool isBetween(Point<T> a, Point<T> b, Point<T> c) {
    return min(a.x, c.x) <= b.x && b.x <= max(a.x, c.x) && min(a.y, c.y) <= b.y && b.y <= max(a.y, c.y);
}

template <typename T>
bool isOnPL(Point<T> p, Point<T> l1, Point<T> l2) { // p가 l1 l2위에 있는지
    return ccw(p, l1, l2) == 0 && isBetween(l1, p, l2);
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

### 삼각함수
```cpp
pll merge(ll a, ll b, ll c, ll d) { // tanT1 = a / b, tanT2 = c / d, tan(T1 + T2) = ?
    return {
        (a * d % mod + b * c % mod) % mod,
        (b * d % mod - a * c % mod + mod) % mod
    };
}
```
리턴값도 (분자, 분모) 형태

## 좌표 계산
### 두 점 $(x1, x2), (y1, y2)$을 지나는 방정식 :   

$\dfrac {y - y1}{x - x1}= \dfrac{y2 - y1}{x2 - x1} \quad \Rightarrow \quad (y2 - y1)(x - x1) + (x1 - x2)(y - y1) = 0$   


```cpp
// ax + by + c = 0
a = y2 - y1;
b = x1 - x2;
c = -a * x1 - b * y1;
```

### 수선의 발, 대칭이동
<details>
<summary>식 정리 과정</summary>

(X, Y)에서 (x1, y1), (x2, y2)을 지나는 직선에 수선의 발 내린다고 하면   

$\dfrac{y_2 - y_1}{x_2 - x_1} \cdot \dfrac{y - Y}{x - X} = -1 \quad \Rightarrow \quad (y - Y)(y_2 - y_1) + (x - X)(x_2 - x_1) = 0$   

$\dfrac{y - y_1}{x - x_1} = \dfrac{y_2 - y_1}{x_2 - x_1} \quad \Rightarrow \quad (y_2 - y_1)(x - x_1) + (x_1 - x_2)(y - y_1) = 0$   

$let) \quad a = y_2 - y_1, \quad b = x_1 - x_2, \quad c = a Y - b X, \quad d = a x_1 + b y_1$   

$-bx + ay = c, \quad ax + by = d \quad \Rightarrow \quad \therefore x = \dfrac{-bc + ad}{a^2 + b^2}, \quad y = \dfrac{ac + bd}{a^2 + b^2}$   
</details>

```cpp
Point<ld> footPL(const Point<ld> &p, const Point<ld> &p1, const Point<ld> &p2) { // p에서 직선 p1p2에 내린 수선의발
    ld a = p2.y - p1.y;
    ld b = p1.x - p2.x;
    ld c = a * p.y - b * p.x;
    ld d = a * p1.x + b * p1.y;
    ld hx = (-b * c + a * d) / (a * a + b * b);
    ld hy = (a * c + b * d) / (a * a + b * b);
    return {hx, hy};
}

Point<ld> reflectPL(const Point<ld> &p, const Point<ld> &p1, const Point<ld> &p2) { // p의 직선 p1p2 기준 대칭이동
    auto [hx, hy] = footPL(p, p1, p2);
    return Point<ld>{2 * hx - p.x, 2 * hy - p.y};
}
```

### 방향 벡터 대칭이동
$(x, y)$의 $(a, b)$ 기준 대칭이동 : $((a^2 - b^2)(-x) - 2aby, (a^2 - b^2)(y) - 2abx)$

### 회전이동
```cpp
void rotate2D(ld &x, ld &y, ld theta) { // 반시계방향으로 theta만큼 회전
    tie(x, y) = pair<ld, ld>{cos(theta) * x + sin(theta) * y, -sin(theta) * x + cos(theta) * y};
}
```
<!-- TODO rotate3D추가해야 됨, 3D에서 z에 아무값넣어보내면 2D로도 쓸수있으니 3D만들고 나서 2D삭제하면 될 듯 -->

### 문제
[CCW](https://www.acmicpc.net/problem/11758) - CCW   
[쓰레기 슈트](https://www.acmicpc.net/problem/4225) - distance   