[카테고리](/README.md)
##### [Point, Cross Product, CCW](/기하학/Cross%20Product,%20CCW.md)
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

template <typename T>
int ccw(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3) { // -1 : 시계, 0 : 일직선, 1 : 반시계
    T cp = crossProduct(p2 - p1, p3 - p1);
    return (cp > 0) - (cp < 0);
}
```
### Point in Polygon
```cpp
template <typename T>
int checkPointInPolygon(const vector<Point<T> > &polygon, const Point<T> &point) { // -1 : 내부, 0 : 경계, 1 : 외부
    int n = polygon.size();
    assert(n >= 3);

    bool inside = false;
    auto isBetween = [](T a, T b, T c) { return min(a, c) <= b && b <= max(a, c); };

    for (int i = 0, j = n - 1; i < n; j = i++) {
        const auto &p1 = polygon[i];
        const auto &p2 = polygon[j];

        // 다각형 경계
        if (ccw(p1, point, p2) == 0 && isBetween(p1.x, point.x, p2.x) && isBetween(p1.y, point.y, p2.y)) return 0;

        // 다각형 내부
        if (min(p1.y, p2.y) <= point.y && point.y < max(p1.y, p2.y)) {
            if (p1.y < p2.y) inside ^= ccw(p1, p2, point) < 0;
            else inside ^= ccw(p2, p1, point) < 0;
        }
    }

    return 1 - 2 * inside;
}
```
### 시간복잡도 
$O(N)$   
볼록다각형에선 [$O(logN)$ 알고리즘](/기하학/Point%20In%20Convex%20Polygon.md) 존재   

### 주의사항
다각형 내부 확인할 때 한 쪽 부등호에만 등식 포함   
```cpp
// 꼭짓점 고려 안 됨
if (min(p1.y, p2.y) < point.y && point.y < max(p1.y, p2.y))

// 꼭짓점 중복 고려
if (min(p1.y, p2.y) <= point.y && point.y <= max(p1.y, p2.y))

// 옳은 코드
if (min(p1.y, p2.y) <= point.y && point.y < max(p1.y, p2.y))
```

### 사용관련
오목/볼록 상관없이 단순다각형이라면 전부 사용 가능   
나눗셈 없이 ccw로 구현해서 Point<int> 등 정수형에서도 오차 없이 작동

### 백준문제
[지민이의 테러](https://www.acmicpc.net/problem/1688)

### 원리
point에서 양의 x축 방향으로 뻗은 기울기 0의 반직선과 다각형의 변($\overline{p_1p_2}$)이 교차하는지 확인   
일단 반직선 대신 직선으로 생각 : point.y가 p1.y와 p2.y 사이 값이라면 무조건 교차   
반직선과의 교차를 확인하려면 추가로 $\overline{p_1p_2}$와 point의 방향 관계를 ccw로 확인   

### 참고문헌
https://anz1217.tistory.com/107   