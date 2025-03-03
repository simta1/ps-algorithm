[카테고리](/README.md)
## Bitset LCS
### [비트셋 덧셈뺄셈](/utils/비트셋%20덧셈뺄셈.md)
<details>
<summary>비트셋 덧셈뺄셈 코드</summary>

```cpp
// https://gist.github.com/cgiosy/a441de545c9e96b1d7b02cc7a00561f9 ----------------------------- {
#define private public // 반드시 #include <bits/stdc++.h>보다 선행되어야 함
#include <bitset> // 반드시 #include <bits/stdc++.h>보다 선행되어야 함
#undef private // 반드시 #include <bits/stdc++.h>보다 선행되어야 함

#include <bits/stdc++.h>
using namespace std;

#include <x86intrin.h>

template<size_t _Nw> void _M_do_sub(_Base_bitset<_Nw> &A, const _Base_bitset<_Nw> &B) {
	for (int i = 0, c = 0; i < _Nw; i++) c = _subborrow_u64(c, A._M_w[i], B._M_w[i], (unsigned long long*)&A._M_w[i]);
}
template<> void _M_do_sub(_Base_bitset<1> &A, const _Base_bitset<1> &B) { A._M_w -= B._M_w; }
template<size_t _Nb> bitset<_Nb>& operator-=(bitset<_Nb> &A, const bitset<_Nb> &B) { _M_do_sub(A, B); return A; }
template<size_t _Nb> inline bitset<_Nb> operator-(const bitset<_Nb> &A, const bitset<_Nb> &B) { bitset<_Nb> C(A); return C-=B; }

template<size_t _Nw> void _M_do_add(_Base_bitset<_Nw> &A, const _Base_bitset<_Nw> &B) {
	for (int i = 0, c = 0; i < _Nw; i++) c = _addcarry_u64(c, A._M_w[i], B._M_w[i], (unsigned long long*)&A._M_w[i]);
}
template<> void _M_do_add(_Base_bitset<1> &A, const _Base_bitset<1> &B) { A._M_w += B._M_w; }
template<size_t _Nb> bitset<_Nb>& operator+=(bitset<_Nb> &A, const bitset<_Nb> &B) { _M_do_add(A, B); return A; }
template<size_t _Nb> inline bitset<_Nb> operator+(const bitset<_Nb> &A, const bitset<_Nb> &B) { bitset<_Nb> C(A); return C+=B; }
// --------------------------------------------------------------------------------------------- }
```
</details>

### Bitset LCS
```cpp
template <size_t sz> // sz는 min(a의 가능한 최대 크기, b의 가능한 최대 크기) 이상인 값으로 사용
int LCS(const string &_a, const string &_b) {
    const string &a = _a.size() > _b.size() ? _a : _b;
    const string &b = _a.size() > _b.size() ? _b : _a;

    bitset<sz> D, x, S[26]; // 대문자만 사용하는 경우임, 문자 종류 여러가지면 charToInt()만들어서 쓰기
    for (int i = 0; i < b.size(); i++) S[b[i] - 'A'][i] = 1;
    for (int i = 0; i < a.size(); i++) {
        x = S[a[i] - 'A'] | D;
        D <<= 1;
        D[0] = 1;
        D = x & (x ^ (x - D));
    }
    return D.count();
}


// ex) 
int main() {
    string a, b;
    cin >> a >> b;
    cout << LCS<50005>(a, b);
}
```
### 시간복잡도
$O(\dfrac{NM}{w})$   
w는 word size   

### 공간복잡도
$O(\dfrac{min(n, m) |\sum|}{w})$   
$|\sum|$는 문자열에 등장하는 문자 종류의 개수   
ex) 대문자로만 이루어진 문자열은 26   

### 문제
[Round words](https://www.acmicpc.net/problem/11852)   
[LCS 6](https://www.acmicpc.net/problem/18439)   

### 참고링크
https://infossm.github.io/blog/2019/09/12/lcs-with-bitset/   
https://koosaga.com/245   
https://gist.github.com/cgiosy/a441de545c9e96b1d7b02cc7a00561f9 - 비트셋 덧셈뺄셈   
https://m.blog.naver.com/jinhan814/222545491428   