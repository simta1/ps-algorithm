[카테고리](/README.md)
## ext/rope
### 헤더
```cpp
#include <ext/rope>
using namespace __gnu_cxx;
```
### 선언
```cpp
rope<char> rp;
rope<char> rp("string literal");
rope<char> rp(st.c_str());
// rope<char> rp(st); // 안 됨
```
rope는 표준 C++라이브러리의 일부가 아니기에 std::string과의 호환성이 없음
### 삽입, 삭제 O(logN)
```cpp
rp.insert(idx, st);
rp.insert(idx, rope2);
rp.erase(pos, cnt);
```
문자열 삽입 뿐 아니라 로프 삽입도 가능
### 분리 O(logN)
```cpp
rp.substr(idx, cnt);
```
### 결합 (operator+) O(logN)
```cpp
rope<char> a("aa"), b("bb"), c;
c = a + b; // "aabb"

rope<char> rp;
rp += rope2;
rp += "string literal";
```
### operator\<\<
```cpp
cout << rp;
```
`rope<char>`의 경우 operator\<\< 가 가능함
operator\>\>는 안 됨

### 시간복잡도
$O(logN)$   

### 문제
[순열복원](https://www.acmicpc.net/problem/1777)

### 참고링크
https://m.blog.naver.com/melon940925/222120515591   