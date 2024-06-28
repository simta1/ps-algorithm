[카테고리](/README.md)
### Coordinate Compression
```cpp
template <typename T>
void coordinate_compression(vector<T> &orig) {
    vector<T> v(orig);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto &e : orig) e = lower_bound(v.begin(), v.end(), e) - v.begin();
}
```
### 시간복잡도 
$O(N~logN)$   