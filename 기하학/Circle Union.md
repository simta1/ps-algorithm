[카테고리](/README.md)
## Union
```cpp
template <typename T> inline T sq(T x) { return x * x; }

template <typename T>
ld circlesUnion(const vector<tuple<T, T, T> > &circles) { // tuple 구조는 x, y, r 순서
    int n = circles.size();

    const ld PI = acos(-1);
    auto constrain = [&PI](ld theta) {
        return theta < 0 ? theta + 2 * PI : theta > 2 * PI ? theta - 2 * PI : theta;
    };

    auto lineIntegral = [](T x, T y, T r, ld theta1, ld theta2) {
        return r * ld(0.5) * (x * (sin(theta2) - sin(theta1)) - y * (cos(theta2) - cos(theta1)) + r * (theta2 - theta1));
    };

    ld res = 0;
    for (int i = 0; i < n; i++) {
        auto [x1, y1, r1] = circles[i];
        if (r1 <= 0) continue;

        vector<pair<ld, ld> > thetas;
        
        for (int j = 0; j < n; j++) if (j != i) {
            auto [x2, y2, r2] = circles[j];
            if (r2 <= 0) continue;

            ld distSquare = sq(x2 - x1) + sq(y2 - y1);
            if (distSquare >= sq(r1 + r2)) continue; // 외접 or 교점 없는 경우
            if (distSquare <= sq(r2 - r1)) { // 내접
                if (r1 == r2) { // 두 원이 완전히 겹친 경우 그 중 하나만 고려
                    r2 = 0;
                    continue;
                }
                else { // 내접하는 경우 큰 원에서만 계산
                    if (r1 < r2) { // 작은 원이면 계산 안 함
                        thetas.push_back({0, 2 * PI});
                        break;
                    }
                    else continue; // 큰 원
                }
            }

            ld theta = acos((sq(r1) + distSquare - sq(r2)) / (2 * r1 * sqrt(distSquare)));
            ld alpha = atan2(y2 - y1, x2 - x1);

            auto theta1 = constrain(alpha + theta);
            auto theta2 = constrain(alpha - theta);

            if (sq(x1 + r1 - x2) + sq(y1 - y2) <= sq(r2)) {
                thetas.push_back({0, min(theta1, theta2)});
                thetas.push_back({max(theta1, theta2), 2 * PI});
            }
            else thetas.push_back({min(theta1, theta2), max(theta1, theta2)});
        }

        sort(thetas.begin(), thetas.end());
        thetas.push_back({2 * PI, 2 * PI});
        
        ld curE = 0;
        for (auto [s, e] : thetas) {
            if (curE < s) res += lineIntegral(x1, y1, r1, curE, s);
            curE = max(curE, e);
        }
    }

    return res;
}
```
### 시간복잡도
$O(N^2 \log{N})$   

### 구현 주의사항
두 원이 완전히 겹치는 경우엔 그 중 하나의 원만 선적분   
하나의 원이 다른 원에 내접하는 경우 큰 원만 선적분   

### 문제
[Knocked Ink](https://www.acmicpc.net/problem/17804)

### 원리
[그린 정리](/기하학/그린%20정리.md)   
$x=x_c+r \cos \theta, y=y_c+r \sin \theta$   

$S = \dfrac{1}{2}\displaystyle\oint (x \, dy - y \, dx)=\dfrac{r}{2}\left[ x_c \sin\theta - y_c \cos\theta + r \theta \right]_{{\theta}_1}^{{\theta}_2}$

### 참고링크
https://infossm.github.io/blog/2022/09/18/shape-union/   
https://xy-plane.tistory.com/22   