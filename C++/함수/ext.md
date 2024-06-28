# ext/rope
### 헤더
```cpp
#include <ext/rope>
using namespace __gnu_cxx;
```

### 선언
```cpp
crope rope;
crope rope("string literal");
crope rope(st.c_str());
// crope rope(st); // 안 됨
```
rope는 표준 C++라이브러리의 일부가 아니기에 std::string과의 호환성이 없음

### 삽입, 삭제 O(logN)
```cpp
rope.insert(idx, st);
rope.erase(pos, cnt);
```
### count
```cpp
count(rope.begin(), rope.end(), ch);
```
count는 std::string에 쓸 때보다 오래 걸림

### operator+, operator<<
```cpp
crope a("aa"), b("bb"), c;
c = a + b; // "aabb"

crope rp;
rp += rope2;
rp += "string literal";


cout << rp;
```
operator>>은 오버로딩 안 돼 있음

# ext/pb_ds
### 헤더
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
```

### 삽입, 삭제 O(logN)
```cpp
ordered_set os;
os.insert(num);
os.erase(num);
```
set처럼 중복 안 됨

### find
```cpp
cout << *os.find_by_order(order) << '\n';
cout << os.order_of_key(key) << '\n';
```
find_by_order에 보내는 매개변수와 order_of_key의 리턴값은 모두 0-based   
order_of_key의 경우 key가 ordered_set에 들어있는지는 확인하지 않음   
ordered_set에 없는 경우에도 ordered_set에 있을 경우의 order을 리턴해줌   

# multiset with ext/pb_ds
### 헤더
```cpp
using ordered_multiset = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
```
less\<int> 대신 less_equal\<int> 사용

### 삽입, 삭제 O(logN)
```cpp
ordered_multiset oms;
oms.insert(num);
oms.erase(os.find_by_order(order));
```

multiset에선 erase(num) 쓰면 이상하게 됨.   
해결 방법은 아직 모름   
코포 설명글 링크 https://codeforces.com/blog/entry/11080?locale=en   

테스트용 백준문제 : [데이터 구조](https://www.acmicpc.net/problem/12899)