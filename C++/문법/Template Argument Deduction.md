[카테고리](/README.md)
### Template Argument Deduction (C++17~)
```cpp
pair p(3, 4); // pair<int, int> p(3, 4);
vector v(n, vector(m, vector<int>(k))); // vector<vector<vector<int> > > v(n, vector<vector<int> >(m, vector<int>(k)));
```
다차원 벡터 선언할 때 편하다.

### 간단한 다차원 벡터 선언(jinhan814)
https://blog.naver.com/jinhan814/223157572809 에서 가져온 코드   
jinhan814님이 AtCoder noshi91님의 코드에 자료형 추론을 적용한 코드라고 한다.   
```cpp
// reference : https://atcoder.jp/contests/abc309/submissions/43356752

template<typename T>
auto Vector(const int n, const T& val) { return vector(n, val); }

template<typename... Ts>
auto Vector(const int n, Ts... args) { return vector(n, Vector(args...)); }

```
`Vector(n, m, k, val)`처럼 선언해서 사용   