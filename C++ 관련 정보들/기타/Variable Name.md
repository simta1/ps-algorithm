[카테고리](/README.md)
### 변수명 통일
```cpp
adj // 그래프 인접리스트
cur, next, cost // 그래프에서 현재 노드, 다음 노드, 간선 가중치
dist // 다익스트라, 벨만 포드, 플로이드 워셜 등등에서 거리 계산결과 저장하는 배열
inDegree // 위상정렬 등에서 노드로 들어오는 간선 개수
node, s, e, l, r // 세그트리, s와 e는 node의 범위, l과 r은 쿼리 범위
```

### 함수명 통일
```cpp
addEdge() // 그래프 간선 추가
propagate() // lazy seg, splay tree 등에서 lazy전파하는 함수. 다른 이름 사용한 코드 좀 있어서 수정해야 됨.
```

### offset
배열에 음수 인덱스 사용하고 싶을 때 인덱스 얼마나 평행이동할지 저장
```cpp
vector<int> v(n);
for (auto &e : v) cin >> e;

int offset = *min_element(v.begin(), v.end());
vector<int> cnt(*max_element(v.begin(), v.end()) - offset);
for (auto &e : v) ++cnt[e - offset];
```

### pos[]
배열의 원소가 어떤 인덱스에 위치하는지 역으로 저장. 인덱스의 역함수 느낌.   
```cpp
for (int i = 0; i < n; i++) pos[v[i]] = i;
```

### rdj
그래프에서 역방향 간선 저장. rdj 뜻은 그냥 reverse adj 줄인 거
```cpp
vector<vector<pair<int, T> > > adj;
vector<vector<pair<int, T> > > rdj; // reverse adj
```

### trueValue
visited배열 등에서 true인지 나타내는 값.   
visited[i] != trueValue이면 false로 생각하는 방식.   
배열 여러번 사용해야 될 때 굳이 O(N)으로 배열값 전부 0으로 초기화하지 않아도 trueValue값만 O(1)로 바꾸면 되서 시간복잡도 줄이는 용. (이분 매칭 코드 참고)
