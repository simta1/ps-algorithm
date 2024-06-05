[카테고리](/README.md)
##### [Point, Cross Product](/기하학/Cross%20Product,%20CCW.md)
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
```
### distance from line to point
```cpp
template <typename T>
T distPP(const Point<T> &p1, const Point<T> &p2) { // distance from P(point) to P(point)
    return sqrtl((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

template <typename T>
T distLP(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3) { // distance from L(line, p1p2) to P(point, p3)
    return crossProduct(p2 - p1, p3 - p1) / distPP(p1, p2);
}
```
### 사용관련
p1 == p2일 때 distLP() 사용하면 division by 0 에러남

### 백준문제
[쓰레기 슈트](https://www.acmicpc.net/problem/4225)

### 원리
[좌표 계산](/수학/Coordinates.md)