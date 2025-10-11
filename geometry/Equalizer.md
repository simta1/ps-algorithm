[카테고리](/README.md)
## 등적등주 분할(Equalizer)
### [기하학 헤더](/기하학/Geometry%20Header.md)
<details>
<summary>Point, Distance, Area</summary>

```cpp
template <typename T>
struct Point {
    T x, y;
};

template <typename T>
T distPP(const Point<T> &p1, const Point<T> &p2) { // distance from P(point) to P(point)
    return sqrtl((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

template <typename T>
inline ld getTriangleArea(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
    return 0.5l * fabsl(a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
}

template <typename T>
inline ld getRectangleArea(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3, const Point<T> &p4) {
    return getTriangleArea(p1, p2, p3) + getTriangleArea(p1, p4, p3);
}
```
</details>

### Polygon Equalizer
```cpp
class Polygon {
private:
    using Division = pair<int, ld>; // idx, rate
    
    int n;
    vector<Point<ld> > points;
    vector<ld> perim, pfsPerim;
    vector<ld> pfsArea;
    ld totPerim, totArea;

    ld getPerimCoor(const Division &cur) {
        auto [curIdx, curRate] = cur;
        assert(curIdx < n);
        return pfsPerim[curIdx] + curRate * perim[(curIdx + 1) % n];
    }

    Division getDivision(const Division &dvs, ld targetDiff) {
        ld targetPerimCoor = getPerimCoor(dvs) + targetDiff;
        int foundIdx = upper_bound(pfsPerim.begin(), pfsPerim.end(), targetPerimCoor) - pfsPerim.begin() - 1;

        ld needLen = targetPerimCoor - pfsPerim[foundIdx];
        ld totLen = pfsPerim[foundIdx + 1] - pfsPerim[foundIdx];
        return {foundIdx, needLen / totLen};
    }

    inline Division getOpponentDivision(const Division &dvs) {
        return getDivision(dvs, totPerim / 2);
    }

    Point<ld> divisionToPoint(const Division &dvs) {
        auto [i, r] = dvs;
        auto [x1, y1] = points[i % n];
        auto [x2, y2] = points[(i + 1) % n];
        return {(1.0 - r) * x1 + r * x2, (1.0 - r) * y1 + r * y2};
    }

    int f(const Division &dvs) {
        auto oppDvs = getOpponentDivision(dvs);
        auto p1 = divisionToPoint(dvs);
        auto p2 = divisionToPoint(oppDvs);

        int i1 = (dvs.first + 1) % n;
        int i2 = oppDvs.first % n;

        ld splitedArea = getRectangleArea(p1, points[i1], points[i2], p2);
        if (i1 <= i2) splitedArea += pfsArea[i2] - pfsArea[i1] - getTriangleArea(points[0], points[i1], points[i2]);
        else splitedArea += totArea - (pfsArea[i1] - pfsArea[i2] - getTriangleArea(points[0], points[i1], points[i2]));

        ld diff = splitedArea - totArea / 2;
        return (diff > 0) - (diff < 0);
    }

public:
    Polygon(int n) : n(n), points(n), perim(n), pfsPerim(2 * n + 2), pfsArea(n) {
        for (auto &[x, y] : points) cin >> x >> y;

        for (int i = 0, j = n - 1; i < n; j = i++) perim[i] = distPP(points[j], points[i]);
        for (int i = 1; i <= pfsPerim.size(); i++) pfsPerim[i] = pfsPerim[i - 1] + perim[i % n];
        
        for (int i = 2; i < n; i++) {
            pfsArea[i] = getTriangleArea(points[0], points[i - 1], points[i]);
            pfsArea[i] += pfsArea[i - 1];
        }
        
        totPerim = pfsPerim[n];
        totArea = pfsArea.back();
    }

    tuple<int, ld, int, ld> getEqualizer() {
        Division lo = {0, 0}, hi = getOpponentDivision(lo);

        ld distDiff = fabsl(getPerimCoor(hi) - getPerimCoor(lo));
        const ld eps = 1e-7;
        while (distDiff > eps) {
            Division mid = getDivision(lo, distDiff / 2);
            if (f(mid) * f(hi) > 0) hi = mid;
            else lo = mid;
            distDiff /= 2;
        }
        
        auto [i1, r1] = lo;
        auto [i2, r2] = getOpponentDivision(lo);

        assert(0 <= r1 && r1 <= 1 && 0 <= r2 && r2 <= 1);
        // r1 = constrain(r1, 0, 1);
        // r2 = constrain(r2, 0, 1);

        return {i1, r1, i2, r2};
    }
};
```
### 시간복잡도
$O(N + logN ~ log\frac{N}{\epsilon})$   
(누적합 없이 naive로 구현할 경우 $O(N ~ log\frac{N}{\epsilon})$ )   

### 사용설명
ld랑 eps 필요한만큼 조절해서 사용

### 문제
[반 나누기 (Hard)](https://www.acmicpc.net/problem/31397)   