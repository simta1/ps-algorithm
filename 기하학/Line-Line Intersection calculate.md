[카테고리](/README.md)
### Line-Line Intersection Calculate
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
void printIntersection(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4) {
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
### 시간복잡도 
$O(1)$   

### 주의사항
좌표들을 곱셈하기 때문에 overflow 고려할 땐 좌표의 최대값의 제곱을 기준으로 판단

### 백준문제
[선분 교차 3](https://www.acmicpc.net/problem/20149)

### 원리