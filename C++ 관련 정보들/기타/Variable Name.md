[카테고리](/README.md)
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
