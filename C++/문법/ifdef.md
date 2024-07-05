### #ifdef LOCAL

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