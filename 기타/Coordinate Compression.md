[카테고리](/README.md)
### Coordinate Compression $O(N~logN)$
```cpp
template <typename T>
void coordinate_compression(vector<T> &orig) {
    vector<T> v(orig);
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

위 코드는 $O(N~logN)$짜리지만 그냥 코드가 직관적이고 예뻐서 사용하고 있다.   
$O(N)$ 구현도 간단하긴 하지만 솔직히 좌표압축 때문에 시간초과받을 일은 없을 것 같아 그냥 사용 중이다.