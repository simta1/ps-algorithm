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
| $n \le 2,000$         | $O(n^2 \log{n})$, $O(\dfrac{n^3}{24})$    | SIMD                                                  |
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
    * ~~<span class="platinum">[_GCD 세그(P+)_](/자료구조/세그먼트%20트리/GCD%20세그.md)</span>~~
    * <span class="platinum">[금광 세그(최대 연속 부분합 세그)(P+)](/자료구조/세그먼트%20트리/금광%20세그.md)</span>
    * <span class="">[퍼시스턴트 세그(P+)]</span>
    * <span class="">[세그트리비츠(D+)]</span> <!-- https://infossm.github.io/blog/2019/10/19/Segment-Tree-Beats/ -->
    * <span class="">[Kinetic Segment Tree]</span> <!-- https://koosaga.com/307 -->
  * #### BBST
    * <span class="">[treap]</span>
    * <span class="diamond">[스플레이 트리(D-)](/자료구조/BBST/SplayTree.md)</span>
    * <span class="">[Persistent BBST, Weight-Balanced Tree]</span> <!-- https://koosaga.com/342 -->
    * <span class="">[레드-블랙 트리]</span>
  * #### 기타
    * <span class="gold">[유니온 파인드(G-)](/자료구조/기타/DSU.md)</span>
    * <span class="">[유니온 파인드 롤백]</span>
    * <span class="">[자료구조 롤백 지원하기]</span> <!-- https://cologne.tistory.com/66 -->
    * <span class="">[erasable pq]</span> <!-- https://nyaannyaan.github.io/library/data-structure/erasable-priority-queue.hpp -->
    * <span class="">[meldable pq]</span>
    * <span class="gold">[희소 배열(G+)](/자료구조/기타/희소배열.md)</span>
    * <span class="platinum">[XOR 트라이(P-)](/자료구조/기타/XOR%20Trie.md)</span>
    * <span class="platinum">[유니온 파인드 with Potential(P+)](/자료구조/기타/DSU%20potential.md)</span>
    * <span class="platinum">[로프(P-)](/자료구조/기타/rope.md)</span>
    * <span class="platinum">[ordered set(P-)](/자료구조/기타/ordered_set.md)</span>
    * <span class="">[wavelet 트리]</span>
    * <span class="">[데카르트 트리(Cartesian tree)]</span> <!-- https://imeimi.tistory.com/42 구간 내에서의 RMQ는 cartesian tree에서의 LCA? -->
    * <span class="">[Farach-Colton and Bender Algorithm]</span> <!-- https://cp-algorithms.com/graph/lca_farachcoltonbender.html --> <!-- https://codeforces.com/blog/entry/86746?locale=en -->
    * <span class="diamond">[Line Container(D-)](/자료구조/기타/LineContainer.md)</span>
    * <span class="">[리-차오 트리(D-)]</span>
    * <span class="">[SPQR tree]</span>
    * <span class="">[PQ tree]</span> <!-- https://infossm.github.io/blog/2021/10/20/PQ_Tree_Part_1/ -->
    <!-- * <span class="">[weighted QU]</span> -->
    <!-- * <span class="">[B-tree]</span> -->
