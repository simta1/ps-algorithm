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
  * #### 세그먼트 트리
    * <span class="gold">[펜윅 트리(G+)](/자료구조/세그먼트%20트리/펜윅.md)</span>
    * <span class="gold">[세그먼트 트리(G+)](/자료구조/세그먼트%20트리/세그.md)</span>
    * <span class="gold">[비재귀 세그(G+)](/자료구조/세그먼트%20트리/비재귀%20세그.md)</span>
    * <span class="platinum">[세그 이분 탐색(P-)](/자료구조/세그먼트%20트리/세그%20이분%20탐색.md)</span>
    * <span class="platinum">[2D 펜윅(P-)](/자료구조/세그먼트%20트리/2차원%20펜윅.md)</span>
    * <span class="platinum">[2D 세그(P-)](/자료구조/세그먼트%20트리/2차원%20세그.md)</span>
    * <span class="platinum">[n차원 펜윅(P-)](/자료구조/세그먼트%20트리/다차원%20펜윅.md)</span>
    * <span class="platinum">[머지소트 트리(P-)](/자료구조/세그먼트%20트리/머지소트%20트리.md)</span>
    * <span class="platinum">[레이지 세그(P-)](/자료구조/세그먼트%20트리/레이지%20세그.md)</span>
    * <span class="">[비재귀 레이지 세그]</span> <!-- https://www.acmicpc.net/blog/view/117 -->
    * <span class="platinum">[다이나믹 세그, 다이나믹 레이지 세그(P-)](/자료구조/세그먼트%20트리/다이나믹%20세그.md)</span>
    * ~~<span class="platinum">[_range GCD 세그(P+)_](/자료구조/세그먼트%20트리/GCD%20세그.md)</span>~~
    * <span class="platinum">[금광 세그(P+)](/자료구조/세그먼트%20트리/금광%20세그.md)</span>
    * <span class="">[퍼시스턴트 세그(P+)]</span>
    * <span class="">[세그트리 비츠(D+)]</span>
  * #### BBST
    * <span class="diamond">[스플레이 트리(D-)](/자료구조/BBST/SplayTree.md)</span>
    * <span class="">[링크/컷 트리(D+)]</span>
    * <span class="">[레드-블랙 트리]</span>
  * #### 기타
    * <span class="gold">[분리 집합(G-)](/자료구조/기타/Disjoint%20Set.md)</span>
    * <span class="">[유니온 파인드 롤백]</span>
    * <span class="gold">[희소 배열(G+)](/자료구조/기타/희소배열.md)</span>
    * <span class="platinum">[XOR 트라이(P-)](/자료구조/기타/XOR%20Trie.md)</span>
    * <span class="">[로프]</span>
    * <span class="">[데카르트 트리]</span>
    * <span class="">[Line container]</span>
    * <span class="">[리-차오 트리(D-)]</span>
    <!-- * <span class="">[weighted QU]</span> -->
    <!-- * <span class="">[B-tree]</span>
    * <span class="">[SPQR tree]</span>
    * <span class="">[treap]</span>
    * <span class="">[wavelet 트리(P+)]</span> -->
