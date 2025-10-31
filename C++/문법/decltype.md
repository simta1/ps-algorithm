[카테고리](/README.md)
## decltype
```cpp
auto cmp = [&](T a, T b) {
	//
};

set<T, decltype(cmp)> s(cmp); // cmp(s.begin(), s.end()) == true가 되도록 정렬됨
priority_queue<T, vector<T>, decltype(cmp)> pq(cmp); // b쪽이 pq.top()임
```
