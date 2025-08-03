팀노트 25페이지안에 최대한 많이 넣으려면 코드줄바꿈이랑 코드길이 줄여야 됨..
###### 1. 클래스로 선언한 것들 전부 구조체로 바꾸고 접근 지정자 삭제
###### 2. for, if안에 코드 한줄인 경우 줄바꿈 X
###### 3. for { if { code }} 이런 형태도 중괄호 없이 한줄로 쓰기

<!-- ### 앞으로 할 거
  1. small to large
  1. simplex / LP dual
  1. 매트로이드
  1. PST
  1. hld
  1. centroid decomposition
  1. $\vdots$
  1. 스프라그 그런디
  1. $\vdots$
  1. DP 최적화들
  1. 리-차오
  1. 선형대수학 카테고리 추가

### 기존 문서에 추가할 거
  * [ ] 유니온파인드 `template <bool largeToSmall=false>` 추가
  * [ ] 오일러 회로 -> 오일러 경로
  * [ ] CHT DP -> lineContainer
  * [ ] 행렬제곱 -> $O(R^3 + RlogN)$ 구현

### 코드 테스트 안 끝난 거
  * [ ] 방향 그래프에서 오일러 회로

### 개선할 거
  * [ ] 그래프들 `addEdge()`함수 간선 양방향/단방향인지 `template <bool directed>`, `if constexpr`사용해서 수정
  * [ ] 회문 트리, 아호-코라식 배열구현에서 문자 종류 제한 개선(convertCharToIdx함수 추가)

### 추가 최적화
  * [x] FFT -> 비재귀로 변경
  * [x] FFT -> 비트뒤집기 최적화
  * [ ] FFT -> SSE/AVX최적화?
  * [ ] 행렬곱셈 -> 캐시 적중률 높이기
  * [ ] 세그먼트 트리 -> 사칙연산 비트연산으로 대체
  * [ ] LCA -> 캐시 적중률 높이기

### LaTeX 수식 형태 통일
  * [ ] 비교적 오래 전에 작성한 자료구조 문서들

## 리팩토링
### 코드, 폴더 구조
  * [ ] 기하학 도형 -> assert(size() >= 3); 추가
  * [ ] 스니펫 제목 크기 \#\#\# -> \#\#으로 변경

### 함수명 통일
  * [ ] splay tree -> lazy전파 함수
  * [ ] lazy propagation seg -> lazy전파 함수


### 변수명 통일
  * [ ] lca -> depth배열 이름 dep로 바꾸기
  * [ ] Dinic -> `template <typename F>` 대신 `template <typename flow_t>`나 `template <typename cap_t>`로 변경 -->