* ### 그래프 이론
  * #### 그래프
    <!-- https://ps.mjstudio.net/tip-bfs-fill -->
    <!-- * <span class="">[온라인 동적 연결성 판정]</span> -->
    * <span class="">[flood fill]</span>
    * <span class="">[0-1 bfs(G-)]</span>
    * <span class="gold">[이분 그래프 판정(G-)](/그래프%20이론/그래프/이분그래프%20판정.md)</span>
    * <span class="gold">[다익스트라(G-)](/그래프%20이론/그래프/Dijkstra.md)</span>
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
    * <span class="platinum">[2-SAT(P-)](/그래프%20이론/그래프/2-SAT.md)</span>
    * <span class="platinum">[오일러 회로(P-)](/그래프%20이론/그래프/오일러%20회로.md)</span>
    * <span class="platinum">[단절점(P-)](/그래프%20이론/그래프/단절점.md)</span>
    * <span class="platinum">[단절선(P-)](/그래프%20이론/그래프/단절선.md)</span>
    * <span class="">[이중 연결 요소]</span>
    * <span class="">[블록 컷 트리]</span>
    * <span class="">[선인장]</span>
    * <span class="">[_2th MST(D-)_]</span>
    * <span class="">[쌍대 그래프(D-)]</span>
    * <span class="">[도미네이터 트리(D-)]</span>
    * <span class="">[오프라인 동적 연결성 판정]</span>
    * <span class="diamond">[유향 MST(D+)](/그래프%20이론/그래프/DMST.md)</span>
    * <span class="">[현 그래프(D+)]</span>
    * <span class="">[일반 매칭(D+)]</span>
    * <span class="ruby">[offline incremental SCC(R-)](/그래프%20이론/그래프/Offline%20Incremental%20SCC.md)</span>
    <!-- * <span class="">[현 그래프 판정]</span> -->
    <!-- * <span class="">[Perfect Elimination Ordering]</span> -->
    <!-- * <span class="">[_최소 차수 MST_]</span> -->
  * #### [네트워크 플로우](/그래프%20이론/네트워크%20플로우/개념%20정리.md)
    * <span class="platinum">[최대유량: Edmonds-Karp (P-)](/그래프%20이론/네트워크%20플로우/최대%20유량.md)</span>
    * <span class="">[최대유량: Dinic (P-)]</span>
    * ~~<span class="">[최대유량: Push-Relabel (P-)]</span>~~
    * <span class="platinum">[최소 비용 최대 유량(P+)](/그래프%20이론/네트워크%20플로우/MCMF.md)</span>
    * <span class="platinum">[이분 매칭(P-)](/그래프%20이론/네트워크%20플로우/이분매칭.md)</span>
    * <span class="">[Circulation]</span> <!-- https://blog.naver.com/kks227/221426339344 -->
    * <span class="">[이분 매칭: Hopcraft-Karp]</span>
    * <span class="">[Stoer-Wagner Algorithm]</span>
    * <span class="">[Gomory-Hu Tree]</span>
    * <span class="">[헝가리안]</span>
    * <span class="">[L-R flow]</span>
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
  <!-- 비트셋 배낭 https://www.acmicpc.net/problem/16072 -->
  <!-- * <span class="">[비트셋 LCS]</span> -->
  <!-- * <span class="">[비트 집합]</span> -->
  * <span class="silver">[Kadane algorithm(S+)](/DP/Kadane%20Algorithm.md)</span>
  * <span class="gold">[LCS(G-)](/DP/lcs.md)</span>
  * <span class="gold">[배낭 문제(G-)](/DP/Knapsack.md)</span>
  * <span class="gold">[비트셋 배낭(G-)](/DP/Knapsack(Bitset).md)</span> <!-- https://egod1537.tistory.com/entry/Bounded-Knapsack-Problem%ED%9A%A8%EC%9C%A8%EC%A0%81%EC%9C%BC%EB%A1%9C-%ED%95%B4%EA%B2%B0%ED%95%98%EA%B8%B0 -->
  * <span class="gold">[비트마스크 DP(G+)](/DP/Bitmask%20DP.md)</span>
  * <span class="">[최단거리 역추적]</span>
  * <span class="">[SOS DP(D-)](/DP/SOS%20DP.md)</span>
  * <span class="">[히르쉬버그(D+)]</span>
  * <span class="">[Connection Profile DP]</span>
  * <span class="">[토글링]</span>
  * <span class="platinum">[볼록껍질 최적화(P+)](/DP/CHT.md)</span>
  * <span class="platinum">[분할정복 최적화(P+)](/DP/DnC.md)</span>
  * <span class="">[크누스 최적화]</span>
  * <span class="">[단조큐 최적화]</span>
  * <span class="">[Slope trick(D-)]</span>
  * <span class="">[키타마사(D-)]</span>
  * <span class="">[벌레캠프-매시(D+)]</span>
  <!-- * <span class="">[aliens 트릭(D-)]</span> -->
