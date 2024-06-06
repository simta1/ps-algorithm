<style>   
  .silver { background-color:#C5D5D5 }   
  .gold { background-color:#FFF5B1 }   
  .platinum { background-color:#DCFFE4 }   
  .diamond { background-color:#C0FFFF }   
  .ruby { background-color:#FFC0C0 }   
  .additional { background-color:#E4BBFE }   
  .information { background-color:#ABCDEF }   
</style>   
##
### 코드 작성
변수명 통일 -> [참고](/C++%20관련%20정보들/기타/Variable%20Name.md)   
vector쓸 땐 array doubling 고려   
매개변수로 vector나 string 받을 땐 가능하면 최대한 상수 참조 사용   

### 카테고리 작성
css로 티어색깔 표시. \<span class="tier"> 사용   
알고리즘의 난이도는 1\~3은 +, 4\~5는 -로 표시. ex) 브론즈3 이상: B+   
백준에 단일 태그로 존재하는 주요 알고리즘이나 유명한 트릭은 __볼드체__ 로 표시   
이외 지엽적이거나 추가적인 구현체는 _이텔릭체_ 로 표시   
<!-- 별로 중요하지 않거나 구현계획 없는 알고리즘은 ~~취소선~~으로 표시 -->

### 문서 작성
VSC markdown.json에 문서 작성용 템플릿 있음. SNIP explain으로 사용   
__주의사항__ 에 코드 작성하면서 겪었던 런타임 에러나 오류들 기록   
코드를 사용할 때의 주의사항이 아니라 해당 코드 구현하면서 겪은 주의사항을 기록   
__시간복잡도__ 는 LaTeX 수식 사용. log(N)은 괄호 없이 logN으로 표기   
__사용관련__ 은 코드 사용할 때 참고할 내용 기록   
__백준문제__ 에는 혹시 코드 수정하게 됐을 때 테스트해볼 수 있도록 문제 링크 적어두기   
##

# ps algorithm
티어 분류 :
<span class="silver">실버(S)<span>
<span class="gold">골드(G)<span>
<span class="platinum">플레(P)<span>
<span class="diamond">다이아(D)<span>
<span class="ruby">루비(R)<span>
<span class="additional">기타 지식(A)<span>

* ### 자료구조
  * #### 세그먼트 트리
    * <span class="gold">[__펜윅 트리(G+)__](/자료구조/세그먼트%20트리/FenwickTree.md)</span>
    * <span class="gold">[__세그먼트 트리(G+)__](/자료구조/세그먼트%20트리/SegmentTree.md)</span>
    * <span class="platinum">[__머지소트 트리(P-)__](/자료구조/세그먼트%20트리/MergesortTree.md)</span>
    * <span class="platinum">[__2D 펜윅(P-)__](/자료구조/세그먼트%20트리/FenwickTree2D.md)</span>
    * <span class="platinum">[__2D 세그(P-)__](/자료구조/세그먼트%20트리/SegmentTree2D.md)</span>
    * <span class="platinum">[__n차원 펜윅(P-)__](/자료구조/세그먼트%20트리/Multi%20Dimensional%20FenwickTree.md)</span>
    * <span class="platinum">[__레이지 세그(P-)__](/자료구조/세그먼트%20트리/SegmentTree(Lazy%20Propagation).md)</span>
    * <span class="platinum">[__다이나믹 세그, 다이나믹 레이지 세그(P-)__](/자료구조/세그먼트%20트리/Dynamic%20SegmentTree.md)</span>
    * <span class="platinum">[_range GCD 세그(P+)_](/자료구조/세그먼트%20트리/GCD%20SegmentTree.md)</span>
    * <span class="platinum">[__금광 세그(P+)__](/자료구조/세그먼트%20트리/Gold%20Mine%20SegmentTree.md)</span>
    * <span class="">[__퍼시스턴트 세그(P+)__]</span>
    * <span class="">[__세그트리 비츠(D+)__]</span>
  * #### BBST
    * <span class="diamond">[__스플레이 트리(D-)__](/자료구조/BBST/SplayTree.md)</span>
    * <span class="">[__링크/컷 트리(D+)__]</span>
    * ~~<span class="">[__AVL 트리__]</span>~~
    * <span class="">[__레드-블랙 트리__]</span>
  * #### 기타
    * <span class="gold">[__분리 집합(G-)__](/자료구조/기타/Disjoint%20Set.md)</span>
    * <span class="gold">[__희소 배열(G+)__](/자료구조/기타/Sparse%20Table.md)</span>
    * <span class="">[__로프__]</span>
    * <span class="">[__데카르트 트리__]</span>
    <!-- * <span class="">[__SPQR tree__]</span> -->
    * <span class="">[__Line container__]</span>
    * <span class="">[__리-차오 트리(D-)__]</span>
    <!-- * <span class="">[__B-tree__]</span>
    * <span class="">[__treap__]</span>
    * <span class="">[__wavelet 트리(P+)__]</span> -->
* ### 쿼리 관련
  * <span class="platinum">[__Mo's algorithm(P+)__](/쿼리%20관련/Mo's%20Algorithm.md)</span>
  * <span class="platinum">[__평방분할(P+)__](/쿼리%20관련/Sqrt%20Decomposition.md)</span>
* ### 그래프 이론
  * #### 그래프
    * <span class="">[__0-1 bfs(G-)__]</span>
    * <span class="gold">[__다익스트라(G-)__](/그래프%20이론/그래프/Dijkstra.md)</span>
    * ~~<span class="">[__A*__]</span>~~
    * <span class="gold">[__벨만-포드(G-)__](/그래프%20이론/그래프/Bellman-Ford.md)</span>
    * <span class="gold">[__SPFA(G-)__](/그래프%20이론/그래프/SPFA.md)</span>
    * <span class="gold">[__플로이드 워셜(G-)__](/그래프%20이론/그래프/Floyd-Warshall.md)</span>
    * <span class="gold">[__최소 스패닝 트리: Kruskal(G-)__](/그래프%20이론/그래프/MST(Kruskal).md)</span>
    * ~~<span class="">[__최소 스패닝 트리: Prim(G-)__]</span>~~
    * <span class="">[__최소 스패닝 트리: Borůvka__]</span>
    * <span class="gold">[_정점 착색수(G+)_](/그래프%20이론/그래프/Graph%20Coloring.md)</span>
    * <span class="">[_간선 착색수_]</span>
    * <span class="gold">[__위상 정렬(G+)__](/그래프%20이론/그래프/Topological%20Sort.md)</span>
    * <span class="platinum">[__강한 연결 요소(P-)__](/그래프%20이론/그래프/Strongly%20Connected%20Component.md)</span>
    * <span class="platinum">[__2-SAT(P-)__](/그래프%20이론/그래프/2-SAT.md)</span>
    * <span class="">[_오일러 회로(P-)_]</span>
    * <span class="platinum">[__단절점(P-)__](/그래프%20이론/그래프/Articulation%20Point.md)</span>
    * <span class="platinum">[__단절선(P-)__](/그래프%20이론/그래프/Articulation%20Bridge.md)</span>
    * <span class="">[__이중 연결 요소__]</span>
    * <span class="">[__블록 컷 트리__]</span>
    * <span class="">[__선인장__]</span>
    * <span class="">[_2th MST(D-)_]</span>
    * <span class="">[__쌍대 그래프(D-)__]</span>
    * <span class="">[__도미네이터 트리(D-)__]</span>
    * <span class="diamond">[__유향 MST(D+)__](/그래프%20이론/그래프/Directed%20Minimum%20Spanning%20Tree.md)</span>
    * <span class="">[__현 그래프(D+)__]</span>
    * <span class="">[__일반 매칭(D+)__]</span>
    <!-- * <span class="">[_최소 차수 MST_]</span> -->
  * #### 네트워크 플로우
    * <span class="platinum">[__최대유량 알고리즘들 정리__](/그래프%20이론/네트워크%20플로우/MaxFlow.md)</span>
    * <span class="platinum">[__최대유량: Edmonds-Karp (P-)__](/그래프%20이론/네트워크%20플로우/Edmonds-Karp.md)</span>
    * <span class="">[__최대유량: Dinic (P-)__]</span>
    * ~~<span class="">[__최대유량: Push-Relabel (P-)__]</span>~~
    * <span class="platinum">[__최소 비용 최대 유량(P+)__](/그래프%20이론/네트워크%20플로우/MCMF.md)</span>
    * <span class="platinum">[__이분 매칭(P-)__](/그래프%20이론/네트워크%20플로우/Bipartite%20Matching.md)</span>
    * <span class="">[__이분 매칭: Hopcraft-Karp__]</span>
    * <span class="">[__Stoer-Wagner Algorithm__]</span>
    * <span class="">[__Gomory-Hu Tree__]</span>
    * <span class="">[__헝가리안__]</span>
    * <span class="">[__L-R flow__]</span>
  * #### 트리
    * <span class="platinum">[__최소 공통 조상(P-)__](/그래프%20이론/트리/Lowest%20Common%20Ancestor.md)</span>
    * <span class="platinum">[__LCA를 통한 트리 쿼리(P-)__](/그래프%20이론/트리/Tree%20Query%20Using%20LCA.md)</span>
    * <span class="platinum">[__오일러 경로 테크닉(P-)__](/그래프%20이론/트리/Euler%20Tour%20Technique.md)</span>
    * <span class="">[__heavy-light 분할(P+)__]</span>
    * <span class="">[__트리 압축__]</span>
    * <span class="">[__센트로이드 분할(D-)__]</span>
    * <span class="">[__트리 동형 사상__]</span>
    * <span class="">[__탑 트리(R-)__]</span>
* ### DP
  * #### 유명한 문제
    * <span class="">[__배낭 문제(G-)__]</span>
    * <span class="">[__LIS__]</span>
    * <span class="">[__LCS__]</span>
    * <span class="">[__행렬 곱셈 순서__]</span>
    * <span class="">[__TSP__]</span>
  * #### 여러 DP 유형
    * <span class="">[__DP dfs 구현코드__](/DP/여러%20DP%20유형/DP%20by%20dfs.md)</span>
    * <span class="gold">[__비트마스크 DP(G+)__](/DP/여러%20DP%20유형/Bitmask%20DP.md)</span>
    * <span class="">[__최단거리 역추적__]</span>
    * <span class="">[__SOS DP__]</span>
    * <span class="">[__히르쉬버그(D+)__]</span>
    * <span class="">[__Connection Profile DP__]</span>
  * #### 최적화
    * <span class="">[__토글링__]</span>
    * <span class="gold">[__비트셋 배낭(G-)__](/DP/최적화/Bitset%20Knapsack.md)</span>
    * <span class="">[__비트셋 LCS__]</span>
    * <span class="">[__비트 집합__]</span>
    * <span class="platinum">[__볼록껍질 최적화(P+)__](/DP/최적화/CHT.md)</span>
    * <span class="">[__분할정복 최적화__]</span>
    * <span class="">[__크누스 최적화__]</span>
    * <span class="">[__단조큐 최적화__]</span>
    * <span class="">[__Slope trick(D-)__]</span>
  * #### 기타
    * <span class="">[__키타마사(D-)__]</span>
    * <span class="">[__벌레캠프-매시(D+)__]</span>
  <!-- * <span class="">[__aliens 트릭(D-)__]</span> -->
* ### 문자열
  * <span class="gold">[__트라이(G+)__](/문자열/Trie.md)</span>
  * <span class="platinum">[__KMP(P-)__](/문자열/Knuth-Morris-Pratt%20Algorithm.md)</span>
  * ~~<span class="">[__bitap algorithm__]</span>~~
  * <span class="">[__해싱__]</span>
  * <span class="">[__라빈 카프__]</span>
  * <span class="">[__아호 코라식__]</span>
  * <span class="">[__매내처__]</span>
  * <span class="platinum">[__접미사 배열과 lcp 배열(P+)__](/문자열/Suffix%20Array.md)</span>
  * <span class="">[__Z algorithm__]</span>
  * <span class="diamond">[__회문 트리(D+)__](/문자열/Palindromic%20Tree.md)</span>
  * <span class="">[__접미사 트리(R-)__]</span>
* ### 기하학
  * <span class="gold">[__cross product, CCW(G-)__](/기하학/Cross%20Product,%20CCW.md)</span>
  * <span class="">[__볼록다각형 판정__]</span>
  * <span class="gold">[__직선-점 거리 계산(G-)__](/기하학/Distance.md)</span>
  * <span class="gold">[__선분교차판정(G+)__](/기하학/Line-Line%20Intersection%20check.md)</span>
  * <span class="platinum">[_선분교차점 계산(P-)_](/기하학/Line-Line%20Intersection%20calculate.md)</span>
  * <span class="platinum">[__볼록 껍질(P-)__](/기하학/Graham%20Scan.md)</span>
  * <span class="platinum">[__가장 먼 두 점 : 회전하는 캘리퍼스(P-)__](/기하학/Rotating%20Calipers.md)</span>
  * <span class="platinum">[__다각형 내부의 점 판정(P-)__](/기하학/Point%20In%20Polygon.md)</span>
  * <span class="platinum">[__볼록 다각형 내부의 점 판정(P+)__](/기하학/Point%20In%20Convex%20Polygon.md)</span>
  * <span class="platinum">[_가장 가까운 두 점(P+)_](/기하학/Closest%20Two%20Points.md)</span>
  * <span class="">[__최소 외접원(P+)__]</span>
  * <span class="">[_반 나누기_]</span>
  * <span class="">[__불도저__]</span>
  * <span class="">[__반평면 교집합(D-)__]</span>
  * ~~<span class="">[__반공간 교집합__]</span>~~
  * <span class="">[__KD tree__]</span>
  * <span class="">[__그린 정리(D+)__]</span>
  * <span class="">[__델로네 삼각분할(R-)__]</span>
  * <span class="">[__보로노이 다이어그램(R-)__]</span>
* ### 수학
  * <span class="silver">[__에라토스테네스의 체(S+)__](/수학/Sieve%20of%20Eratosthenes.md)</span>
  * <span class="silver">[__분할정복 거듭제곱(S+)__](/수학/Power.md)</span>
  * <span class="silver">[__nCr, 파스칼의 삼각형(S+)__](/수학/Combination%20by%20DP.md)</span>
  * <span class="gold">[__행렬 거듭제곱(G-)__](/수학/Matrix.md)</span>
  * <span class="gold">[__확장 유클리드 호제법, 모듈러 역원(G+)__](/수학/ExtendedGCD,%20Modular%20Inverse.md)</span>
  * <span class="gold">[__오일러 파이 함수(G+)__](/수학/Euler's%20Totient%20Function.md)</span>
  * <span class="">[__가우스 소거법(P-)__]</span>
  * <span class="">[_키르히호프(A)_]</span> <!-- https://www.acmicpc.net/problem/9614 -->
  * <span class="platinum">[__중국인의 나머지 정리(P-)__](/수학/Chinese%20Remainder%20Theorem.md)</span>
  * <span class="">[__Garner's algorithm__]</span>
  * <span class="">[__nCr mod 소수, 뤼카(P-)__]</span>
  * <span class="">[__nCr mod 합성수(D-)__]</span>
  * <span class="">[__이산 로그(P+)__]</span>
  * <span class="platinum">[__밀러-라빈 소수 판별법(P+)__](/수학/MillerRabin.md)</span>
  * <span class="platinum">[__폴라드 로(P+)__](/수학/PollardRho.md)</span>
  * ~~<span class="">[__카라츠바__]</span>~~
  * <span class="platinum">[__FFT(P+)__](/수학/Fast%20Fourier%20Transform.md)</span>
  * <span class="">[__3진 FFT(D-)__]</span>
  * <span class="">[__정밀도 높은 FFT(D-)__]</span>
  * <span class="diamond">[__NTT(D-)__](/수학/Number%20Theoretic%20Transform.md)</span>
  * <span class="">[__다항식 나눗셈__]</span>
  * <span class="">[__online FFT__]</span>
  * <span class="">[__포함 배제의 원리, 뫼비우스 함수, 뫼비우스 반전(D-)__]</span>
  * <span class="">[__생성 함수(D-)__]</span>
  * <span class="additional">[__Tonelli-Shanks algorithm(A)__](/수학/Tonelli-Shanks.md)</span>
  * <span class="additional">[__Cornacchia's algorithm(A)__](/수학/Cornacchia.md)</span>
  * <span class="">[__메르텐스 함수__]</span>
  * <span class="">[__매트로이드(R-)__]</span>
* ### 기타
  * <span class="silver">[__이분 탐색(S-)__](/기타/Binary%20Search.md)</span>
  * <span class="silver">[__비트마스크(S-)__](/기타/Bitmask.md)</span>
  * <span class="silver">[__값 / 좌표 압축(S-)__](/기타/Coordinate%20Compression.md)</span>
  * <span class="silver">[__순열 사이클 분할(S+)__](/기타/Permutation%20Cycle%20Decomposition.md)</span>
  * <span class="">[__투 포인터(G-)__]</span>
  * <span class="">[__중간에서 만나기(G+)__]</span>
  * <span class="">[__스위핑__]</span>
  * <span class="">[__슬라이딩 윈도우__]</span>
  * <span class="">[__imos__]</span>
  * <span class="platinum">[__XOR 트라이(P-)__](/기타/XOR%20Trie.md)</span>
  * <span class="">[__삼분 탐색__]</span>
  * <span class="">[__병렬 이분 탐색(P+)__]</span>
  * <span class="">[__춤추는 링크, 크누스 X__]</span>
  * <span class="">[__임의 정밀도(epsilon값 계산)(A)__]</span>
  * ~~<span class="">[__담금질 기법__]</span>~~
* ### 게임 이론
  * <span class="">[__스프라그-그런디__]</span> <!-- (비트셋) -->
---
# 유용한 C++ 기능들
* ### 문법
  * <span class="">[range-based for loop]</span>
  * <span class="">[literal]</span>
  * <span class="information">[template argument deduction](/C++%20관련%20정보들/문법/Template%20Argument%20Deduction.md)</span>
  * <span class="">[람다 재귀]</span>
  * <span class="">[코드 여러줄 이어쓰기]</span>
  * <span class="">[리터럴 여러줄 이어쓰기]</span>
* ### 함수
  * <span class="">[수학관련]</span> <!-- atan, atan2 추가하기 -->
  * <span class="">[배열관련]</span>
  * <span class="information">[문자열관련](/C++%20관련%20정보들/함수/string.md)</span>
  * <span class="information">[이분탐색 람다함수](/C++%20관련%20정보들/함수/lower_bound_lambda.md)</span>
  * <span class="">[permutation]</span>
  * <span class="">[custom pq]</span>
  * <span class="">[io manip]</span>
* ### ps용 설정
  * <span class="">[cph]</span>
  * <span class="">[snippet]</span>
  * <span class="">[debug, c_cpp_properties.json 설정]</span>
  <!-- * Pre-defined Compiler Macros
  * 버전 gnu++17로 해야 Template argument deduction 등 문법 사용가능 -->
* ### 기타
  * <span class="information">[자주 쓰는 변수명](/C++%20관련%20정보들/기타/Variable%20Name.md)</span>
  * <span class="information">[비트 트릭](/C++%20관련%20정보들/기타/Bit%20Trick.md)</span>
  * <span class="information">[코딩 아이디어](/C++%20관련%20정보들/기타/Idea.md)</span>
---
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

백준 알고리즘 분류   
https://www.acmicpc.net/problem/tags   