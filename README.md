<style>   
  .bronze { background-color:#CE8946 }   
  .silver { background-color:#C5D5D5 }   
  .gold { background-color:#FFF5B1 }   
  .platinum { background-color:#DCFFE4 }   
  .diamond { background-color:#C0FFFF }   
  .ruby { background-color:#FFC0C0 }   
  .additional { background-color:#E4BBFE }   
  .information { background-color:#ABCDEF }   
</style>   
<!-- ### 코드 작성
변수명 통일 -> [참고](/C++%20관련%20정보들/기타/Variable%20Name.md)   
vector쓸 땐 array doubling 고려   
매개변수로 vector나 string 받을 땐 가능하면 최대한 상수 참조 사용   

### 카테고리 작성
css로 티어색깔 표시. \<span class="tier"> 사용   
알고리즘의 난이도는 1\~3은 +, 4\~5는 -로 표시   
백준에 단일 태그로 존재하는 주요 알고리즘이나 유명한 트릭이 아닌, 지엽적이거나 추가적인 구현체는 _이텔릭체_ 로 표시   
별로 중요하지 않거나 구현계획 없는 알고리즘은 ~~취소선~~으로 표시

### 문서 작성
VSC markdown.json에서 문서 작성용 템플릿 스니펫 사용   
__주의사항__ 에 코드 작성하면서 겪었던 런타임 에러나 오류들 기록   
코드를 사용할 때의 주의사항이 아니라 해당 코드 구현하면서 겪은 주의사항을 기록   
__시간복잡도__ 는 LaTeX 수식 사용. log(N)은 괄호 없이 logN으로 표기   
__사용관련__ 은 코드 사용할 때 참고할 내용 기록   
__백준문제__ 에는 혹시 코드 수정하게 됐을 때 테스트해볼 수 있도록 문제 링크 적어두기   

### 그래프 작성
카테고리에 있는 알고리즘 중 문서 작성 완료된 것들만 그래프에 포함   
mermaid stateDiagram-v2 사용   

## -->
# time complexity
| constraints           | time complexity                           | algorithm                                             |
|-----------------------|-------------------------------------------|-------------------------------------------------------|
| $n \le 12$            | $O(n!)$                                   |                                                       |
| $n \le 25$            | $O(2^n)$, $O(n^2 \cdot 2^n)$              |                                                       |
| $n \le 50$            | $O(\sqrt2^n)$                             |                                                       |
| $n \le 100$           | $O(n^4)$                                  |                                                       |
| $n \le 500$           | $O(n^3)$                                  |                                                       |
| $n \le 5,000$         | $O(n^2)$                                  |                                                       |
| $n \le 100,000$       | $O(n \sqrt n)$, $O(n \log^2n)$            |                                                       |
| $n \le 1,000,000$     | $O(n \log n)$                             |                                                       |
| $n \le 5,000,000$     | $O(n \log n)$                             | SegmentTree(bottom-up only)                           |
| $n \le 100,000,000$   | $O(n)$                                    |                                                       |
| $n \gt 10^8 $         | $O(logn)$, $O(1)$                         |                                                       |

# ps algorithm
티어 분류 :
<span class="silver">실버(S)<span>
<span class="gold">골드(G)<span>
<span class="platinum">플레(P)<span>
<span class="diamond">다이아(D)<span>
<span class="ruby">루비(R)<span>
<span class="additional">기타(A)<span>

* ### 자료구조
    <span class="information">[자료구조 구현할 때 주의사항](/자료구조/주의사항.md)</span>
  * #### 세그먼트 트리
    <!-- 펜윅으로 머지소트 트리 대체? https://codeforces.com/blog/entry/107849 -->
    <!-- * <span class="">[비재귀 레이지 세그]</span> -->
    <!-- https://www.acmicpc.net/blog/view/117 -->
    <!-- 펜윅 레이지 + 역원없는 연산 지원 버전 만들까 싶었으나 솔직히 너무 과한 듯. 다이나믹 레이지 세그가 너무 막강함 -->
    * <span class="gold">[펜윅 트리(G+)](/자료구조/세그먼트%20트리/펜윅.md)</span>
    * <span class="gold">[세그먼트 트리(G+)](/자료구조/세그먼트%20트리/세그.md)</span>
    * <span class="gold">[비재귀 세그(G+)](/자료구조/세그먼트%20트리/비재귀%20세그.md)</span>
    * <span class="platinum">[세그 이분 탐색(P-)](/자료구조/세그먼트%20트리/세그%20이분%20탐색.md)</span>
    * <span class="platinum">[2D 펜윅(P-)](/자료구조/세그먼트%20트리/2차원%20펜윅.md)</span>
    * <span class="platinum">[2D 세그(P-)](/자료구조/세그먼트%20트리/2차원%20세그.md)</span>
    * <span class="platinum">[n차원 펜윅(P-)](/자료구조/세그먼트%20트리/다차원%20펜윅.md)</span>
    * <span class="platinum">[머지소트 트리(P-)](/자료구조/세그먼트%20트리/머지소트%20트리.md)</span>
    * <span class="platinum">[레이지 세그(P-)](/자료구조/세그먼트%20트리/레이지%20세그.md)</span>
    * <span class="platinum">[다이나믹 세그(P-)](/자료구조/세그먼트%20트리/다이나믹%20세그.md)</span>
    * <span class="platinum">[다이나믹 레이지 세그(P+)](/자료구조/세그먼트%20트리/다이나믹%20레이지%20세그.md)</span>
    * ~~<span class="platinum">[_range GCD 세그(P+)_](/자료구조/세그먼트%20트리/GCD%20세그.md)</span>~~
    * <span class="platinum">[금광 세그(P+)](/자료구조/세그먼트%20트리/금광%20세그.md)</span>
    * <span class="">[퍼시스턴트 세그(P+)]</span>
    * <span class="">[세그트리 비츠(D+)]</span>
  * #### BBST
    * <span class="">[treap]</span>
    * <span class="diamond">[스플레이 트리(D-)](/자료구조/BBST/SplayTree.md)</span>
    * <span class="">[링크/컷 트리(D+)]</span>
    * <span class="">[레드-블랙 트리]</span>
  * #### 기타
    * <span class="gold">[유니온 파인드(G-)](/자료구조/기타/DSU.md)</span>
    * <span class="">[유니온 파인드 롤백]</span>
    * <span class="gold">[희소 배열(G+)](/자료구조/기타/희소배열.md)</span>
    * <span class="platinum">[XOR 트라이(P-)](/자료구조/기타/XOR%20Trie.md)</span>
    * <span class="platinum">[유니온 파인드 with Potential(P+)](/자료구조/기타/DSU%20potential.md)</span>
    * <span class="platinum">[로프(P-)](/자료구조/기타/rope.md)</span>
    * <span class="platinum">[ordered set(P-)](/자료구조/기타/ordered_set.md)</span>
    * <span class="">[데카르트 트리]</span>
    * <span class="">[Line container]</span>
    * <span class="">[리-차오 트리(D-)]</span>
    <!-- * <span class="">[weighted QU]</span> -->
    <!-- * <span class="">[B-tree]</span>
    * <span class="">[SPQR tree]</span>
    * <span class="">[PQ tree]</span>
    https://infossm.github.io/blog/2021/10/20/PQ_Tree_Part_1/
    * <span class="">[treap]</span>
    * <span class="">[wavelet 트리(P+)]</span> -->
* ### [그래프 이론](/그래프%20이론/개념%20정리.md)
  * #### 그래프
    <!-- https://ps.mjstudio.net/tip-bfs-fill -->
    <!-- * <span class="">[온라인 동적 연결성 판정]</span> -->
    * <span class="">[flood fill]</span>
    * <span class="">[0-1 bfs(G-)]</span>
    * <span class="gold">[이분그래프 판정(G-)](/그래프%20이론/그래프/이분그래프%20판정.md)</span>
    * <span class="gold">[다익스트라(G-)](/그래프%20이론/그래프/Dijkstra.md)</span>
    * <span class="">[dial's algorithm]</span>
    * ~~<span class="">[A*]</span>~~
    * <span class="gold">[벨만-포드(G-)](/그래프%20이론/그래프/Bellman-Ford.md)</span>
    * <span class="gold">[SPFA(G-)](/그래프%20이론/그래프/SPFA.md)</span>
    * <span class="gold">[플로이드 워셜(G-)](/그래프%20이론/그래프/Floyd-Warshall.md)</span>
    * <span class="gold">[최소 스패닝 트리: Kruskal(G-)](/그래프%20이론/그래프/MST.md)</span>
    * ~~<span class="">[최소 스패닝 트리: Prim(G-)]</span>~~
    * <span class="">[최소 스패닝 트리: Borůvka]</span>
    * <span class="gold">[_정점 착색수(G+)_](/그래프%20이론/그래프/Graph%20Coloring.md)</span>
    * <span class="">[_간선 착색수_]</span>
    * <span class="gold">[위상 정렬(G+)](/그래프%20이론/그래프/Topological%20Sort.md)</span>
    * <span class="">[kth 최단 경로]</span>
    * <span class="platinum">[강한 연결 요소(P-)](/그래프%20이론/그래프/SCC.md)</span>
    * <span class="platinum">[단절점(P-)](/그래프%20이론/그래프/단절점.md)</span>
    * <span class="platinum">[단절선(P-)](/그래프%20이론/그래프/단절선.md)</span>
    * <span class="">[이중 연결 요소]</span>
    * <span class="platinum">[2-SAT(P-)](/그래프%20이론/그래프/2-SAT.md)</span>
    * <span class="platinum">[오일러 회로(P-)](/그래프%20이론/그래프/오일러%20회로.md)</span>
    * <span class="">[블록 컷 트리]</span>
    * <span class="">[선인장]</span>
    * <span class="">[_2th MST(D-)_]</span>
    * <span class="">[쌍대 그래프(D-)]</span>
    * <span class="">[도미네이터 트리(D-)]</span>
    * <span class="">[오프라인 동적 연결성 판정]</span>
    * <span class="">[평면 그래프]</span>
    * <span class="">[쌍대 그래프]</span>
    * <span class="">[현 그래프(D+)]</span>
    * <span class="diamond">[유향 MST(D+)](/그래프%20이론/그래프/DMST.md)</span>
    * <span class="ruby">[offline incremental SCC(R-)](/그래프%20이론/그래프/Offline%20Incremental%20SCC.md)</span>
    <!-- * <span class="">[현 그래프 판정]</span> -->
    <!-- * <span class="">[Perfect Elimination Ordering]</span> -->
    <!-- * <span class="">[최소 차수 MST]</span> -->
    <!-- * <span class="">[Euclidean MST]</span> -->
  * #### [네트워크 플로우](/그래프%20이론/네트워크%20플로우/개념%20정리.md)
    * <span class="platinum">[이분 매칭(P-)](/그래프%20이론/네트워크%20플로우/이분매칭.md)</span>
    * ~~<span class="platinum">[최대유량: Edmonds-Karp (P-)](/그래프%20이론/네트워크%20플로우/최대%20유량.md)</span>~~
    * <span class="platinum">[최대유량: Dinic (P-)](/그래프%20이론/네트워크%20플로우/Dinic.md)</span>
    * <span class="platinum">[이분 매칭: Hopcraft-Karp(P-)](/그래프%20이론/네트워크%20플로우/Hopcroft-Karp.md)</span>
    * ~~<span class="">[최대유량: Push-Relabel (P-)]</span>~~
    * <span class="platinum">[최소 비용 최대 유량(P+)](/그래프%20이론/네트워크%20플로우/MCMF.md)</span>
    * <span class="diamond">[서큘레이션, L-R flow(D-)](/그래프%20이론/네트워크%20플로우/서큘레이션.md)</span>
    * <span class="diamond">[헝가리안(D-)](/그래프%20이론/네트워크%20플로우/헝가리안.md)</span>
    * <span class="">[일반 매칭(D+)]</span>
    * <span class="">[Stoer-Wagner Algorithm]</span> <!-- https://justicehui.github.io/hard-algorithm/2019/11/28/global-min-cut/ -->
    * <span class="">[Gomory-Hu Tree]</span>
    <!-- * <span class="">[Successive Shortest Path Algorithm]</span> --> <!-- https://koosaga.com/289 --> <!-- 다이아1 문제 https://www.acmicpc.net/problem/23181 -->
    <!-- * <span class="">[홀의 결혼 정리]</span> -->
  * #### 트리
    * <span class="platinum">[최소 공통 조상(P-)](/그래프%20이론/트리/LCA.md)</span>
    * <span class="platinum">[LCA를 통한 트리 쿼리(P-)](/그래프%20이론/트리/Query%20with%20LCA.md)</span>
    * <span class="platinum">[오일러 경로 테크닉(P-)](/그래프%20이론/트리/ETT.md)</span>
    * <span class="">[heavy-light 분할(P+)]</span>
    * <span class="">[트리 압축]</span>
    * <span class="">[센트로이드 분할(D-)]</span>
    * <span class="">[트리 동형 사상]</span>
    * <span class="">[탑 트리(R-)]</span>
* ### [DP](/DP/Top-Down%20DP.md)
  <!-- * <span class="">[배낭 문제(G-)]</span> -->
  <!-- * <span class="">[비트 집합]</span> -->
  <!-- https://egod1537.tistory.com/entry/Bounded-Knapsack-Problem%ED%9A%A8%EC%9C%A8%EC%A0%81%EC%9C%BC%EB%A1%9C-%ED%95%B4%EA%B2%B0%ED%95%98%EA%B8%B0 -->
  * <span class="silver">[Kadane algorithm(S+)](/DP/Kadane%20Algorithm.md)</span>
  * <span class="silver">[LIS(S+)](/DP/LIS.md)</span>
  * <span class="gold">[LCS(G-)](/DP/LCS.md)</span>
  * <span class="">[비트셋 LCS]</span>
  * <span class="gold">[배낭 문제(G-)](/DP/Knapsack.md)</span>
  * <span class="gold">[비트셋 배낭(G-)](/DP/Knapsack(Bitset).md)</span>
  * <span class="">[최단거리 역추적](/DP/DP%20역추적.md)</span>
  * <span class="gold">[비트마스크 DP(G+)](/DP/Bitmask%20DP.md)</span>
  * <span class="platinum">[토글링(P-)](/DP/toggling.md)</span>
  * <span class="platinum">[볼록껍질 최적화(P+)](/DP/CHT.md)</span>
  * <span class="platinum">[분할정복 최적화(P+)](/DP/DnC.md)</span>
  * <span class="diamond">[SOS DP(D-)](/DP/SOS%20DP.md)</span>
  * <span class="">[히르쉬버그(D+)]</span>
  * <span class="">[Connection Profile DP]</span>
  * <span class="">[크누스 최적화]</span>
  * <span class="">[단조큐 최적화]</span>
  * <span class="">[Slope trick(D-)]</span>
  * <span class="">[벌레캠프-매시(D+)]</span>
  <!-- * <span class="">[aliens 트릭(D-)]</span> -->
* ### 문자열
<!-- RBS(Regular Bracket Sequence) -->
  * <span class="gold">[트라이(G+)](/문자열/Trie.md)</span>
  * <span class="platinum">[매내처(P-)](/문자열/Manacher.md)</span>
  * <span class="platinum">[롤링 해시(P-)](/문자열/롤링%20해시.md)</span>
  * <span class="platinum">[라빈 카프(P-)](/문자열/Rabin-Karp.md)</span>
  * <span class="platinum">[KMP(P-)](/문자열/KMP.md)</span>
  * <span class="platinum">[아호 코라식(P+)](/문자열/Aho-Corasick.md)</span>
  * ~~<span class="">[bitap algorithm]</span>~~
  * <span class="platinum">[접미사 배열과 lcp 배열(P+)](/문자열/Suffix%20and%20LCP%20Array.md)</span>
  * <span class="">[Z algorithm]</span>
  * <span class="diamond">[회문 트리(D+)](/문자열/회문%20트리.md)</span>
  * <span class="">[접미사 트리(R-)]</span>
* ### 기하학
  <!-- * ~~<span class="">[반공간 교집합]</span>~~ -->
  <!-- * <span class="">[3D convex hull]</span>
  * <span class="">[dynamic convex hull]</span>
  * <span class="">[polygon raycast]</span>
  molamola 팀노트 https://zigui.tistory.com/5 -->
  <!-- https://zigui.tistory.com/34 -->
  * <span class="additional">[기하학 헤더](/기하학/Geometry%20Header.md)</span>
    * <span class="">[외적, CCW(G-)]</span>
    * <span class="">[거리 계산 : point-point, line-point]</span>
    * <span class="">[넓이 계산 : 삼각형 신발끈, 사각형 신발끈, 헤론, 브라마굽타, 활꼴]</span>
    * <span class="">[제2 cos]</span>
    * <span class="">[좌표 계산 : 2d회전, 3d회전]</span>
  * <span class="gold">[볼록다각형 넓이(G-)](/기하학/Polygon%20Area.md)</span>
  * <span class="">[볼록다각형 판정]</span>
  * <span class="gold">[선분교차판정(G+)](/기하학/선분교차판정.md)</span>
  * <span class="platinum">[선분교차점 계산(P-)](/기하학/선분교차점%20계산.md)</span>
  * <span class="platinum">[볼록 껍질(P-)](/기하학/볼록%20껍질.md)</span>
  * <span class="platinum">[가장 먼 두 점 : 회전하는 캘리퍼스(P-)](/기하학/Rotating%20Calipers.md)</span>
  * <span class="platinum">[plane sweeping(P-)](/기하학/Plane%20Sweeping.md)</span>
  * <span class="platinum">[다각형 내부의 점 판정(P-)](/기하학/PIP.md)</span>
  * <span class="platinum">[볼록 다각형 내부의 점 판정(P+)](/기하학/PIP(convex).md)</span>
  * <span class="platinum">[등적등주 분할(P+)](/기하학/Equalizer.md)</span>
  * <span class="platinum">[가장 가까운 두 점(P+)](/기하학/Closest%20Two%20Points.md)</span>
  * <span class="">[최소 외접원(P+)]</span>
  * <span class="">[볼록다각형 접선]</span> <!-- https://www.acmicpc.net/problem/18190 --> <!-- https://youngyojun.github.io/contest/review/2020/02/15/iamcoder-2019-yearend-contest/ -->
  * <span class="">[불도저]</span>
  * <span class="">[반평면 교집합(D-)]</span>
  * <span class="">[KD tree]</span> <!-- https://algoshitpo.github.io/2020/02/09/kdtree/ -->
  * <span class="">[그린 정리(D+)]</span>
  * <span class="">[델로네 삼각분할(R-)]</span>
  * <span class="">[보로노이 다이어그램(R-)]</span> <!-- https://zigui.tistory.com/32 -->
  * <span class="">[disk convex hull(R)]</span> <!-- https://www.acmicpc.net/problem/27957 -->
* ### [수학](/수학/개념%20정리.md)
  * #### 조합론, 수열
    * <span class="silver">[nCr, 파스칼의 삼각형(S+)](/수학/조합론/Combination(DP).md)</span> <!-- https://justicehui.github.io/medium-algorithm/2024/02/10/combinatorics/ -->
    * <span class="gold">[거듭제곱 피보나치(G+)](/수학/조합론/피보나치.md)</span>
    * <span class="">[교란수]</span>
    * <span class="">[자연수 분할](/수학/조합론/자연수%20분할.md)</span> <!-- P(n, k) -->
    * <span class="platinum">[집합 분할(P-)](/수학/조합론/집합%20분할.md)</span>
    * <span class="">[nCr mod 소수, 뤼카(P-)]</span>
    * <span class="">[nCr mod 합성수(D-)]</span>
    * <span class="">[생성 함수(D-)]</span> <!-- 카탈란 생성함수 O(nlogN) --> <!-- https://github.com/infossm/infossm.github.io/blob/master/_posts/2019-10-19-generating-function.md -->
    * <span class="">[키타마사(D-)]</span>
    * <span class="">[Bostan-Mori]</span>
    <!-- https://codeforces.com/blog/entry/111862 -->
    <!-- https://blog.myungwoo.kr/149 -->
    <!-- https://infossm.github.io/blog/2021/12/21/Bostan-Mori_Algorithm/ -->
  * #### 선형대수학
    * <span class="silver">[행렬(S-)](/수학/선형대수학/Matrix.md)</span>
    * <span class="">[가우스 소거법(P-)]</span>
    * <span class="">[키르히호프(P-)]</span> <!-- https://www.acmicpc.net/problem/9614 -->
    * <span class="">[strassen algorithm]</span>
    * <span class="">[Freivalds' algorithm]</span> <!-- https://www.acmicpc.net/problem/13165 -->
    <!-- * <span class="">[Deterministic Verification of Integer Matrix Multiplication in Quadratic Time]</span> -->
  * #### 기타
    <!-- * <span class="">[고합성수 찾기]</span>
    * <span class="">[우월고합성수]</span> -->
    <!-- Szemerédi–Trotter theorem -->
    * <span class="silver">[분할정복 거듭제곱(S+)](/수학/빠른%20거듭제곱.md)</span>
    * <span class="silver">[에라토스테네스의 체(S+)](/수학/에라토스테네스의%20체.md)</span>
    * <span class="gold">[Linear sieve 소수 판별(G-)](/수학/Linear%20Sieve.md)</span>
    * <span class="gold">[약수 리스트 계산(G-)](/수학/약수%20리스트%20계산.md)</span>
    * <span class="gold">[harmonic lemma 조화 수열 계산(G+)](/수학/Harmonic%20Lemma.md)</span>
    * <span class="gold">[harmonic lemma 배수 개수 계산(G+)](/수학/배수%20개수%20계산.md)</span>
    * <span class="gold">[p-지수(G+)](/수학/p-지수.md)</span>
    * <span class="gold">[확장 유클리드 호제법, 모듈러 역원(G+)](/수학/ExtendedGCD,%20Modular%20Inverse.md)</span>
    * <span class="">[모듈러 역원 값 여러개 계산]</span> <!-- https://codeforces.com/blog/entry/83075 -->
    * <span class="gold">[오일러 파이 함수(G+)](/수학/Phi%20Function.md)</span>
    * <span class="platinum">[중국인의 나머지 정리(P-)](/수학/CRT.md)</span>
    * <span class="">[Garner's algorithm]</span>
    * <span class="">[Barrett reduction]</span>
    * <span class="">[베르누이 수]</span>
    * ~~<span class="platinum">[Faulhaber(P+)](/수학/Faulhaber.md)</span>~~
    * <span class="">[Stern-Brocot 트리]</span> <!-- https://blog.myungwoo.kr/126 --> <!-- https://youngyojun.github.io/secmem/2022/02/18/sigma-sum-stern-brocot/ -->
    * <span class="platinum">[밀러-라빈 소수 판별법(P+)](/수학/MillerRabin.md)</span>
    * <span class="platinum">[폴라드 로(P+)](/수학/PollardRho.md)</span>
    * <span class="platinum">[FFT(P+)](/수학/FFT.md)</span>
    * ~~<span class="">[카라츠바]</span>~~
    * <span class="">[이산 로그(P+)]</span>
    * <span class="diamond">[이산 제곱근(D-)](/수학/Tonelli-Shanks.md)</span>
    * <span class="">[이산 k제곱근]</span>
    * <span class="diamond">[Cornacchia's algorithm(D-)](/수학/Cornacchia.md)</span>
    * <span class="diamond">[Power tower(D-)](/수학/Power%20Tower.md)</span>
    * <span class="">[3진 FFT(D-)]</span> <!-- https://www.acmicpc.net/problem/14882 -->
    * <span class="diamond">[NTT(D-)](/수학/NTT.md)</span>
    * <span class="">[FFT 나눗셈]</span>
    * <span class="">[simplex]</span>
    * <span class="">[LP]</span>
    * <span class="">[xor convolution]</span>
    * <span class="">[FFT 응용]</span> <!-- https://hyperbolic.tistory.com/4 -->
    * <span class="">[online FFT]</span>
    * <span class="diamond">[라그랑주 보간법(D-)](/수학/라그랑주%20보간법.md)</span>
    * <span class="diamond">[Linear sieve 곱셈적 함수(D-)](/수학/곱셈적%20함수.md)</span>
    * <span class="diamond">[뫼비우스 함수(D-)](/수학/뫼비우스.md)</span>
    * <span class="diamond">[뫼비우스 반전(D-)](/수학/뫼비우스%20반전.md)</span>
    * <span class="diamond">[메르텐스 함수(D+)](/수학/메르텐스.md)</span>
    * <span class="diamond">[메르텐스 트릭, Xudyh's sieve (D+)](/수학/Xudyh's%20sieve.md)</span>
    * <span class="">[min_25's sieve]</span>
    * <span class="">[매트로이드(R-)]</span>
* ### 게임 이론
  * <span class="">[스프라그-그런디]</span> <!-- (비트셋) -->
  * <span class="">[hackenbush]</span> <!-- https://en.wikipedia.org/wiki/Hackenbush --> <!-- https://rkm0959.tistory.com/139 -->
  * <span class="">[coldgame]</span> <!-- https://infossm.github.io/blog/2024/11/01/Coldgame-problem-solving/ -->
* ### 기타
  * <span class="additional">[비트 트릭(A)](/기타/Bit%20Trick.md)</span>
  * <span class="">[계수 정렬]</span>
  * <span class="silver">[기수 정렬(S-)](/기타/Radix%20Sort.md)</span>
  * <span class="silver">[이분 탐색(S-)](/기타/이분탐색.md)</span>
  * <span class="silver">[투 포인터(S-)](/기타/Two%20Pointer.md)</span>
  * <span class="silver">[비트마스크(S-)](/기타/Bitmask.md)</span>
  * <span class="silver">[좌표 압축(S-)](/기타/좌표압축.md)</span>
  * <span class="silver">[순열 사이클 분할(S+)](/기타/순열%20사이클%20분할.md)</span>
  * <span class="">[모노톤 스택]</span>
  * <span class="">[모노톤 큐]</span>
  * <span class="">[XOR Hashing]</span> <!-- https://codeforces.com/blog/entry/85900 -->
  * <span class="">[누적합, imos]</span>
  * <span class="">[Barrett reduction]</span>
  * <span class="">[Gray code](/기타/Gray%20code.md)</span>
  * <span class="gold">[후위 표기식(G+)](/기타/Postfix%20Notation.md)</span>
  * <span class="">[중간에서 만나기(G+)]</span>
  * <span class="platinum">[반전수(P-)](/기타/반전수.md)</span>
  * <span class="">[스위핑]</span>
  * <span class="">[슬라이딩 윈도우]</span>
  * <span class="platinum">[덱을 이용한 구간 최댓값 트릭(P-)](/기타/Deque%20Trick.md)</span>
  * <span class="platinum">[삼분 탐색(P-)](/기타/삼분탐색.md)</span>
  * <span class="platinum">[Mo's algorithm(P+)](/기타/Mo's.md)</span>
  * <span class="platinum">[평방분할(P+)](/기타/제곱근%20분할법.md)</span>
  * <span class="">[small to large]</span>
  * <span class="">[range mode query]</span> <!-- https://infossm.github.io/blog/2021/05/20/Data-Structure-For-Range-Mode-Query/ --> <!-- https://www.acmicpc.net/problem/14898 -->
  * <span class="">[병렬 이분 탐색(P+)]</span>
  * <span class="">[춤추는 링크, 크누스 X]</span>
  * <span class="">[임의 정밀도(epsilon값 계산)(A)]</span>
  * ~~<span class="">[담금질 기법]</span>~~ <!-- https://ryute.tistory.com/35    --> <!-- https://ryute.tistory.com/36    -->
  * <span class="">[Fracturing Search(D+)]</span> <!-- https://usaco.guide/adv/fracturing-search?lang=cpp --> <!-- https://www.acmicpc.net/problem/14166 -->
  * <span class="">[선형 계획법]</span>
  * <span class="">[쌍대성]</span>
  * <span class="">[Simplex algorithm]</span>
* ### utils
  * <span class="additional">[fastio](/utils/fastio.md)</span>
  * <span class="additional">[bit](/utils/Bit.md)</span>
  * <span class="additional">[문자열 압축](/utils/String%20Compression.md)</span>
  * <span class="additional">[개수 계산](/utils/Counter.md)</span>
  * <span class="additional">[랜덤](/utils/Random.md)</span>
  * <span class="additional">[고합성수 검색](/utils/Highly%20Composite%20Number.md)</span>
  * <span class="additional">[배열 연산](/utils/Array.md)</span>
  * <span class="additional">[가까운 2의 멱수 계산](/utils/Nearest%20Power2.md)</span>
  * <span class="">[modInt]</span>
  * <span class="">[bigInt]</span>
  * <span class="">[baseInt]</span> <!-- bigint랑 합쳐서 구현하는 게 나을 듯 -->
# C++ 유용한 기능
* ### 문법
  * <span class="">[range-based for loop]</span>
  * <span class="">[using]</span> <!-- 기하학 풀 때 using ld; -->
  * <span class="">[literal]</span>
  * <span class="information">[template argument deduction](/C++/문법/Template%20Argument%20Deduction.md)</span>
  * <span class="information">[람다 캡처, 재귀](/C++/문법/lambda.md)</span>
  * <span class="">[코드 여러줄 이어쓰기]</span>
  * <span class="">[리터럴 여러줄 이어쓰기]</span>
* ### 함수
  * <span class="information">[수학관련](/C++/함수/math.md)</span>
  * <span class="">[배열관련]</span> <!-- copy doubling -->
  * <span class="">[constexpr, static_assert]</span> <!-- if constexpr 등등도 포함 -->
  * <span class="information">[multiset](/C++/함수/multiset.md)</span>
  * <span class="information">[permutation](/C++/함수/permutation.md)</span>
  * <span class="information">[casting](/C++/함수/casting%20operators.md)</span>
  * <span class="information">[GCC built-in](/C++/함수/builtin.md)</span>
  * <span class="information">[GCC 최적화](/C++/함수/GCC%20optimize.md)</span>
  * <span class="information">[문자관련](/C++/함수/char.md)</span>
  * <span class="information">[문자열관련](/C++/함수/string.md)</span>
  * <span class="information">[이분탐색 람다함수](/C++/함수/lower_bound_lambda.md)</span>
  * <span class="information">[custom pq](/C++/함수/costom%20pq.md)</span>
  * <span class="information">[io manip](/C++/함수/iomanip.md)</span>
* ### ps용 환경설정
  * <span class="">[cph]</span>
  * <span class="information">[define](/C++/ps용%20환경설정/define.md)</span>
  * <span class="information">[snippet](/C++/ps용%20환경설정/snippet.md)</span>
  * <span class="">[debug, c_cpp_properties.json 설정]</span>
  <!-- * Pre-defined Compiler Macros
  * 버전 gnu++17로 해야 Template argument deduction 등 문법 사용가능 -->
  * <span class="">[predifined macro]</span>
  * <span class="">[percompiled header]</span> <!-- https://codeforces.com/blog/entry/79026 --> <!-- https://codeforces.com/blog/entry/53909? -->
* ### 기타
  * <span class="information">[자주 쓰는 변수명](/C++/기타/Variable%20Name.md)</span>
  * <span class="information">[코딩 아이디어](/C++/기타/Idea.md)</span>
  <!-- https://xy-plane.tistory.com/11 -->
# 참고링크
백준 알고리즘 분류   
https://www.acmicpc.net/problem/tags   

tlsdydaud1   
https://00ad-8e71-00ff-055d.tistory.com/3   

jh05013   
https://jh05013.github.io/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/   

jhnah917   
https://justicehui.github.io/tutorial/   
https://github.com/justiceHui/Unknown-To-Wellknown   

jinhan814   
https://blog.naver.com/jinhan814/222439886998   
https://blog.naver.com/PostView.naver?blogId=jinhan814&logNo=222689836982&parentCategoryNo=&categoryNo=6&viewDate=&isShowPopularPosts=false&from=postView   

정수론   
https://ahgus89.github.io/

kcm1700   
https://algospot.com/wiki/read/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98_%EB%8C%80%ED%9A%8C%EC%97%90_%ED%95%84%EC%9A%94%ED%95%9C_%EC%88%98%ED%95%99   
https://algospot.com/wiki/read/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98_%EB%8C%80%ED%9A%8C%EC%97%90_%ED%95%84%EC%9A%94%ED%95%9C_%EA%B8%B0%ED%95%98   

선형대수학   
https://tistory.joonhyung.xyz/18   

bowbowbow   
https://bowbowbow.tistory.com/category/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98   

kks227   
https://m.blog.naver.com/kks227?categoryNo=299&tab=1   

MJ Studio   
https://ps.mjstudio.net/categories/algorithm   

koosaga   
https://koosaga.com/242   

https://youngyojun.github.io/

S/W 멤버십 기술 블로그   
https://infossm.github.io/blog/   

gratus907   
https://gratus-blog.tistory.com/   

정수론 시리즈   
https://xy-plane.tistory.com/16

https://blog.myungwoo.kr/

https://nyaannyaan.github.io/library/data-structure/union-find-with-potential.hpp.html

https://cocoachan.tistory.com/

pentagon03   
https://howtoliveworldnice.tistory.com/category/Algorithm/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%20%EC%9D%B4%EB%A1%A0%20%EC%A0%95%EB%A6%AC

기하학   
zigui   
https://zigui.tistory.com/34

algoshitpo   
https://algoshitpo.github.io/   

<!-- # 알고리즘 순서 { -->
  ```mermaid
  stateDiagram-v2
  direction LR
  %% 
  %% %% [*] --> 자료구조
  %% 자료구조 --> 펜윅_트리
  %%   펜윅_트리 --> 2D_펜윅
  %%   2D_펜윅 --> n차원_펜윅
  %% 자료구조 --> 세그먼트_트리
  %%   세그먼트_트리 --> 2D_세그
  %%   세그먼트_트리 --> 머지소트_트리
  %%   세그먼트_트리 --> 다이나믹_세그
  %%   세그먼트_트리 --> 레이지_세그
  %%     다이나믹_세그 --> 다이나믹_레이지_세그
  %%     레이지_세그 --> 다이나믹_레이지_세그
  %%   세그먼트_트리 --> 금광_세그
  %% 자료구조 --> 스플레이_트리
  %% 레이지_세그 --> 스플레이_트리
  %% 자료구조 --> 분리_집합
  %% 자료구조 --> 희소_배열
  %% 
  %% %% [*] --> 그래프_이론
  %% %% 그래프_이론 --> 그래프
  %%   그래프 --> 최소_스패닝_트리
  %%   그래프 --> 이분_그래프_판정
  %%   그래프 --> 다익스트라
  %%   그래프 --> 벨만_포드
  %%     벨만_포드 --> SPFA
  %%   그래프 --> 플로이드_워셜
  %%   그래프 --> 정점_착색수
  %%   그래프 --> 위상_정렬
  %%   그래프 --> 강한_연결_요소
  %%     강한_연결_요소 --> 2_SAT
  %%   그래프 --> 오일러_회로
  %%   그래프 --> 단절량
  %%   그래프 --> 단절선
  %%   그래프 --> 유향_최소_신장_트리
  %% 그래프 --> 네트워크_플로우
  %%   네트워크_플로우 --> 최대유량
  %%   최대유량 --> 최소_비용_최대_유량
  %%   SPFA --> 최소_비용_최대_유량
  %%   네트워크_플로우 --> 이분_매칭
  %% 그래프 --> 트리
  %%   트리 --> 최소_공통_조상
  %%   희소_배열 --> 최소_공통_조상
  %%   트리 --> 오일러_경로_테크닉
  %% 
  %% %% [*] --> 동적_계획법
  %% 동적_계획법 --> 비트마스크_DP
  %% 동적_계획법 --> 볼록껍질_최적화
  %% 동적_계획법 --> 분할정복_최적화
  %% 
  %% %% [*] --> 수학
  %% 수학 --> 에라토스테네스의_체
  %% 수학 --> 조합론
  %% 조합론 --> nCr_파스칼의_삼각형
  %% 동적_계획법 --> nCr_파스칼의_삼각형
  %% 조합론 --> nCr_mod_소수
  %% 모듈러_역원 --> nCr_mod_소수
  %% %% nCr_mod_소수 --> 뤼카
  %% 수학 --> 분할정복_거듭제곱
  %% 분할정복_거듭제곱 --> 행렬_거듭제곱
  %% 분할정복_거듭제곱 --> 밀러_라빈_소수_판별법
  %% 밀러_라빈_소수_판별법 --> 폴라드_로
  %% 유클리드_호제법 --> 폴라드_로
  %% 수학 --> 유클리드_호제법
  %% 유클리드_호제법 --> 확장_유클리드_호제법
  %% 확장_유클리드_호제법 --> 모듈러_역원
  %% 모듈러_역원 --> 중국인의_나머지_정리
  %% 수학 --> 오일러_파이_함수
  %% 수학 --> FFT
  %% FFT --> NTT
  %% 중국인의_나머지_정리 --> NTT
  %% 
  %% %% [*] --> 문자열
  %% 문자열 --> 트라이
  %% 트라이 --> XOR_트라이
  %% 문자열 --> KMP
  %% 트라이 --> 아호_코라식
  %% KMP --> 아호_코라식
  %% %% 계수_정렬 --> 접미사_배열과_lcp_배열
  %% 문자열 --> 접미사_배열과_lcp_배열
  %% 문자열 --> 펠린드롬
  %% 펠린드롬 --> 매내처
  %% 펠린드롬 --> 회문_트리
  %% 
  %% %% [*] --> 기하학
  %% 기하학 --> 외적
  %% 외적 --> ccw
  %% 외적 --> 직선_점_거리_계산
  %% ccw --> 선분교차판정
  %% ccw --> 볼록껍질
  %% ccw --> 회전하는_캘리퍼스
  %% ccw --> 다각형_내부의_점_판정
  %% ccw --> 볼록_다각형_내부의_점_판점
  %% 기하학 --> 가장_가까운_두_점
  %% 
  %% [*] --> 기타
  %% 기타 --> 이분_탐색
  %% 이분_탐색 --> 볼록_다각형_내부의_점_판점
  %% 기타 --> 값_좌표_압축
  %% 기타 --> 순열_사이클_분할
  %% 기타 --> Mo's
  %% 기타 --> 평방분할
  %% 
  %% %% 나중에 추가할 거 같은 간선
  %% %% 트리_압축 --> 유향_최소_신장_트리
  %% %% 최대유량_Dinic --> 이칭_매칭_Hopcraft_Karp
  %% %% 트라이 --> 아호_코라식
  %% %% ccw --> 볼록다각형_판정
  ```
<!-- } -->
<!-- vim %이동을 위한 괄호임 삭제하면 안 됨 -->