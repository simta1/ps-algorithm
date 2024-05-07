[카테고리](/README.md)
### Coordinate Compression $O(N~logN)$
```cpp
void coordinate_compression(vector<int> &orig) {
    vector<int> v(orig);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto &e : orig) e = lower_bound(v.begin(), v.end(), e) - v.begin();
}
```
### Coordinate Compression $O(N)$
```cpp
```
### 시간복잡도 
$O(N)$   