* ### 문자열
<!-- RBS(Regular Bracket Sequence) -->
  * <span class="gold">[트라이(G+)](/문자열/Trie.md)</span>
  * <span class="platinum">[매내처(P-)](/문자열/Manacher.md)</span>
  * <span class="platinum">[KMP(P-)](/문자열/KMP.md)</span>
  * <span class="platinum">[아호 코라식(P+)](/문자열/Aho-Corasick.md)</span>
  * ~~<span class="">[bitap algorithm]</span>~~
  * <span class="">[해싱]</span>
  * <span class="">[라빈 카프]</span>
  * <span class="platinum">[접미사 배열과 lcp 배열(P+)](/문자열/Suffix%20and%20LCP%20Array.md)</span>
  * <span class="">[Z algorithm]</span>
  * <span class="diamond">[회문 트리(D+)](/문자열/회문%20트리.md)</span>
  * <span class="">[접미사 트리(R-)]</span>
* ### 기하학
  <!-- * ~~<span class="">[반공간 교집합]</span>~~ -->
  * <span class="gold">[cross product, CCW, 직선-점 거리 계산(G-)](/기하학/Geometry%20Header.md)</span>
  * <span class="">[plane sweeping]</span>
  * <span class="gold">[볼록다각형 넓이(G-)](/기하학/Polygon%20Area.md)</span>
  * <span class="">[볼록다각형 판정]</span>
  * <span class="gold">[선분교차판정(G+)](/기하학/선분교차판정.md)</span>
  * <span class="platinum">[선분교차점 계산(P-)](/기하학/Intersection%20Calculate(LL).md)</span>
  * <span class="platinum">[볼록 껍질(P-)](/기하학/볼록%20껍질.md)</span>
  * <span class="platinum">[가장 먼 두 점 : 회전하는 캘리퍼스(P-)](/기하학/Rotating%20Calipers.md)</span>
  * <span class="platinum">[다각형 내부의 점 판정(P-)](/기하학/PIP.md)</span>
  * <span class="platinum">[볼록 다각형 내부의 점 판정(P+)](/기하학/PIP(convex).md)</span>
  * <span class="platinum">[등적등주 분할(P+)](/기하학/Equalizer.md)</span>
  * <span class="platinum">[가장 가까운 두 점(P+)](/기하학/Closest%20Two%20Points.md)</span>
  * <span class="">[최소 외접원(P+)]</span>
  * <span class="">[볼록다각형 접선]</span>
  * <span class="">[불도저]</span>
  * <span class="">[반평면 교집합(D-)]</span>
  * <span class="">[KD tree]</span>
  * <span class="">[그린 정리(D+)]</span>
  * <span class="">[델로네 삼각분할(R-)]</span>
  * <span class="">[보로노이 다이어그램(R-)]</span>
