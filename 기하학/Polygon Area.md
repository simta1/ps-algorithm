[카테고리](/README.md)
### Polygon Area
```cpp
template <typename T>
ld getTriangleArea(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
    return 0.5l * fabsl(a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
}

template <typename T>
ld getPolygonArea(const vector<Point<T> > &polygon) {
    if (polygon.size() <= 2) return 0;

    ld res = 0;
    for (int i = 2; i < polygon.size(); i++) res += getTriangleArea(polygon[0], polygon[i - 1], polygon[i]);
    return res;
}
```
### 시간복잡도
$O(N)$   

### 사용관련
볼록다각형에서만 테스트 한 코드임   
오목다각형은 테스트 안 했음   

### 백준문제
[넓이](https://www.acmicpc.net/problem/1077)