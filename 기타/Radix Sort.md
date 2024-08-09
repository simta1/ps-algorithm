[카테고리](/README.md)
### Radix Sort
```cpp
template <typename T>
void radixSort(vector<T> &v) {
    static_assert(is_integral<T>::value, "T must be an integral type.");

	const unsigned int SZ = 8;
    const unsigned int mask = ~-(1 << SZ);
	static queue<T> qs[1 << SZ];

    for (int k = 0; k < sizeof(T); k++) {
	    for (const auto& e : v) qs[e >> k * SZ & mask].push(e);
        v.clear();

        for (auto& q : qs) {
            while (q.size()) {
                v.push_back(q.front());
                q.pop();
            }
        }
    }
}
```
### 시간복잡도 
int $O(4N)$   
long long $O(8N)$   

### 사용관련
정수형, 양수에서만 사용   

### 백준문제
[수 정렬하기 2](https://www.acmicpc.net/problem/2751)