* ### [수학](/수학/개념%20정리.md)
  <!-- * <span class="">[고합성수 찾기]</span>
  * <span class="">[우월고합성수]</span> -->
  <!-- * <span class="">[Linear-sieve]</span> -->
  * <span class="silver">[에라토스테네스의 체(S+)](/수학/에라토스테네스의%20체.md)</span>
  * <span class="silver">[분할정복 거듭제곱(S+)](/수학/빠른%20거듭제곱.md)</span>
  * <span class="silver">[nCr, 파스칼의 삼각형(S+)](/수학/Combination(DP).md)</span>
  * <span class="gold">[p-지수(G+)](/수학/p-지수.md)</span>
  * <span class="gold">[확장 유클리드 호제법, 모듈러 역원(G+)](/수학/ExtendedGCD,%20Modular%20Inverse.md)</span>
  * <span class="gold">[오일러 파이 함수(G+)](/수학/Phi%20Function.md)</span>
  * <span class="platinum">[중국인의 나머지 정리(P-)](/수학/CRT.md)</span>
  * <span class="">[Garner's algorithm]</span>
  * <span class="">[nCr mod 소수, 뤼카(P-)]</span>
  * <span class="">[nCr mod 합성수(D-)]</span>
  * <span class="platinum">[밀러-라빈 소수 판별법(P+)](/수학/MillerRabin.md)</span>
  * <span class="platinum">[폴라드 로(P+)](/수학/PollardRho.md)</span>
  * <span class="">[이산 로그(P+)]</span>
  * <span class="platinum">[FFT(P+)](/수학/FFT.md)</span>
  * ~~<span class="">[카라츠바]</span>~~
  * <span class="">[3진 FFT(D-)]</span>
  * <span class="diamond">[NTT(D-)](/수학/NTT.md)</span>
  * <span class="">[FFT 나눗셈]</span>
  * <span class="">[FFT 응용]</span> <!-- https://hyperbolic.tistory.com/4 -->
  * <span class="">[online FFT]</span>
  * <span class="">[포함 배제의 원리, 뫼비우스 함수, 뫼비우스 반전(D-)]</span>
  * <span class="">[생성 함수(D-)]</span>
  * <span class="diamond">[Tonelli-Shanks algorithm(D-)](/수학/Tonelli-Shanks.md)</span>
  * <span class="diamond">[Cornacchia's algorithm(D-)](/수학/Cornacchia.md)</span>
  * <span class="">[이산 제곱근]</span>
  * <span class="">[메르텐스 함수]</span>
  * <span class="">[매트로이드(R-)]</span>
* ### 선형대수학
  * <span class="silver">[행렬(S-)](/선형대수학/Matrix.md)</span>
  * <span class="">[가우스 소거법(P-)]</span>
  * <span class="">[키르히호프(P-)]</span> <!-- https://www.acmicpc.net/problem/9614 -->
* ### 게임 이론
  * <span class="">[스프라그-그런디]</span> <!-- (비트셋) -->
  * <span class="">[hackenbush]</span>
* ### 기타
  * <span class="additional">[비트 트릭(A)](/기타/Bit%20Trick.md)</span>
  * <span class="">[계수 정렬]</span>
  * <span class="silver">[기수 정렬(S-)](/기타/Radix%20Sort.md)</span>
  * <span class="silver">[이분탐색(S-)](/기타/이분탐색.md)</span>
  * <span class="silver">[투 포인터(S-)](/기타/Two%20Pointer.md)</span>
  * <span class="silver">[비트마스크(S-)](/기타/Bitmask.md)</span>
  * <span class="silver">[좌표 압축(S-)](/기타/좌표압축.md)</span>
  * <span class="silver">[순열 사이클 분할(S+)](/기타/순열%20사이클%20분할.md)</span>
  * <span class="">[모노톤 스택]</span>
  * <span class="">[모노톤 큐]</span>
  * <span class="">[누적합, imos]</span>
  * <span class="gold">[후위 표기식(G+)](/기타/Postfix%20Notation.md)</span>
  * <span class="">[중간에서 만나기(G+)]</span>
  * <span class="platinum">[반전수(P-)](/기타/반전수.md)</span>
  * <span class="">[스위핑]</span>
  * <span class="">[슬라이딩 윈도우]</span>
  * <span class="platinum">[덱을 이용한 구간 최댓값 트릭(P-)](/기타/Deque%20Trick.md)</span>
  * <span class="platinum">[삼분 탐색(P-)](/기타/삼분탐색.md)</span>
  * <span class="platinum">[Mo's algorithm(P+)](/기타/Mo's.md)</span>
  * <span class="platinum">[평방분할(P+)](/기타/제곱근%20분할법.md)</span>
  * <span class="">[병렬 이분 탐색(P+)]</span>
  * <span class="">[춤추는 링크, 크누스 X]</span>
  * <span class="">[임의 정밀도(epsilon값 계산)(A)]</span>
  * ~~<span class="">[담금질 기법]</span>~~
* ### utils
  * <span class="">[fastio]</span> <!-- https://www.acmicpc.net/blog/view/105 -->
  * <span class="additional">[문자열 압축](/utils/String%20Compression.md)</span>
  * <span class="additional">[개수 계산](/utils/Counter.md)</span>
  * <span class="additional">[랜덤](/utils/Random.md)</span>
  * <span class="additional">[고합성수 검색](/utils/Highly%20Composite%20Number.md)</span>
  * <span class="additional">[배열 연산](/utils/Array.md)</span>
  * <span class="additional">[가까운 2의 멱수 계산](/utils/Nearest%20Power2.md)</span>
  * <span class="additional">[bigInt]()</span>
  * <span class="additional">[baseInt]()</span> <!-- bigint랑 합쳐서 구현하는 게 나을 듯 -->
# C++ 유용한 기능
* ### 문법
  * <span class="">[range-based for loop]</span>
  * <span class="">[using]</span> <!-- 기하학 풀 때 using ld; -->
  * <span class="">[literal]</span>
  * <span class="information">[template argument deduction](/C++/문법/Template%20Argument%20Deduction.md)</span>
  * <span class="">[람다 재귀]</span>
  * <span class="">[코드 여러줄 이어쓰기]</span>
  * <span class="">[리터럴 여러줄 이어쓰기]</span>
* ### 함수
  * <span class="">[수학관련]</span> <!-- atan, atan2 추가하기 -->
  * <span class="">[배열관련]</span> <!-- copy doubling -->
  * <span class="information">[타입관련](/C++/함수/casting%20operators.md)</span>
  * <span class="information">[GCC built-in](/C++/함수/builtin.md)</span>
  * <span class="information">[문자관련](/C++/함수/char.md)</span>
  * <span class="information">[문자열관련](/C++/함수/string.md)</span>
  * <span class="information">[이분탐색 람다함수](/C++/함수/lower_bound_lambda.md)</span>
  * <span class="">[permutation]</span>
  * <span class="information">[custom pq](/C++/함수/costom%20pq.md)</span>
  * <span class="">[io manip]</span>
  * <span class="information">[ext](/C++/함수/ext.md)</span>
* ### ps용 환경설정
  * <span class="">[cph]</span>
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
# 참고문헌
tlsdydaud1   
https://00ad-8e71-00ff-055d.tistory.com/3   

jh05013   
https://jh05013.github.io/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/   

jhnah917   
https://justicehui.github.io/tutorial/   
https://github.com/justiceHui/Unknown-To-Wellknown   

jin814   
https://blog.naver.com/jinhan814/222439886998   
https://blog.naver.com/PostView.naver?blogId=jinhan814&logNo=222689836982&parentCategoryNo=&categoryNo=6&viewDate=&isShowPopularPosts=false&from=postView   

kcm1700   
https://algospot.com/wiki/read/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98_%EB%8C%80%ED%9A%8C%EC%97%90_%ED%95%84%EC%9A%94%ED%95%9C_%EC%88%98%ED%95%99   

https://algospot.com/wiki/read/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98_%EB%8C%80%ED%9A%8C%EC%97%90_%ED%95%84%EC%9A%94%ED%95%9C_%EA%B8%B0%ED%95%98

백준 알고리즘 분류   
https://www.acmicpc.net/problem/tags   

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

# 알고리즘 순서
```mermaid
stateDiagram-v2
direction LR

%% [*] --> 자료구조
자료구조 --> 펜윅_트리
  펜윅_트리 --> 2D_펜윅
  2D_펜윅 --> n차원_펜윅
자료구조 --> 세그먼트_트리
  세그먼트_트리 --> 2D_세그
  세그먼트_트리 --> 머지소트_트리
  세그먼트_트리 --> 다이나믹_세그
  세그먼트_트리 --> 레이지_세그
    다이나믹_세그 --> 다이나믹_레이지_세그
    레이지_세그 --> 다이나믹_레이지_세그
  세그먼트_트리 --> 금광_세그
자료구조 --> 스플레이_트리
레이지_세그 --> 스플레이_트리
자료구조 --> 분리_집합
자료구조 --> 희소_배열

%% [*] --> 그래프_이론
%% 그래프_이론 --> 그래프
  그래프 --> 최소_스패닝_트리
  그래프 --> 이분_그래프_판정
  그래프 --> 다익스트라
  그래프 --> 벨만_포드
    벨만_포드 --> SPFA
  그래프 --> 플로이드_워셜
  그래프 --> 정점_착색수
  그래프 --> 위상_정렬
  그래프 --> 강한_연결_요소
    강한_연결_요소 --> 2_SAT
  그래프 --> 오일러_회로
  그래프 --> 단절량
  그래프 --> 단절선
  그래프 --> 유향_최소_신장_트리
그래프 --> 네트워크_플로우
  네트워크_플로우 --> 최대유량
  최대유량 --> 최소_비용_최대_유량
  SPFA --> 최소_비용_최대_유량
  네트워크_플로우 --> 이분_매칭
그래프 --> 트리
  트리 --> 최소_공통_조상
  희소_배열 --> 최소_공통_조상
  트리 --> 오일러_경로_테크닉

%% [*] --> 동적_계획법
동적_계획법 --> 비트마스크_DP
동적_계획법 --> 볼록껍질_최적화
동적_계획법 --> 분할정복_최적화

%% [*] --> 수학
수학 --> 에라토스테네스의_체
수학 --> 조합론
조합론 --> nCr_파스칼의_삼각형
동적_계획법 --> nCr_파스칼의_삼각형
조합론 --> nCr_mod_소수
모듈러_역원 --> nCr_mod_소수
%% nCr_mod_소수 --> 뤼카
수학 --> 분할정복_거듭제곱
분할정복_거듭제곱 --> 행렬_거듭제곱
분할정복_거듭제곱 --> 밀러_라빈_소수_판별법
밀러_라빈_소수_판별법 --> 폴라드_로
유클리드_호제법 --> 폴라드_로
수학 --> 유클리드_호제법
유클리드_호제법 --> 확장_유클리드_호제법
확장_유클리드_호제법 --> 모듈러_역원
모듈러_역원 --> 중국인의_나머지_정리
수학 --> 오일러_파이_함수
수학 --> FFT
FFT --> NTT
중국인의_나머지_정리 --> NTT

%% [*] --> 문자열
문자열 --> 트라이
트라이 --> XOR_트라이
문자열 --> KMP
트라이 --> 아호_코라식
KMP --> 아호_코라식
%% 계수_정렬 --> 접미사_배열과_lcp_배열
문자열 --> 접미사_배열과_lcp_배열
문자열 --> 펠린드롬
펠린드롬 --> 매내처
펠린드롬 --> 회문_트리

%% [*] --> 기하학
기하학 --> 외적
외적 --> ccw
외적 --> 직선_점_거리_계산
ccw --> 선분교차판정
ccw --> 볼록껍질
ccw --> 회전하는_캘리퍼스
ccw --> 다각형_내부의_점_판정
ccw --> 볼록_다각형_내부의_점_판점
기하학 --> 가장_가까운_두_점

[*] --> 기타
기타 --> 이분_탐색
이분_탐색 --> 볼록_다각형_내부의_점_판점
기타 --> 값_좌표_압축
기타 --> 순열_사이클_분할
기타 --> Mo's
기타 --> 평방분할

%% 나중에 추가할 거 같은 간선
%% 트리_압축 --> 유향_최소_신장_트리
%% 최대유량_Dinic --> 이칭_매칭_Hopcraft_Karp
%% 트라이 --> 아호_코라식
%% ccw --> 볼록다각형_판정
```