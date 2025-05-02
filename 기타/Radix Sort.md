[카테고리](/README.md)
## Radix Sort
```cpp
template <bool onlyPositive, typename T>
void radixSort(vector<T> &v) {
    static_assert(is_integral<T>::value, "T가 정수형 자료형이어야 함");

    const unsigned int SZ = 8;
    const unsigned int mask = (1 << SZ) - 1;
    static queue<T> qs[1 << SZ];

    for (int k = 0; k < sizeof(T); k++) {
        for (const auto &e : v) qs[e >> k * SZ & mask].push(e);
        v.clear();

        for (auto& q : qs) {
            while (q.size()) {
                v.push_back(q.front());
                q.pop();
            }
        }
    }

    if constexpr (!onlyPositive) {
        for (int i = 0; i < v.size(); i++) if (v[i] < 0) {
            rotate(v.begin(), v.begin() + i, v.end());
            break;
        }
    }
}
```
### 시간복잡도 
int $O(4N)$   
long long $O(8N)$   

### 사용설명
정수형에서만 사용   
```cpp
vector<int> v(n);
for (auto &e : v) cin >> e;
radixSort<true>(v); // 양수만 주어질 때
radixSort<false>(v); // 음수도 주어질 때
```

### 문제
[수 정렬하기 2](https://www.acmicpc.net/problem/2751)