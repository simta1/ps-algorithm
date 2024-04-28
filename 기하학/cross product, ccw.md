[카테고리](/README.md)
### Point 구조체
```cpp
template <typename T>
struct Point {
    T x, y;

    bool operator<(const Point &other) const { return x == other.x ? y < other.y : x < other.x; }
    bool operator<=(const Point &other) const { return x == other.x ? y <= other.y : x <= other.x; }
    bool operator==(const Point &other) const { return x == other.x && y == other.y; }
    Point operator-(const Point &other) const { return {x - other.x, y - other.y}; }
};
```
### Cross Product
```cpp
template <typename T>
T crossProduct(Point<T> p1, Point<T> p2) {
    return (p1.x * p2.y - p2.x * p1.y);
}
```
### CCW
```cpp
template <typename T>
int ccw(Point<T> p1, Point<T> p2, Point<T> p3) {
    T cp = crossProduct(p2 - p1, p3 - p1);
    return (cp > 0) - (cp < 0);
}
```
### 주의사항
좌표들을 곱셈하기 때문에 overflow 고려할 땐 좌표의 최대값의 제곱을 기준으로 판단

### 백준문제
[CCW](https://www.acmicpc.net/problem/11758)