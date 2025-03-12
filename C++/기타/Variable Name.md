[카테고리](/README.md)
# 자주 쓰는 변수명/함수명
## 그래프
### adj[][], rdj[][]
`adj[][]` : 그래프에서 인접리스트(adjacent)   
`rdj[][]` : 유향그래프에서 역방향 간선 저장하는 인접리스트(reverse adj)   
```cpp
auto addEdge = [&adj, &rdj](int u, int v) { // 무향그래프
    adj[u].push_back(v);
    adj[v].push_back(u);
};

auto addEdge = [&adj, &rdj](int u, int v) { // 유향그래프
    adj[u].push_back(v);
    rdj[v].push_back(u);
};
```

### sz[], dep[], par[]
`sz[], dep[], par[]` : HLD 등에서 트리의 서브트리 크기, 현재노드의 깊이, 부모노드 저장하는 배열   

### chd[][], makeTree()
`chd[][]` : 트리에서 인접리스트(child). 입력을 양방향 간선으로 받아 adj에 저장한 결과로부터 부모->자식 방향 간선만 남긴 거   
`makeTree()` : 트리에서 adj로 `chd[][], sz[], dep[], par[]` 등등 계산하는 함수
```cpp
function<void(int, int)> makeTree = [&adj, &chd, &makeTree](int cur, int parent) {
    for (auto next : adj[cur]) if (next != parent) {
        chd[cur].push_back(next);
        makeTree(next, cur);
    }
};
```

### cur, next, cost, dist[]
`cur, next, cost` : 그래프에서 현재 노드, 간선으로 이어진 다음 노드, 간선 가중치   
`dist[]` : 다익스트라, 벨만 포드, 플로이드 워셜 등등에서 거리 계산결과 저장하는 배열   
```cpp
for (auto [next, cost] : adj[cur]) if (dist[next] > dist[cur] + cost) {
    dist[next] = dist[cur] + cost;
    pq.push({dist[next], next});
}
```

### inDegree[]
`inDegree[]` : 위상정렬 등에서 노드로 들어오는 간선 개수 저장하는 배열   
```cpp
auto addEdge = [&](int u, int v) {
    adj[u].push_back(v);
    ++inDegree[v];
};
```

### dfsn[], dfsi
`dfsn[]` : ETT, SCC, BCC 등에서 dfs 트리 만들면서 방문한 순서 저장   
`dfsi` : dfsn 채울 때 쓰는 변수   
```cpp
int dfsi = 0;
function<void(int)> dfs = [&](int cur) {
    dfsn[cur] = ++dfsi;
    for (auto next : adj[cur]) if (!dfsn[next]) dfs(next);
};
```

### inRange(), si, sj, ei, ej, ci, cj, di, dj, ni, nj, dpos[], dir
2차원 격자에서 탐색할 때 이동방향, 좌표정보 저장   

`inRange()` : 인덱스가 2차원 격자 범위 내에 존재하는지 확인   
`si, sj` : 시작 위치(start)   
`ei, ej` : 목적지 위치(end)   
`ci, cj` : 현재 위치(cur)   
`di, dj` : 이동방향에 따른 좌표변화량(differential)   
`ni, nj` : 현재 위치에서 {di, dj} 방향으로 이동한 뒤의 좌표   

`dpos[]` : 이동방향에 따른 {di, dj} 쌍 모아놓은 배열   
`dir` : 이동방향 저장, dpos[] 배열에 대한 인덱스로 저장   
```cpp
const vector<pair<int, int> > dpos = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // 상좌하우
const string dirToChar = "NWSE";

auto inRange = [&n, &m](int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
};

// ex) bfs
while (!q.empty()) {
    auto [ci, cj] = q.front();
    q.pop();

    for (auto [di, dj] : dpos) {
        int ni = ci + di;
        int nj = cj + dj;
        if (inRange(ni, nj) && !visited[ni][nj]) {
            q.emplace(ni, nj);
            visited[ni][nj] = true;
        }
    }
}

// ex) 달팽이 방향 탐색
int ci = si, cj = sj, dir = 0;
while (ci != ei || cj != ej) {
    auto [di, dj] = dpos[dir];
    int ni = ci + di;
    int nj = cj + dj;
    if (inRange(ni, nj) && !visited[ni][nj]) ci = ni, cj = nj;
    else dir = (dir + 1) % dpos.size();
}
```

