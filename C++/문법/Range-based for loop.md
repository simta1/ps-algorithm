[카테고리](/README.md)
### Range-based for loop(범위 기반 for문, C++11~)
```cpp
// for (auto &element : container) {}

// ex) 
vector<int> v(n);
for (auto &e : v) cin >> e;
for (auto e : v) cout << e << " ";
```
### Structured binding declaration(구조적 바인딩, C++17~)
```cpp
pair<int, int> p;
auto& [x, y] = p;

tuple<int, int, int> t;
auto& [x, y, z] = t;

pair<pair<int, int>, int> p;
auto [a, b] = p; // a : pair<int, int>, b : int
// auto [[a, b], c] = p; // 괄호 겹쳐쓰는 건 불가능
```

### for문 + 구조적 바인딩
```cpp
vector<pair<int, int> > points(n);
for (auto &[x, y] : points) cin >> x >> y;

const vector<pair<int, int> > dpos = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
for (auto [dx, dy] : dpos) {
    // ...
}

// map, set도 begin(), end()가 있으므로 Range-based for loop가능
map<int, int> mp;
for (auto& [key, value] : mp) {
    // ...
}
```