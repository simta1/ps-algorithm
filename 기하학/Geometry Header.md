[카테고리](/README.md)
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

### isBetween
```cpp
template <typename T>
bool isBetween(Point<T> a, Point<T> b, Point<T> c) {
    return min(a.x, c.x) <= b.x && b.x <= max(a.x, c.x) && min(a.y, c.y) <= b.y && b.y <= max(a.y, c.y);
}
```

### isOnPL
```cpp
```

### 주의사항
좌표들을 곱셈하기 때문에 overflow 고려할 땐 좌표의 최대값의 제곱을 기준으로 판단

### 백준문제
[CCW](https://www.acmicpc.net/problem/11758) - CCW   
[쓰레기 슈트](https://www.acmicpc.net/problem/4225) - distance   

### 원리
p1p2와 p3 사이 거리(수선의 발이 선분 위에 있을 때)   
$(y_2 - y_1)(x - x_1) - (x_2 - x_1)(y - y_1) = 0$   
$(x_3, y_3)$에서 거리
$\frac{|(y_2 - y_1)(x_3 - x_1) - (x_2 - x_1)(y_3 - y_1)|}{\sqrt{(y_2 - y_1) ^ 2 + (x_2 - x_1) ^ 2}} = \frac{|cp(p3 - p1, p2 - p1)|}{dist(p_1, p_2)}$