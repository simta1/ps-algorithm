[카테고리](/README.md)
## ext/pbds
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
```
multiset은 `less<T>` 대신 `less_equal<T>` 사용
### ordered_set
```cpp
// 삽입, 삭제 O(logN)
ordered_set os;
os.insert(key);
os.erase(os.find_by_order(order)); // order번째 원소 삭제
os.erase(key); // key 삭제

// 검색 O(logN)
cout << *os.find_by_order(order) << '\n';
cout << os.order_of_key(key) << '\n';
if (os.find(key) != os.end()) ;
```
find_by_order에 보내는 매개변수와 order_of_key의 리턴값은 모두 0-based   
order_of_key의 경우 key보다 작은 수들의 개수를 세는 함수이므로 key가 ordered_set에 들어있는 값이 아니어도 됨

### ordered_multiset
```cpp
// 삽입, 삭제 O(logN)
ordered_multiset os;
os.insert(key);
os.erase(os.find_by_order(order)); // order번째 원소 삭제
os.erase(os.find_by_order(os.order_of_key(key))); // key 삭제 (위험)

// key가 multiset에 들어있지 않다면 다른 값이 삭제되므로 확인하는 게 안전함
int order = os.order_of_key(key);
if (order < os.size()) {
    auto it = os.find_by_order(os.order_of_key(key))
    if (*it == key) os.erase();
}

// 검색 O(logN)
int order = os.order_of_key(key);
if (order < os.size() && *os.find_by_order(order) == val) ;
```
less_equal<T>를 사용하는 ordered_multiset의 경우 erase()와 find()가 제대로 작동하지 않기에 `find_by_order()`과 `order_of_key()`로 우회해서 사용   

### 시간복잡도
$O(logN)$   

### 사용설명
find_by_order()의 경우 0-based임에 주의.   
[세그 이분 탐색](/자료구조/세그먼트%20트리/세그%20이분%20탐색.md)에서 findKth()가 1-based인 것과 다르니 착각하면 안 된다.   

직접 세그 이분 탐색 구현해서 쓰는 게 좀 더 빠른 것 같다.   
코드 짜기 귀찮거나 스니펫 복붙 못하는 상황에서 쓸 듯   

### 문제
[데이터 구조](https://www.acmicpc.net/problem/12899)   
[까다로운 아이들과 선물 상자](https://www.acmicpc.net/problem/23760)   

### 참고링크
https://daisylum.tistory.com/18   
https://codeforces.com/blog/entry/11080?locale=en   