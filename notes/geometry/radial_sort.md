[카테고리](/README.md)
## Radial sort
```cpp
auto checkQuadrant = [](const Point &p) -> bool {
	return p.y < 0 || (p.y == 0 && p.x < 0); // PI <= atan2(p) < 2 * PI
};

sort(planes.begin(), planes.end(), [&](const Point &a, const Point &b) {
	bool aq = checkQuadrant(a), bq = checkQuadrant(b);
	if constexpr (isCCW) return aq != bq ? aq < bq : crossProduct(a, b) > 0;
	else return aq != bq ? aq < bq : crossProduct(a, b) < 0;
});
```
### 시간복잡도
$O(N \log{N})$   

### 원리
1,2사분면과 3,4사분면을 분리해 계산   
checkQuadrant의 값이 같을 땐 최대각도가 180도 미만이므로 ccw를 사용해도 순서가 꼬이지 않음   
