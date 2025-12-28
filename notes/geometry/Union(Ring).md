[카테고리](/README.md)
## Union of Rings
```cpp
const ld PI = acos(-1);

template <typename T> inline T sq(T x) { return x * x; }

template <typename T>
pair<ld, ld> intersectionCC(T x1, T y1, T r1, T x2, T y2, T r2) {
    T distSquare = sq(x2 - x1) + sq(y2 - y1);

    ld cosTheta = ld(sq(r1) + distSquare - sq(r2)) / (2 * r1 * sqrt(ld(distSquare)));
    ld theta = acos(min<ld>(1, max<ld>(-1, cosTheta)));
    ld alpha = atan2<ld>(y2 - y1, x2 - x1);

    ld theta1 = alpha - theta; // -2 * PI <= <= PI
    if (theta1 < 0) theta1 += 2 * PI;
    ld theta2 = alpha + theta; // -PI <= <= 2 * PI
    if (theta2 < 0) theta2 += 2 * PI;

    return {theta1, theta2};
}

template <typename T>
ld ringUnionArea(const vector<tuple<T, T, T, T> > &circles) { // tuple 구조는 x, y, D, d 순서 // D+d가 겉반지름, D-d가 속반지름을 의미
    int n = circles.size();

    auto arcIntegral = [](T x, T y, T r, ld theta1, ld theta2) {
        return r * ld(0.5) * (x * (sin(theta2) - sin(theta1)) - y * (cos(theta2) - cos(theta1)) + r * (theta2 - theta1));
    };

    ld res = 0;
    for (int _i = 0; _i < 2 * n; _i++) {
        int i = _i / 2;
        auto [x1, y1, D1, d1] = circles[i];
        
        T r1 = (_i & 1) ? (D1 + d1) : (D1 - d1);
        if (r1 <= 0) continue;

        vector<pair<ld, ld> > thetas;

        auto pushInterval = [&thetas, &PI](ld theta1, ld theta2) {
            if (theta1 <= theta2) thetas.emplace_back(theta1, theta2);
            else {
                thetas.push_back({theta1, 2 * PI});
                thetas.push_back({0, theta2});
            }
        };

        for (int j = 0; j < n; j++) if (i != j) {
            auto [x2, y2, D2, d2] = circles[j];

            T R2 = D2 + d2;
            T r2 = max(0, D2 - d2);
            T distSquare = sq(x2 - x1) + sq(y2 - y1);
            if (r2 == 0) { // 안쪽고리 없음
                if (distSquare >= sq(r1 + R2)) continue;
                else if (distSquare > sq(r1 - R2)) {
                    auto [theta1, theta2] = intersectionCC(x1, y1, r1, x2, y2, R2);
                    pushInterval(theta1, theta2);
                }
                else if (distSquare == sq(r1 - R2)) {
                    if (r1 < R2) thetas.emplace_back(0, 2 * PI);
                    else if (r1 > R2) continue;
                    else { // 바깥쪽 고리랑 동일한 원
                        if (r1 == D1 + d1) {
                            if (i < j) continue;
                            else thetas.emplace_back(0, 2 * PI);
                        }
                        else thetas.emplace_back(0, 2 * PI);
                    }
                }
                else if (distSquare < sq(r1 - R2)) {
                    assert (r1 != R2);
                    if (r1 < R2) thetas.emplace_back(0, 2 * PI);
                    else continue;
                }
            }
            else if (distSquare > sq(r1 + r2)) { // 안쪽고리 외부
                if (distSquare >= sq(r1 + R2)) continue;
                else if (distSquare <= sq(r1 - R2)) thetas.emplace_back(0, 2 * PI);
                else {
                    auto [theta1, theta2] = intersectionCC(x1, y1, r1, x2, y2, R2);
                    pushInterval(theta1, theta2);
                }
            }
            else if (distSquare == sq(r1 + r2)) { // 안쪽고리 외접
                if (distSquare >= sq(r1 + R2)) assert(false);
                else if (distSquare <= sq(r1 - R2)) thetas.emplace_back(0, 2 * PI);
                else {
                    auto [theta1, theta2] = intersectionCC(x1, y1, r1, x2, y2, R2);
                    pushInterval(theta1, theta2);
                }
            }
            else if (distSquare > sq(r1 - r2)) { // 안쪽고리 교점2개
                auto [theta3, theta4] = intersectionCC(x1, y1, r1, x2, y2, r2);
                if (distSquare >= sq(r1 + R2)) assert(false);
                else if (distSquare <= sq(r1 - R2)) pushInterval(theta4, theta3);
                else {
                    auto [theta1, theta2] = intersectionCC(x1, y1, r1, x2, y2, R2);
                    pushInterval(theta1, theta3);
                    pushInterval(theta4, theta2);
                }
            }
            else if (distSquare == sq(r1 - r2)) { // 안쪽고리 내접
                if (r1 < r2) continue;
                else if (r1 > r2) {
                    if (distSquare >= sq(r1 + R2)) assert(false);
                    else if (distSquare <= sq(r1 - R2)) thetas.emplace_back(0, 2 * PI);
                    else {
                        auto [theta1, theta2] = intersectionCC(x1, y1, r1, x2, y2, R2);
                        pushInterval(theta1, theta2);
                    }
                }
                else { // 안쪽고리랑 동일한 원
                    if (r1 == D1 + d1) thetas.emplace_back(0, 2 * PI);
                    else {
                        if (i < j) continue;
                        else thetas.emplace_back(0, 2 * PI);
                    }
                }
            }
            else if (distSquare < sq(r1 - r2)) { // 안쪽고리 포함
                assert (r1 != r2); // 안쪽고리랑 동일한 원일 수는 없음
                if (r1 < r2) continue;
                else { // r1 > r2
                    if (distSquare >= sq(r1 + R2)) assert(false);
                    else if (distSquare > sq(r1 - R2)) {
                        auto [theta1, theta2] = intersectionCC(x1, y1, r1, x2, y2, R2);
                        pushInterval(theta1, theta2);
                    }
                    else if (distSquare == sq(r1 - R2)) {
                        if (r1 < R2) thetas.emplace_back(0, 2 * PI);
                        else if (r1 > R2) continue;
                        else { // 바깥쪽 고리랑 동일한 원
                            if (r1 == D1 + d1) {
                                if (i < j) continue;
                                else thetas.emplace_back(0, 2 * PI);
                            }
                            else thetas.emplace_back(0, 2 * PI);
                        }
                    }
                    else {
                        assert (r1 != R2);
                        if (r1 < R2) thetas.emplace_back(0, 2 * PI);
                        else continue;
                    }
                }
            }
            else assert(false);
        }

        sort(thetas.begin(), thetas.end());
        thetas.emplace_back(2 * PI, 2 * PI);
        
        ld curArea = 0, curE = 0;
        for (auto [s, e] : thetas) {
            if (curE < s) curArea += arcIntegral(x1, y1, r1, curE, s);
            curE = max(curE, e);
        }
        
        res += ((r1 == D1 + d1) ? 1 : -1) * curArea;
    }

    return res;
}
```
### 시간복잡도
$O(N^2 \log{N})$   

### 문제
[Cleaning the Hallway](https://www.acmicpc.net/problem/9598)

### 원리
![원리](https://github.com/user-attachments/assets/99e60775-ae24-4f87-9501-092b18c37a4c)