### fac[], facInv[]
`fac[], facInv[]` : 팩토리얼, 각 팩토리얼에 대응되는 모듈러 역원 저장   
```cpp
vector<ll> fac(n + 1, 1);
for (int i = 2; i < fac.size(); i++) fac[i] = fac[i - 1] * i % mod;

vector<ll> facInv(fac.size(), modInverse(fac.back(), mod));
for (int i = facInv.size() - 1; i > 0; i--) facInv[i - 1] = facInv[i] * i % mod;
```

### sq, sqr
`sq` : 제곱 저장   
`sqr` : 제곱근 저장   
```cpp
int sq = n * n;
int sqr = sqrt(n); // 실수오차 때문에 int에 대해서 sqrt함수를 사용하는 건 위험하지만 여기선 그냥 변수명이 사용되는 예시를 보이는 게 목표기 때문에 사용함

// ex) x^2+bx+c=0의 정수해 
int tmp = b * b - 4 * c;
int sqr = sqrt(tmp);
if (sqr * sqr != tmp || sqr + b & 1) return false;
int x1 = -b + sqr >> 1;
int x2 = -b - sqr >> 1;
```

### lpf[], lpe[]
`lpf[]` : linear sieve 등에서 최소소인수 저장(least prime factor)   
`lpe[]` : $\phi(n)$ 등의 곱셈적 함수를 선형 체로 $O(N)$에 구할 때 사용, 최소소인수의 지수 저장(exponent)   

## 자료구조
### node, s, e, l, r
`node, s, e, l, r` : 세그트리 등에서 s와 e는 현재 node가 가리키는 범위, l과 r은 쿼리 범위   

### propagate()
`propagate()` : lazy seg, splay tree 등에서 lazy 전파하는 함수   

## 수학
### lowHalf, highHalf
`lowHalf` : 자연수 반으로 쪼갰을 때 작은 부분   
`highHalf` : 자연수 반으로 쪼갰을 때 큰 부분   
```cpp
int lowHalf = n >> 1;
int highHalf = n + 1 >> 1;
```

### carry, borrow
`carry, borrow` : bigInt 등 구현할 때 덧셈/뺄셈에서 자리올림/자리내림 저장

### eps
`eps` : 기하 문제 등에서 실수오차 고려해서 대소관계 비교할 때 사용(epsilon)   
https://www.acmicpc.net/blog/view/37 참고   
```cpp
const ld eps = 1e-7;

bool isEqual(ld a, ld b) { // 실수 a, b에 대해서 a == b인지 검사
    return abs(a - b) <= eps;
}
```

## 기타
### offset
`offset` : 배열에 음수 인덱스 사용하고 싶을 때 인덱스 얼마나 평행이동할지 저장   
```cpp
vector<int> v(n);
for (auto &e : v) cin >> e;

int offset = *min_element(v.begin(), v.end());
vector<int> cnt(*max_element(v.begin(), v.end()) - offset + 1);
for (auto &e : v) ++cnt[e - offset];
```

### mask
`mask` : 비트마스킹할 때 비트 저장용 변수   

### pos[]
`pos[]` : 배열의 원소가 어떤 인덱스에 위치하는지 역으로 저장. 인덱스의 역함수 느낌   
```cpp
for (int i = 0; i < n; i++) pos[v[i]] = i;
```

### trueValue
`trueValue` : visited배열 등에서 true인지 나타내는 값   
`visited[i] != trueValue`이면 false로 생각하는 방식   
배열 여러번 사용해야 될 때 굳이 $O(N)$으로 배열값 전부 0으로 초기화하지 않아도 trueValue값만 $O(1)$로 바꾸면 되서 시간복잡도 줄이는 용. ([이분 매칭](/그래프%20이론/네트워크%20플로우/이분매칭.md) 코드 참고)