* ### [그래프 이론](/그래프%20이론/개념%20정리.md)
  * #### 그래프
    <!-- * <span class="">[horn sat]</span> -->
    <!-- https://www.acmicpc.net/problem/3636 -->
    <!-- https://ps.mjstudio.net/tip-bfs-fill -->
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
    * <span class="">[Dynamic MST]</span> <!-- https://koosaga.com/211 -->
    * <span class="">[삼각형, 사각형 찾기(D-)]</span>
    * <span class="">[_2th MST(D-)_]</span>
    * <span class="">[쌍대 그래프(D-)]</span>
    * <span class="">[그래프 채색]</span> <!-- https://infossm.github.io/blog/2023/06/21/Graph-Coloring/ -->
    * <span class="">[도미네이터 트리]</span>
    * <span class="">[오프라인 동적 연결성 판정]</span> <!-- https://stonejjun.tistory.com/171 -->
    * <span class="">[삼각형 찾기]</span> <!-- https://jh05013.github.io/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/%EC%82%BC%EA%B0%81%ED%98%95%20%EC%B0%BE%EA%B8%B0/ -->
    * <span class="">[평면 그래프]</span>
    * <span class="">[쌍대 그래프]</span>
    * <span class="">[현 그래프 판정]</span>
    * <span class="">[현 그래프(D+)]</span>
    * <span class="diamond">[유향 MST(D+)](/그래프%20이론/그래프/DMST.md)</span>
    * <span class="ruby">[offline incremental SCC(R-)](/그래프%20이론/그래프/Offline%20Incremental%20SCC.md)</span>
    * <span class="">[온라인 동적 연결성 판정(R+)]</span> <!-- https://etyu39.tistory.com/5 --> <!-- https://www.acmicpc.net/problem/17465 -->
    <!-- * <span class="">[Perfect Elimination Ordering]</span> -->
    <!-- * <span class="">[최소 차수 MST]</span> -->
  * #### [네트워크 플로우](/그래프%20이론/네트워크%20플로우/개념%20정리.md)
    * <span class="platinum">[이분 매칭(P-)](/그래프%20이론/네트워크%20플로우/이분매칭.md)</span>
    * ~~<span class="platinum">[최대유량: Edmonds-Karp (P-)](/그래프%20이론/네트워크%20플로우/최대%20유량.md)</span>~~
    * <span class="platinum">[최대유량: Dinic (P-)](/그래프%20이론/네트워크%20플로우/Dinic.md)</span>
    * <span class="platinum">[이분 매칭: Hopcraft-Karp(P-)](/그래프%20이론/네트워크%20플로우/Hopcroft-Karp.md)</span>
    * ~~<span class="">[최대유량: Push-Relabel (P-)]</span>~~
    * <span class="platinum">[최소 비용 최대 유량(P+)](/그래프%20이론/네트워크%20플로우/MCMF.md)</span>
    * <span class="platinum">[zkw mcmf]</span>
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
    * <span class="platinum">[heavy-light 분할(P+)](/그래프%20이론/트리/HLD.md)</span>
    * <span class="">[트리 압축]</span>
    * <span class="">[센트로이드]</span>
    * <span class="">[센트로이드 분할(D-)]</span>
    * <span class="">[트리 동형 사상]</span>
    * <span class="">[tree width]</span>
    * <span class="">[링크/컷 트리(D+)]</span> <!-- https://jh05013.github.io/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/%EB%A7%81%ED%81%AC-%EC%BB%B7%20%ED%8A%B8%EB%A6%AC/ --> <!-- https://justicehui.github.io/hard-algorithm/2021/01/01/link-cut-tree/ --> <!-- https://m.blog.naver.com/jinhan814/222309144459?recommendTrackingCode=2 -->
    * <span class="">[탑 트리(R-)]</span> <!-- https://etyu39.tistory.com/8 -->
