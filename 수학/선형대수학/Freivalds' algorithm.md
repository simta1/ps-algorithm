[카테고리](/README.md)
## Freivalds' algorithm
```cpp
template <typename T>
bool freivalds(const vector<vector<T> > &a, const vector<vector<T> > &b, const vector<vector<T> > &c) { // n*n행렬 A, B, C에 대해 AB==C인지 O(LOOP * N^2)에 확인 // (0.5^LOOP)의 확률로 AB!=C인데 AB==C라고 틀린 판별을 내릴 가능성 있음
    int n = a.size();
    vector<unsigned long long> Bx(n), x(n);

    static Random<int> rand(0, 1);
    constexpr int LOOP = 30;

    for (int it = LOOP; it--;) {
        for (auto &e : x) e = rand() & 1;
        
        for (int i = 0; i < n; i++) {
            Bx[i] = 0;
            for (int j = 0; j < n; j++) Bx[i] += b[i][j] * x[j];
        }
        
        for (int i = 0; i < n; i++) {
            unsigned long long ABx_i = 0, Cx_i = 0;
            for (int j = 0; j < n; j++) {
                ABx_i += a[i][j] * Bx[j];
                Cx_i += c[i][j] * x[j];
            }
            if (ABx_i != Cx_i) return false;
        }
    }
    return true;
}
```
### 시간복잡도
$O(K N^2)$   
$K$는 알고리즘 반복횟수(코드에서 변수 LOOP에 저장한 값)

### 구현 주의사항
혹시 계산 중에 오버플로우 나도 괜찮도록 Bx, x, ABx, Cx에는 unsigned자료형 사용   
signed에서의 오버플로우는 UB지만 unsigned에서의 오버플로우는 $\mod{2^k}$를 취한 것과 같으므로 값을 비교하기엔 문제 없음   
물론 mod로 인해 해시 충돌처럼 다른 값을 같은 값이라 판단하는 경우가 생길 수도 있겠지만 애초에 알고리즘을 여러 번 반복하기에 딱히 영향은 없을 듯   

### 문제
[Comparing answers](https://www.acmicpc.net/problem/3847)   
[이것도 해결해 보시지](https://www.acmicpc.net/problem/13165)   
<!-- [Inner Product](https://www.acmicpc.net/problem/17313)    -->

### 참고링크
https://blog.naver.com/sluggeryck/220938909066   