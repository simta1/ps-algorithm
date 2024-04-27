[카테고리](/README.md)
### Bitmask
```cpp
// init
a = 0; // empty
a = (1<<n) - 1; // all

// update
a |= (1<<x);	// add
a &= ~(1<<x);	// remove
a ^= (1<<x);	// toggle

// check
if (a & (1<<x))	// have
if (~a & (1<<x))// don't have

// last element (bit trick)
a &= (a - 1);	// remove last
x = log2(a & -a); // get last
```
### 주의사항
비트연산이 덧셈뺄셈보다 연산자우선순위 낮음

### 백준문제
[집합](https://www.acmicpc.net/problem/11723)

### 원리
0, 1, 2, ... , (n - 1)번째 값이 각각 2^0, 2^1, 2^2, ..., 2^(n-1)자리에 저장된다.