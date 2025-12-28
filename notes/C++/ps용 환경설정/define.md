[카테고리](/README.md)
## define
<!-- TODO
일단 다른 사람들 debug코드쓰는 거 여러개 복사해두고 나중에 조합해서 나한테 맞는 코드 만들면 될듯
-->
```cpp
#define prt(x) #x << ": " << x
```

```cpp
#define SPC << " " <<
#define DEBUG(x) cerr << #x << " = "; cerr << x << endl;
#define DEBUG_ITER(x) cerr << #x << " = "; for (auto _ : x) cerr << _ << ' '; cerr << endl;
```