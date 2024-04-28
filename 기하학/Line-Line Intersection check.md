[카테고리](/README.md)
### Line-Line Intersection Check
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
T crossProduct(Point<T> p1, Point<T> p2) {
    return (p1.x * p2.y - p2.x * p1.y);
}

template <typename T>
int ccw(Point<T> p1, Point<T> p2, Point<T> p3) {
    T cp = crossProduct(p2 - p1, p3 - p1);
    return (cp > 0) - (cp < 0);
}

template <typename T>
bool checkIntersect(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4) {
    int a = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int b = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (a > 0 || b > 0) return false;
    if (a < 0 || b < 0) return true;
    return min(p1, p2) <= max(p3, p4) && min(p3, p4) <= max(p1, p2);
}
```
### 시간복잡도 
$O(1)$   

### 주의사항
ccw에서 좌표들을 곱셈하기 때문에 overflow 고려할 땐 좌표의 최대값의 제곱을 기준으로 판단

### 사용관련
checkIntersect()는 선분 p1p2, 선분 p3p4의 교차 여부 확인

### 백준문제
[선분 교차 2](https://www.acmicpc.net/problem/17387)