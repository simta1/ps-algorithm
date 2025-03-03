[카테고리](/README.md)
## Freivalds' algorithm ([Random](/utils/Random.md) 필요)
```cpp
template <typename T>
bool freivalds(const vector<vector<T> > &a, const vector<vector<T> > &b, const vector<vector<T> > &c) { // n*n행렬 A, B, C에 대해 AB==C인지 O(LOOP * N^2)에 확인 // (0.5^LOOP)의 확률로 AB!=C인데 AB==C라고 틀린 판별을 내릴 가능성 있음
    int n = a.size();
    vector<unsigned long long> Bx(n), x(n);

    static Random<int> rand(0, 1);
    constexpr int LOOP = 30;

    for (int it = LOOP; it--;) {
        for (auto &e : x) e = rand();
        
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

### 원리
$n \times n$행렬 $A, B, C$가 $AB = C$를 만족한다면 임의의 $n \times 1$ 행렬 $x$에 대해 $ABx = Cx$를 만족한다.   
$ABx$의 값은 $Bx$를 먼저 계산한 뒤 $A(Bx)$를 계산하면 $O(N^2)$에 계산이 가능하므로 랜덤한 행렬 $x$를 잡아 $ABx = Cx$인지 확인하는 것은 $O(N^2)$에 가능하다.

$AB$와 $C$를 비교하는 대신 $ABx$와 $Cx$를 비교하는 알고리즘을 생각하자.   
$ABx \neq Cx$라면 $AB \neq C$임은 확실하고(대우명제임),   
따라서 알고리즘이 틀릴 확률은 $ABx = Cx$이지만 $AB \neq C$일 확률과 같다.   
$x$의 원소가 $0$과 $1$로만 이루어져있을 때 이러한 확률은 $\dfrac{1}{2}$ 미만이므로 $x$를 바꿔가며 알고리즘을 여러 번 시행하면 높은 정확도를 보장할 수 있다.   

### 참고링크
https://blog.naver.com/sluggeryck/220938909066   

### 난수를 사용하지 않는 $O(N^2)$ 알고리즘 (PS 범위 아님)
ps-snippet 레포지토리와는 거리가 먼 듯 해서 https://simtal.tistory.com/41 에 정리해둠   