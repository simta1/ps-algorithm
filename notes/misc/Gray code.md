[카테고리](/README.md)
## Gray code
```cpp
void grayCode(int n) {
    for (int i = 0; i < (1 << n); ++i) {
        int gray = i ^ (i >> 1);
        cout << bitset<32>(gray).to_string().substr(32 - n) << "\n";
    }
}
```
### 시간복잡도
$O(2^N)$   

### 문제
[Eric’s Work](https://www.acmicpc.net/problem/20250)   