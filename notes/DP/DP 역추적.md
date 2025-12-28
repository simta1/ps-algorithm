[카테고리](/README.md)
## 최단거리 역추적
```cpp
function<void()> trace = [&](int ) {

};
```
### 시간복잡도
$O()$   

### 구현 주의사항
bottom-up으로 dp배열의 모든 값을 구해놓은 게 아니라 재귀함수 `getDp()`로 구한 경우라면 모든 dp값이 채워지지 않았을 수 있음에 주의   
trace에서 dp값을 확인할 땐 `dp[i]`로 직접 배열에 접근하지 말고 `getDp(i)`로 확인해야 안전함   

### 사용설명


### 문제
[경찰차](https://www.acmicpc.net/problem/2618)   

### 원리


### 참고링크