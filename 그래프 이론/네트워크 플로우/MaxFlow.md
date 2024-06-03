## __Ford-Fulkerson__
증가 경로 더 이상 찾을 수 없을 때까음 증가 경로 찾아서 유량을 흘려주면 최대유량을 구할 수 있다.   
증가경로 찾는 방법까진 명시하지 않음 -> Algorithm이 아니라 Method로 부르기도 하는 듯   
$O(Ef)$

## __Edmonds-Karp__   $O(V E^2)$
증가경로를 찾기 위해 bfs 사용하는 Ford-Fulkerson   

정확한 시간복잡도는,   
dfs : $O(Ef)$   
bfs : $O(min(Ef, VE^2))$

## __Dinic(Dinitz)__ $O(V^2 E)$   

정확한 시간복잡도는,   
$O(min(Ef, V^2 E))$   

모든 간선의 용량이 1이라면 더욱 효율적   
$O(min(V^\frac{2}{3}, E^\frac{1}{2})E)$   

## __Push-Relabel__ $O(V^3)$
휴리스틱 잘 적용할수록 더 빨라짐   
<!-- [메시라이브](https://www.acmicpc.net/problem/21731)    -->



### 참고문헌
https://gseok.gitbooks.io/algorithm/content/b124-d2b8-c6cc-d06c-d50c-b85c-c6b0/d3ec-b4dc-d480-cee4-c2a828-ford-fulkerson-c560-b4dc-baac-b4dc-ce74-d50428-edmonds-karp.html   
https://en.wikipedia.org/wiki/Dinic%27s_algorithm   
https://koosaga.com/18