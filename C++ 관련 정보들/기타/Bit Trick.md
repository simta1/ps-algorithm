[카테고리](/README.md)
### if (!~x)
```cpp
if (!~visited[cur]) //방문 안 한 곳인지
if (!~dp[i]) //초기화됐던 처음상태인지
```
-1일 때만 true


### if (x & 1)
홀수면 true
x % 2보다 훨씬 빠르다. %는 산술 연산자 중 가장 느리다.

### if (~x & 1)
짝수면 true

### if (x && !(x & x-1))
2의 거듭제곱만 true   
ex) 1, 2, 4, 8, 16, ...   
$\because$   
x & (x - 1) ->  2의 거듭제곱과 0만 false

### x & -x
최하위 1비트(오른쪽에서 첫번째 1)   
$\because$   
-k = (~k + 1) 이기 때문

### x &= x - 1
최하위 1비트 제거
```cpp
// ex) popcount
for (cnt = 0; x; ++cnt) x &= x - 1;
```
$\because$   
01010100 // x   
01010011 // x - 1   
01010000 // x & (x - 1)   

### !!x
bool(x) 숏코딩할 때

### x ^= 1
x가 bool일 때만 사용   
x = !x랑 같은 의미   
x 변수이름 길어지면 유용
```cpp
// ex) Splay Tree
void reverse(int l, int r) {
    gather(l, r)->flipLazy ^= 1;
}
```



---
# 그냥 참고용

### 대문자 소문자 변환
```cpp
c |= ' '; // 대문자 -> 소문자 
c &= '_'; // 소문자 -> 대문자
```

### a ^= b ^= a ^= b;
swap(a, b)와 동일   
정수에만 쓸 수 있는 swap하위호환.   
python에서 가끔 쓴 적 있긴 함