* ### [DP](/DP/Top-Down%20DP.md)
  <!-- * <span class="">[비트 집합]</span> -->
  <!-- https://egod1537.tistory.com/entry/Bounded-Knapsack-Problem%ED%9A%A8%EC%9C%A8%EC%A0%81%EC%9C%BC%EB%A1%9C-%ED%95%B4%EA%B2%B0%ED%95%98%EA%B8%B0 -->
  * <span class="silver">[Kadane algorithm(S+)](/DP/Kadane%20Algorithm.md)</span>
  * <span class="silver">[LIS(S+)](/DP/LIS.md)</span>
  * <span class="gold">[LCS(G-)](/DP/LCS.md)</span>
  * <span class="gold">[동전 교환 문제(G-)](/DP/동전%20교환%20문제.md)</span>
  * <span class="additional">[배낭문제(G-)](/DP/배낭문제.md)</span>
    * <span class="gold">[0-1 Knapsack(G-)](/DP/배낭문제.md#0-1-knapsack-problem)</span>
    * <span class="gold">[Unbounded Knapsack(G-)](/DP/배낭문제.md#unbounded-knapsack-problem)</span>
    * <span class="platinum">[Bounded Knapsack(P-)](/DP/배낭문제.md#bounded-knapsack-problem)</span>
  * <span class="gold">[비트셋 배낭(G-)](/DP/비트셋%20배낭.md)</span>
  * <span class="gold">[최단거리 역추적(G-)](/DP/DP%20역추적.md)</span>
  * <span class="gold">[달걀 낙하(G+)](/DP/달걀%20낙하.md)</span>
  * <span class="gold">[비트마스크 DP(G+)](/DP/Bitmask%20DP.md)</span>
  * <span class="">[트리DP, re-rooting]</span> <!-- https://codeforces.com/blog/entry/124286 -->
  * <span class="platinum">[토글링(P-)](/DP/toggling.md)</span>
  * <span class="platinum">[볼록 껍질을 이용한 최적화(P+)](/DP/CHT.md)</span>
  * <span class="platinum">[분할 정복을 이용한 최적화(P+)](/DP/DnC.md)</span>
  * <span class="diamond">[SOS DP(D-)](/DP/SOS%20DP.md)</span>
  * <span class="">[검은 돌 트릭]</span> <!-- https://ansol4328.github.io/problem%20solving/2021/10/14/unique-time-complexity/# -->
  * <span class="">[히르쉬버그(D+)]</span>
  * <span class="">[aliens 트릭]</span>
  * <span class="">[Connection Profile DP]</span>
  * <span class="">[크누스 최적화]</span>
  * <span class="">[단조 큐를 이용한 최적화]</span>
  * <span class="">[함수 개형을 이용한 최적화(Slope trick) (D-)]</span>
  * <span class="">[aliens 트릭(라그랑주 최적화)]</span>
  * <span class="">[벌레캠프-매시(D+)]</span>
  * <span class="">[커넥션 프로파일을 이용한 다이나믹 프로그래밍]</span>
  * <span class="ruby">[비트셋 LCS(R-)](/DP/비트셋%20LCS.md)</span>
* ### 문자열
  <!-- RBS(Regular Bracket Sequence) -->
  <!-- https://blog.cube219.me/posts/2021/solve-stock-price-prediction-problem-without-segment-tree/ -->
  * <span class="">[괄호문자열]</span> <!-- 괄호문자열 판별, 괄호 종류 여러개일 때, 괄호문자열 응용 등등 -->
  * <span class="gold">[트라이(G+)](/문자열/Trie.md)</span>
  * <span class="platinum">[매내처(P-)](/문자열/Manacher.md)</span>
  * <span class="platinum">[롤링 해시(P-)](/문자열/롤링%20해시.md)</span>
  * <span class="platinum">[라빈 카프(P-)](/문자열/Rabin-Karp.md)</span>
  * <span class="platinum">[KMP(P-)](/문자열/KMP.md)</span>
  * <span class="platinum">[아호 코라식(P+)](/문자열/Aho-Corasick.md)</span>
  * ~~<span class="">[bitap algorithm]</span>~~
  * <span class="platinum">[접미사 배열과 lcp 배열(P+)](/문자열/Suffix%20and%20LCP%20Array.md)</span>
  * <span class="">[Lyndon Factorization(Duval algorithm)]</span> <!-- https://codeforces.com/blog/entry/89629 --> <!-- https://gall.dcinside.com/mgallery/board/view/?id=ps&no=21405 --> <!-- https://codeforces.com/blog/entry/106725 -->
  * <span class="">[Z algorithm]</span>
  * <span class="">[와일드카드 문자열 매칭]</span> <!-- https://infossm.github.io/blog/2021/08/20/wildcard-string-matching/ --> <!-- https://www.acmicpc.net/problem/26136 -->
  * <span class="diamond">[회문 트리(D+)](/문자열/회문%20트리.md)</span>
  * <span class="">[run enumerate(R-)]</span>
  * <span class="">[접미사 트리(R-)]</span> <!-- https://infossm.github.io/blog/2021/02/20/suffix-tree/ -->
  * <span class="">[suffix automaton]</span> <!-- https://www.acmicpc.net/workbook/view/13245 -->
* ### 기하학
  <!-- * ~~<span class="">[반공간 교집합]</span>~~ -->
  <!-- <span class="">[polygon raycast]</span>
  molamola 팀노트 https://zigui.tistory.com/5 -->
  <!-- https://zigui.tistory.com/34 -->
  * <span class="additional">[기하학 헤더](/기하학/기하학%20헤더.md)</span>
    * <span class="additional">[외적, CCW(G-)](/기하학/기하학%20헤더.md#point-cross-product-ccw)</span>
    * <span class="additional">[거리 계산 : point-point, line-point](/기하학/기하학%20헤더.md#distance)</span>
    * <span class="additional">[넓이 계산 : 단순다각형, 헤론, 브라마굽타, 활꼴](/기하학/기하학%20헤더.md#area)</span>
    * <span class="additional">[점-직선 포함여부 판정](/기하학/기하학%20헤더.md#isbetween-isonpl)</span>
    * <span class="additional">[제2 cos](/기하학/기하학%20헤더.md#triangle)</span>
    * <span class="additional">[삼각함수 합성](/기하학/기하학%20헤더.md#삼각함수)</span>
    * <span class="additional">[좌표 계산 : 수선의 발, 대칭이동, 회전이동](/기하학/기하학%20헤더.md#좌표-계산)</span>
  * <span class="gold">[볼록다각형 부분넓이(G)](/기하학/볼록다각형%20부분넓이.md)</span>
  * <span class="gold">[선분교차판정(G+)](/기하학/선분교차판정.md)</span>
  * <span class="platinum">[선분교차점 계산(P-)](/기하학/선분교차점%20계산.md)</span>
  * <span class="platinum">[볼록 껍질:Graham Scan(P-)](/기하학/볼록껍질(Graham%20Scan).md)</span>
  * <span class="platinum">[볼록 껍질:Monotone Chain(P-)](/기하학/볼록껍질(Monotone%20Chain).md)</span>
  * <span class="platinum">[가장 먼 두 점 : 회전하는 캘리퍼스(P-)](/기하학/Rotating%20Calipers.md)</span>
  * <span class="platinum">[plane sweeping(P-)](/기하학/Plane%20Sweeping.md)</span>
  * <span class="">[radial sweeping]</span>
  * <span class="platinum">[다각형 내부의 점 판정(P-)](/기하학/PIP.md)</span>
  * <span class="platinum">[볼록 다각형 내부의 점 판정(P+)](/기하학/PIP(convex).md)</span>
  * <span class="platinum">[등적등주 분할(P+)](/기하학/Equalizer.md)</span>
  * <span class="platinum">[가장 가까운 두 점(P+)](/기하학/Closest%20Two%20Points.md)</span>
  * <span class="platinum">[최소 외접원(P+)](/기하학/최소외접원.md)</span>
  * <span class="">[Shamos-Hoey]</span> <!-- https://qwerasdfzxcl.tistory.com/18 -->
  * <span class="diamond">[반평면 교집합(D-)](/기하학/반평면%20교집합.md)</span>
  * <span class="">[Bentley-Ottmann]</span> <!-- https://velog.io/@frog_slayer/Bentley-Ottmann -->
  * <span class="diamond">[점-볼록다각형 접선(D-)](/기하학/볼록다각형%20접선.md)</span>
  * <span class="">[볼록다각형-볼록다각형 접선]</span> <!-- https://www.geeksforgeeks.org/tangents-two-convex-polygons/ -->
  * <span class="">[점-원 접선, 원-원 접선]</span> <!-- https://cubelover.tistory.com/4 -->
  * <span class="">[Dynamic Convex Hull]</span> <!-- https://lem0nad3.tistory.com/m/133 --> <!-- https://www.geeksforgeeks.org/dynamic-convex-hull-adding-points-existing-convex-hull/?ref=oin_asr2 -->
  * <span class="">[Convex Layers]</span>
  * <span class="">[구분구적법]</span>
  * <span class="">[심슨 적분]</span> <!-- https://www.acmicpc.net/problem/8303 -->
  * <span class="diamond">[불도저 트릭(Rotating Line Sweep)(D+)](/기하학/불도저.md)</span>
  * <span class="">[KD tree]</span> <!-- https://algoshitpo.github.io/2020/02/09/kdtree/ --> <!-- https://gist.github.com/cgiosy/9d39fa9aedeae94c60ba0692c840c078 -->
  * <span class="">[Polygon Clipping]</span>
  * <span class="diamond">[그린 정리(D+)](/기하학/그린%20정리.md)</span>
  * <span class="diamond">[도형에서의 불 연산: Circle Union(D+)](/기하학/Union(Circle).md)</span>
  * <span class="diamond">[도형에서의 불 연산: Ring Union(D+)](/기하학/Union(Ring).md)</span>
  * <span class="">[도형에서의 불 연산: Polygon Union]</span>
  * <span class="">[델로네 삼각분할, 보로노이 다이어그램(D+)]</span>
  * <span class="">[Euclidean MST]</span>
  * <span class="additional">[3차원 기하학 헤더](/기하학/3D%20기하학%20헤더.md)</span>
    * <span class="additional">[외적, 면 법선 벡터 계산](/기하학/3D%20기하학%20헤더.md)</span>
    * <span class="additional">[거리 : point-face](/기하학/3D%20기하학%20헤더.md)</span>
    * <span class="">[로드리게스 회전]</span> <!-- https://jebae.github.io/rodrigues-rotation -->
  * <span class="diamond">[3D Convex Hull(D+)](/기하학/3D%20볼록껍질.md)</span>
  * <span class="">[Disk Convex Hull(R)]</span> <!-- https://www.acmicpc.net/problem/27957 -->
* ### [수학](/수학/개념%20정리.md)
  * #### 조합론, 수열
    <!-- https://justicehui.github.io/medium-algorithm/2024/02/10/combinatorics/ -->
    * <span class="additional">[이항계수 nCr](/수학/조합론/이항계수.md)</span>
      * <span class="silver">[파스칼의 삼각형(S+)](/수학/조합론/이항계수.md#forall-1-le-n-le-n-1-le-r-le-r에-대해-nCr-modm-전부-계산)</span>
      * <span class="gold">[모듈러 역원을 이용한 계산(G+)](/수학/조합론/이항계수.md#ncr-modp-계산)</span>
      * <span class="platinum">[뤼카정리(P-)](/수학/조합론/이항계수.md#ncr-modp-p-ll-n-계산)</span>
      * <span class="platinum">[p-지수를 이용한 계산(P-)](/수학/조합론/이항계수.md#ncr-modm-계산)</span>
      * <span class="diamond">[nCr mod p^e 계산(D-)](/수학/조합론/이항계수.md#ncr-modpe-계산)</span>
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
    <!-- XOR과 관련된 문제
    https://infossm.github.io/blog/2019/12/14/%EC%A3%BC%EC%96%B4%EC%A7%84-%EC%88%98%EB%93%A4%EC%9D%98-XOR-%EC%97%B0%EC%82%B0%EC%9C%BC%EB%A1%9C-%EB%A7%8C%EB%93%A4-%EC%88%98-%EC%9E%88%EB%8A%94-%EC%88%98/
    https://infossm.github.io/blog/2021/07/17/various-technic-solving-xor-problem/ -->
    <!-- * <span class="">[고합성수 찾기]</span>
    * <span class="">[우월고합성수]</span> -->
    <!-- Szemerédi–Trotter theorem -->
    * <span class="additional">[부등식](/수학/부등식.md)</span>
    * <span class="silver">[분할정복 거듭제곱(S+)](/수학/빠른%20거듭제곱.md)</span>
    * <span class="silver">[에라토스테네스의 체(S+)](/수학/에라토스테네스의%20체.md)</span>
    * <span class="gold">[Linear sieve 소수 판별(G-)](/수학/Linear%20Sieve.md)</span>
    * <span class="gold">[약수 리스트 계산(G-)](/수학/약수%20리스트%20계산.md)</span>
    * <span class="gold">[harmonic lemma 조화 수열 계산(G+)](/수학/Harmonic%20Lemma.md)</span>
    * <span class="gold">[harmonic lemma 배수 개수 계산(G+)](/수학/배수%20개수%20계산.md)</span>
    * <span class="gold">[p-지수(G+)](/수학/p-지수.md)</span>
    * <span class="gold">[확장 유클리드 호제법, 모듈러 역원(G+)](/수학/ExtendedGCD,%20Modular%20Inverse.md)</span>
    * <span class="">[Canonical Extended GCD]</span> <!-- https://panty.run/egcd/ -->
    * <span class="gold">[오일러 파이 함수(G+)](/수학/Phi%20Function.md)</span>
    * <span class="platinum">[중국인의 나머지 정리(P-)](/수학/CRT.md)</span>
    * <span class="">[Garner's algorithm]</span>
    * <span class="">[Barrett reduction]</span>
    * <span class="">[프뤼퍼 수열]</span> <!-- https://hongjun7.tistory.com/10 -->
    * <span class="">[베르누이 수]</span>
    * ~~<span class="platinum">[Faulhaber(P+)](/수학/Faulhaber.md)</span>~~
    * <span class="">[Stern-Brocot 트리]</span> <!-- https://blog.myungwoo.kr/126 --> <!-- https://youngyojun.github.io/secmem/2022/02/18/sigma-sum-stern-brocot/ --> <!-- https://zigui.tistory.com/29 -->
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
    * <span class="">[다중 대입값 계산]</span> <!-- https://infossm.github.io/blog/2019/06/16/Multipoint-evaluation/ -->
    * <span class="">[simplex]</span> <!-- https://velog.io/@wjleekr927/Simplex-algorithm -->
    * <span class="">[LP]</span>
    * <span class="">[XOR Convolution]</span>
    * <span class="">[FFT 응용]</span> <!-- https://hyperbolic.tistory.com/4 -->
    * <span class="">[online FFT]</span> <!-- https://cocoachan.tistory.com/15 -->
    * <span class="">[CDQ]</span> <!-- https://codeforces.com/blog/entry/111399 -->
    * <span class="">[FWHT]</span> <!-- https://velog.io/@dnr6054/Fast-Walsh-Hadamard-Transform -->
    * <span class="">[번사이드 보조정리]</span> <!-- https://algoshitpo.github.io/2020/02/09/burnside/ -->
    * <span class="">[홀의 결혼 정리]</span>
    * <span class="">[린드스트롬-게셀-비엔노 보조정리(LGV Lemma)]</span>
    * <span class="diamond">[라그랑주 보간법(D-)](/수학/라그랑주%20보간법.md)</span>
    * <span class="diamond">[Linear sieve 곱셈적 함수(D-)](/수학/곱셈적%20함수.md)</span>
    * <span class="diamond">[뫼비우스 함수(D-)](/수학/뫼비우스.md)</span>
    * <span class="diamond">[뫼비우스 반전(D-)](/수학/뫼비우스%20반전.md)</span>
    * <span class="diamond">[메르텐스 함수(D+)](/수학/메르텐스.md)</span>
    * <span class="diamond">[메르텐스 트릭, Xudyh's sieve (D+)](/수학/Xudyh's%20sieve.md)</span>
    * <span class="">[min_25's sieve]</span>
    * <span class="">[매트로이드(R-)]</span> <!-- https://m.blog.naver.com/kks227/221031527413 --> <!-- https://infossm.github.io/tags/matroid/ --> <!-- https://imeimi.tistory.com/45 --> <!-- https://m.blog.naver.com/kks227/221031527413 --> <!-- https://koosaga.com/252 --> <!-- https://joohs0505.tistory.com/4 --> <!-- https://dad-rock.tistory.com/673 -->
* ### 게임 이론
  * <span class="">[스프라그-그런디]</span> <!-- (비트셋) --> <!-- https://blog.myungwoo.kr/82 --> <!-- https://blog.myungwoo.kr/27 -->
  * <span class="">[hackenbush]</span> <!-- https://en.wikipedia.org/wiki/Hackenbush --> <!-- https://rkm0959.tistory.com/139 -->
  * <span class="">[coldgame]</span> <!-- https://infossm.github.io/blog/2024/11/01/Coldgame-problem-solving/ -->
* ### 기타
  * <span class="additional">[비트 트릭(A)](/기타/Bit%20Trick.md)</span>
  * <span class="">[정렬, `std::sort()` strict weak ordering]</span> <!-- https://panty.run/strict-weak-ordering/ -->
  * <span class="">[계수 정렬]</span>
  * <span class="silver">[기수 정렬(S-)](/기타/Radix%20Sort.md)</span>
  * <span class="silver">[이분 탐색(S-)](/기타/이분탐색.md)</span>
  * <span class="silver">[투 포인터(S-)](/기타/Two%20Pointer.md)</span>
  * <span class="silver">[비트마스크(S-)](/기타/Bitmask.md)</span>
  * <span class="silver">[좌표 압축(S-)](/기타/좌표압축.md)</span>
  * <span class="silver">[순열 사이클 분할(S+)](/기타/순열%20사이클%20분할.md)</span>
  * <span class="">[최적화]</span> <!-- https://cgiosy.github.io/posts/fast-io -->
  * <span class="">[Log Decomp]</span> <!-- https://codeforces.com/blog/entry/124766 -->
  * <span class="">[모노톤 스택]</span>
  * <span class="">[모노톤 큐]</span>
  * <span class="">[XOR Hashing]</span> <!-- https://codeforces.com/blog/entry/85900 -->
  * <span class="">[트리 해싱]</span> <!-- https://blog.cgiosy.dev/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%AC%B8%EC%A0%9C-%ED%92%80-%EB%95%8C-%EC%93%B0%EB%8A%94-%ED%95%B4%EC%8B%9C-%EC%A2%85%EB%A5%98%EB%93%A4 -->
  * <span class="">[누적합, imos]</span>
  * <span class="">[SIMD]</span>
  * <span class="">[Gray code](/기타/Gray%20code.md)</span>
  * <span class="gold">[후위 표기식(G+)](/기타/Postfix%20Notation.md)</span>
  * <span class="">[중간에서 만나기(G+)]</span>
  * <span class="platinum">[반전수(P-)](/기타/반전수.md)</span>
  * <span class="">[스위핑]</span>
  * <span class="">[슬라이딩 윈도우]</span>
  * <span class="">[Range Minimum Query]</span>
  * <span class="platinum">[덱을 이용한 구간 최댓값 트릭(P-)](/기타/Deque%20Trick.md)</span>
  * <span class="platinum">[삼분 탐색(P-)](/기타/삼분탐색.md)</span>
  * <span class="platinum">[Mo's algorithm(P+)](/기타/Mo's.md)</span>
  * <span class="">[hilbert Mo]</span> <!-- https://tamref.com/97 -->
  * <span class="platinum">[평방분할(P+)](/기타/제곱근%20분할법.md)</span>
  * <span class="">[병렬 이분 탐색(P+)]</span>
  * <span class="">[small to large]</span>
  * <span class="">[차이 부등식]</span> <!-- https://koosaga.com/72 --> <!-- https://www.acmicpc.net/workbook/view/3303 -->
  * <span class="">[range mode query]</span> <!-- https://infossm.github.io/blog/2021/05/20/Data-Structure-For-Range-Mode-Query/ --> <!-- https://www.acmicpc.net/problem/14898 -->
  * <span class="">[SMAWK]</span> <!-- https://github.com/koosaga/olympiad/blob/master/Library/codes/ad_hoc/smawk.cpp -->
  * <span class="">[춤추는 링크, 크누스 X]</span>
  * <span class="">[임의 정밀도(epsilon값 계산)(A)]</span> <!-- https://www.acmicpc.net/blog/view/37 -->
  * ~~<span class="">[담금질 기법]</span>~~ <!-- https://ryute.tistory.com/35    --> <!-- https://ryute.tistory.com/36    --> <!-- https://algospot.com/forum/read/1211/ --> <!-- https://koosaga.com/3 -->
  * <span class="">[DLAS]</span> <!-- https://cocoachan.tistory.com/12 --> <!-- https://gist.github.com/cgiosy/ed16f4988eeb7e989a97644fe61e1561 -->
  * <span class="">[Fracturing Search(D+)]</span> <!-- https://usaco.guide/adv/fracturing-search?lang=cpp --> <!-- https://www.acmicpc.net/problem/14166 --> <!-- https://blog.cube219.me/posts/2022/fracturing-search/ -->
  * <span class="">[선형 계획법]</span>
  * <span class="">[쌍대성]</span>
* ### utils
  * <span class="additional">[fastio](/utils/fastio.md)</span>
  * <span class="additional">[비트 연산](/utils/Bit.md)</span>
  * <span class="additional">[비트셋 덧셈, 뺄셈](/utils/비트셋%20덧셈뺄셈.md)</span>
  * <span class="additional">[문자열 압축](/utils/String%20Compression.md)</span>
  * <span class="additional">[개수 계산](/utils/Counter.md)</span>
  * <span class="additional">[랜덤](/utils/Random.md)</span>
  * <span class="additional">[고합성수 검색](/utils/Highly%20Composite%20Number.md)</span>
  * <span class="additional">[배열 연산](/utils/Array.md)</span>
  * <span class="additional">[가까운 2의 멱수 계산](/utils/Nearest%20Power2.md)</span>
  * <span class="additional">[시간 초 변환]</span>
  * <span class="additional">[날짜 변환](/utils/날짜%20변환.md)</span>
  * <span class="additional">[__int128 입출력](/utils/__int128%20입출력.md)</span>
  * <span class="">[파싱]</span>
  * <span class="additional">[utf-8 입력 처리](/utils/utf-8.md)</span>
  * <span class="additional">[n!, nCr, nHr 브루트포스 순회](/utils/n!%20nCr%20nHr%20브루트포스%20순회.md)</span>
  * <span class="">[modInt]</span>
  * <span class="">[infInt]</span>
  * <span class="">[bigInt]</span>
  * <span class="additional">[BaseInt](/utils/BaseInt.md)</span> <!-- bigint랑 합쳐서 구현하는 게 나을 듯 -->
# C++ 유용한 기능
* ### 문법
  * <span class="information">[Range-based for loop, 구조적 바인딩](/C++/문법/Range-based%20for%20loop.md)</span>
  * <span class="information">[람다 캡처, 재귀](/C++/문법/lambda.md)</span>
  * <span class="information">[constexpr](/C++/문법/constexpr.md)</span>
  * <span class="information">[ifdef](/C++/문법/ifdef.md)</span>
  * <span class="">[사전 정의 매크로]</span>
  * <span class="">[register]</span>
  * <span class="information">[리터럴](/C++/문법/리터럴.md)</span>
  * <span class="">[실수형 inf]</span> <!-- const double INF = 1/.0 --> <!-- 1/.0 > numeric_limits<double>::max() -->
  * <span class="">[using]</span> <!-- 기하학 풀 때 using ld; -->
  * <span class="">[저장 유형 지정자]</span> <!-- static, register -->
  * <span class="information">[template argument deduction](/C++/문법/Template%20Argument%20Deduction.md)</span>
  * <span class="information">[코드 여러줄 이어쓰기](/C++/문법/코드%20줄바꿈.md)</span>
* ### 함수
  * <span class="information">[수학관련](/C++/함수/수학%20관련.md)</span>
  * <span class="information">[배열관련](/C++/함수/배열%20관련.md)</span>
  * <span class="">[regex]</span>
  * <span class="">[constexpr, static_assert]</span> <!-- if constexpr 등등도 포함 -->
  * <span class="information">[multiset](/C++/함수/multiset.md)</span>
  * <span class="information">[permutation](/C++/함수/permutation.md)</span>
  * <span class="information">[casting](/C++/함수/casting%20operators.md)</span>
  * <span class="information">[GCC built-in](/C++/함수/builtin.md)</span>
  * <span class="information">[GCC 최적화](/C++/함수/GCC%20optimize.md)</span>
  * <span class="information">[문자관련](/C++/함수/char.md)</span>
  * <span class="information">[문자열관련](/C++/함수/string.md)</span>
  * <span class="information">[이분탐색 람다함수](/C++/함수/lower_bound_lambda.md)</span>
  * <span class="information">[custom pq](/C++/함수/custom%20pq.md)</span>
  * <span class="information">[io manip](/C++/함수/io%20manip.md)</span>
* ### ps용 환경설정
  * <span class="">[cph, competitive-companion]</span> <!-- https://chromewebstore.google.com/detail/competitive-companion/cjnmckjndlpiamhfimnnjmnckgghkjbl -->
  * <span class="information">[define](/C++/ps용%20환경설정/define.md)</span>
  * <span class="information">[vsc snippet](/C++/ps용%20환경설정/snippet.md)</span>
  * <span class="">[vim script]</span> <!-- auto cin -->
  * <span class="">[debug, c_cpp_properties.json 설정]</span>
  * <span class="">[Pre-defined Compiler Macros]</span> <!-- 버전 gnu++17로 해야 Template argument deduction 등 문법 사용가능 -->
  * <span class="">[percompiled header]</span> <!-- https://codeforces.com/blog/entry/79026 --> <!-- https://codeforces.com/blog/entry/53909? -->
* ### 기타
  * <span class="information">[자주 쓰는 변수명](/C++/기타/Variable%20Name.md)</span>
  * <span class="information">[코딩 아이디어](/C++/기타/Idea.md)</span> <!-- https://xy-plane.tistory.com/11 -->
# 파이썬
  * ### 유용한 함수
    * <span class="">[itertools]</span>
    * <span class="">[regex]</span>
    * <span class="">[eval]</span>
  * ### 숏코딩 팁
    * <span class="">[숏코딩 팁]</span>

# 참고링크
백준 알고리즘 분류   
https://www.acmicpc.net/problem/tags   

https://codeforces.com/blog/entry/125257

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

rkm0959 - PS 정수론 가이드   
https://rkm0959.tistory.com/category/PS/PS%20%EC%A0%95%EC%88%98%EB%A1%A0%20%EA%B0%80%EC%9D%B4%EB%93%9C

ahgus89 - 정수론   
https://ahgus89.github.io/

kcm1700 - 알고리즘 대회에 필요한 수학, 기하   
https://algospot.com/wiki/read/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98_%EB%8C%80%ED%9A%8C%EC%97%90_%ED%95%84%EC%9A%94%ED%95%9C_%EC%88%98%ED%95%99   
https://algospot.com/wiki/read/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98_%EB%8C%80%ED%9A%8C%EC%97%90_%ED%95%84%EC%9A%94%ED%95%9C_%EA%B8%B0%ED%95%98   

topology - 선형대수학   
https://tistory.joonhyung.xyz/18   

bowbowbow   
https://bowbowbow.tistory.com/category/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98   

kks227   
https://m.blog.naver.com/kks227?categoryNo=299&tab=1   

MJ Studio   
https://ps.mjstudio.net/categories/algorithm   

cubelover   
https://cubelover.tistory.com/

koosaga   
https://koosaga.com/242   

leo020630   
https://leo630.tistory.com/

yclock   
https://youngyojun.github.io/

S/W 멤버십 기술 블로그   
https://infossm.github.io/blog/   

gratus907   
https://gratus-blog.tistory.com/   

snowflake - 정수론 시리즈   
https://xy-plane.tistory.com/16

snowflake - 그린정리   
https://xy-plane.tistory.com/22

myungwoo   
https://blog.myungwoo.kr/

Nyaan   
https://nyaannyaan.github.io/library/data-structure/union-find-with-potential.hpp.html

stonejjun03   
https://stonejjun.tistory.com/category/%EC%BD%94%EB%94%A9/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%20%26%20%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0   

궁극의 웰노운 알고리즘   
https://cocoachan.tistory.com/

pentagon03   
https://howtoliveworldnice.tistory.com/category/Algorithm/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%20%EC%9D%B4%EB%A1%A0%20%EC%A0%95%EB%A6%AC

zigui - 기하학   
https://zigui.tistory.com/34

algoshitpo   
https://algoshitpo.github.io/   

imeimi2000   
https://imeimi.tistory.com/   

koosaga - olympiad Library codes   
https://github.com/koosaga/olympiad/tree/master/Library/codes   

kimjihoon   
https://etyu39.tistory.com/category/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98

TAMREF   
https://tamref.com/

h0ngjun7   
https://hongjun7.tistory.com/

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