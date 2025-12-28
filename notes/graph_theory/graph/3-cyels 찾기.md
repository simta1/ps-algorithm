[카테고리](/README.md)
## 삼각형, 사각형 찾기
```cpp

```
### 시간복잡도
$O()$   

### 구현 주의사항


### 사용설명


### 문제
[]()

### 원리
정점 v의 차수를 $\deg(v)$라 할 때 $\sum_{uv \in E} \min(\deg(u), \deg(v))$ = $O(m \sqrt m)$   

$\because$   
$\sum_{v \in V} \deg(v) = 2m$이므로 $\deg(v) \geq \sqrt m$인 정점은 많아야 $O(\sqrt m)$개   
단순그래프이므로 $\min(\deg(u), \deg(v)) \geq \sqrt m$인 간선은 많아야 $O(m)$개   
나머지 간선은 $\min(\deg(u), \deg(v)) \leq \sqrt m$ ■   

### 참고링크
https://jh05013.github.io/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/%EC%82%BC%EA%B0%81%ED%98%95%20%EC%B0%BE%EA%B8%B0/    
https://judge.yosupo.jp/problem/counting_c4   