[카테고리](/README.md)
## ifdef
### 사용예시
ps에선 보통 디버그할 때 씀   
gcc -DLOCAL처럼 컴파일 시 매크로 변수를 추가하면 `#ifdef LOCAL`의 코드가 실행되도록 할 수 있음   
vsc의 경우 .vscode의 c_cpp_properties.json에서 configurations.defines[]에 "LOCAL"을 추가하면 됨([ps용 환경설정](/C++/ps용%20환경설정/Debug.md) 참고)
```cpp
#ifdef LOCAL
	#define ASSERT(x) assert(x)
#else
	#define ASSERT(x) 42
#endif
```

```cpp
#ifdef LOCAL
	#include "Debug.h"
#else
	#define debug_endl() 42
	#define debug(...) 42
	#define debug2(...) 42
```
참고로 42는 아무 의미 없는 값임(The Hitchhiker's Guide to the Galaxy에서 유래한 값), 보통 ps에서 아무 의미 없는 값으로 42를 사용하는 관례가 있는 듯   