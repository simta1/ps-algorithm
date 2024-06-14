[카테고리](/README.md)
### p-adic valuation
```cpp
template <typename T>
T pAdicValuation(T n, T p) {
    T res = 0;
    while (n) res += (n /= p);
    return res;
}
```
### 시간복잡도 
$O(\log_{p}{n})$   