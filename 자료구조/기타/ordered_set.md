[카테고리](/README.md)
<!-- TODO c++/함수/ext.md에 있는 거 옮겨오기, multiset 설명 분리하기? -->
## ordered_set
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
```
### 시간복잡도
$O(logN)$   

### 구현 주의사항
`ordered_multiset` 사용할 경우 `less<int>` 대신 `less_equal<int>` 사용   
이 경우 erase()는 조금 귀찮아짐.   
```cpp
ordered_multiset os;

// order 기준 삭제
auto it = os.find_by_order(order);
os.erase(it);

// value 삭제
auto it = os.find_by_order(os.order_of_key(val));
os.erase(it);
```

find()도 똑같이 `find_by_order()`과 `order_of_key()`로 우회해서 사용   

### 사용설명
find_by_order()의 경우 0-based임에 주의. [세그 이분 탐색](/자료구조/세그먼트%20트리/세그%20이분%20탐색.md)에서 findKth()가 1-based인 것과 착각하지 않도록 주의

직접 세그 이분 탐색 구현해서 쓰는 게 좀 더 빠른 것 같다.
코드 짜기 귀찮거나 스니펫 복붙 못하는 상황에서 쓸 듯

### 문제
[까다로운 아이들과 선물 상자](https://www.acmicpc.net/problem/23760)

### 참고링크
https://daisylum.tistory.com/18   