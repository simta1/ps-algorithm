[카테고리](/README.md)
### Point in Convex Polygon
```cpp
template <typename T>
int checkPointInPolygon(const vector<Point<T> > &polygon, const Point<T> &point, int dir=0) { // -1 : 내부, 0 : 경계, 1 : 외부
    int n = polygon.size();
    assert(n >= 3);

    if (!dir) {
        int i = 2;
        while (!dir) dir = ccw(polygon[0], polygon[1], polygon[i++]);
    }

    if (ccw(polygon[0], polygon[1], point) * dir < 0) return 1;
    if (ccw(polygon[0], polygon[n - 1], point) * dir > 0) return 1;

    int lo = 1, hi = n;
    while (lo + 1 < hi) {
        int mid = lo + hi >> 1;
        if (ccw(polygon[0], polygon[mid], point) * dir >= 0) lo = mid;
        else hi = mid;
    }

    if (hi == n) { // polygon[0], polygon[n - 1], point가 일직선인 경우
        T res = fabsl(point.x - polygon[0].x) - fabsl(polygon[lo].x - polygon[0].x);
        return (res > 0) - (res < 0);
    }

    return -ccw(polygon[lo], polygon[hi], point) * dir;
}
```
### 시간복잡도 
$O(logN)$   

### 사용관련
오목다각형에선 사용 불가   

dir은 polygon에서 점들이 주어진 방향(반시계 : 1, 시계 : -1, 모르는 경우(default) : 0)   
dir모르는 경우 그냥 checkPoint(polygon, point)로 호출   

### 백준문제
[미스테리 싸인](https://www.acmicpc.net/problem/20670)

### 참고문헌
https://velog.io/@vkdldjvkdnj/boj09875   
https://anz1217.tistory.com/107