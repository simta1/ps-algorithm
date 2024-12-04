[카테고리](/README.md)
## Union
```cpp
template <typename T> inline T sq(T x) { return x * x; }

template <typename T>
ld circleUnionArea(const vector<tuple<T, T, T> > &circles) { // tuple 구조는 x, y, r 순서
    int n = circles.size();

    const ld PI = acos(-1);

    auto arcIntegral = [](T x, T y, T r, ld theta1, ld theta2) {
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

            T distSquare = sq(x2 - x1) + sq(y2 - y1);
            if (distSquare >= sq(r1 + r2)) continue; // 외접 or 교점 없는 경우
            if (distSquare <= sq(r2 - r1)) { // 내접
                if (r1 == r2) { // 두 원이 완전히 겹친 경우 그 중 하나만 고려
                    if (i > j) { // 나중에 나오는 원이면 계산 안 함
                        thetas.push_back({0, 2 * PI});
                        break;
                    }
                    else continue; // 먼저 나온 원
                }
                else { // 내접하는 경우 큰 원에서만 계산
                    if (r1 < r2) { // 작은 원이면 계산 안 함
                        thetas.push_back({0, 2 * PI});
                        break;
                    }
                    else continue; // 큰 원
                }
            }

            ld cosTheta = ld(sq(r1) + distSquare - sq(r2)) / (2 * r1 * sqrt(ld(distSquare)));
            ld theta = acos(min<ld>(1, max<ld>(-1, cosTheta)));
            ld alpha = atan2<ld>(y2 - y1, x2 - x1);

            ld theta1 = alpha - theta; // -2 * PI <= <= PI
            if (theta1 < 0) theta1 += 2 * PI;
            ld theta2 = alpha + theta; // -PI <= <= 2 * PI
            if (theta2 < 0) theta2 += 2 * PI; // theta2==2*PI일 경우 0으로 해줘도 되지만 안해도 결과 똑같음, 밑에 if문에 경우나눠서 생각해보면 결과 똑같은 거 알 수 있음
            
            // 반시계방향, 즉 theta1->theta2 로 적분해야 함이 자명함

            if (theta1 > theta2) {
                thetas.push_back({theta1, 2 * PI});
                thetas.push_back({0, theta2});
            }
            else thetas.push_back({theta1, theta2});
        }

        sort(thetas.begin(), thetas.end());
        thetas.push_back({2 * PI, 2 * PI});
        
        ld curE = 0;
        for (auto [s, e] : thetas) {
            if (curE < s) res += arcIntegral(x1, y1, r1, curE, s);
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