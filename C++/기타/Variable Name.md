[카테고리](/README.md)
### 변수명 통일
```cpp
adj[][] // adjacent, 그래프에서 인접리스트
rdj[][] // reverse adj, 방향그래프에서 역방향 간선 저장
chd[][] // child, 트리에서 인접리스트. 입력을 양방향 간선으로 받아 adj에 저장한 뒤    부모->자식 방향 간선만 남겨 저장
cur, next, cost // 그래프에서 현재 노드, 다음 노드, 간선 가중치
dist[] // 다익스트라, 벨만 포드, 플로이드 워셜 등등에서 거리 계산결과 저장하는 배열
inDegree[] // 위상정렬 등에서 노드로 들어오는 간선 개수
node, s, e, l, r // 세그트리, s와 e는 node의 범위, l과 r은 쿼리 범위
sz[], dep[], par[] // 트리에서 서브트리 크기, 현재노드의 깊이, 부모노드 저장하는 배열
dfsn // ETT 등에서 dfs 스패닝 트리 만들 때 방문순서 저장
```

### 함수명 통일
```cpp
addEdge() // 그래프 간선 추가
propagate() // lazy seg, splay tree 등에서 lazy전파하는 함수. 다른 이름 사용한 코드 좀 있어서 수정해야 됨.
makeTree() // 트리에서 adj로 chd만드는 함수
```

### offset
배열에 음수 인덱스 사용하고 싶을 때 인덱스 얼마나 평행이동할지 저장
```cpp
vector<int> v(n);
for (auto &e : v) cin >> e;

int offset = *min_element(v.begin(), v.end());
vector<int> cnt(*max_element(v.begin(), v.end()) - offset + 1);
for (auto &e : v) ++cnt[e - offset];
```

### mask
비트마스킹할 때 비트 저장용 변수   

### pos[]
배열의 원소가 어떤 인덱스에 위치하는지 역으로 저장. 인덱스의 역함수 느낌.   
```cpp
for (int i = 0; i < n; i++) pos[v[i]] = i;
```

### trueValue
visited배열 등에서 true인지 나타내는 값.   
visited[i] != trueValue이면 false로 생각하는 방식.   
배열 여러번 사용해야 될 때 굳이 O(N)으로 배열값 전부 0으로 초기화하지 않아도 trueValue값만 O(1)로 바꾸면 되서 시간복잡도 줄이는 용. ([이분 매칭](/그래프%20이론/네트워크%20플로우/이분매칭.md) 코드 참고)

### dpos, dir, sx, sy, cx, cy, ex, ey, dx, dy
2차원 배열 위에서 움직일 때 이동방향, 좌표정보 저장   

sx, sy는 시작 위치(start)   
cx, cy는 현재 위치(cur)   
ex, ey는 목적지 위치(end)   
dx, dy는 이동방향에 따른 좌표변화량(differential)   
   
dir는 현재 이동방향을 0~3으로 저장   
dpos는 dx, dy들 모아놓은 배열   
```cpp
const vector<pair<int, int> > dpos = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // 상좌하우
const string dirToChar = "NWSE";

// ex)
auto [dx, dy] = dpos[dir];
cx += dx;
cy += dy;
```

### fac, facInv
```cpp
vector<ll> fac(n + 1, 1);
for (int i = 2; i < fac.size(); i++) fac[i] = fac[i - 1] * i % mod;
vector<ll> facInv(fac.size(), modInverse(fac.back(), mod));
for (int i = facInv.size() - 1; i > 0; i--) facInv[i - 1] = facInv[i] * i % mod;
```
팩토리얼, 각 팩토리얼에 대응되는 모듈러 역원 저장

### sq, sqr
제곱, 제곱근 저장

### lpf, lpe
linear sieve구현할 때 사용   
각각 최소소인수, 최소소인수의 지수 저장   