[카테고리](/README.md)
## Simplex Method
```cpp
template <typename double_t>
class LP {
private:
    const double_t eps = 1e-7;
    
    bool eq(double_t a, double_t b) { return abs(a - b) < eps;  }
    bool lt(double_t a, double_t b) { return a < b && !eq(a, b); }

    int n, m; // n: 변수 개수, m: 제약조건 개수
    vector<vector<double_t> > a; // a[m][n], b[m], c[n], sol[n]
    vector<double_t> b, c, sol; // a는 제약조건 계수, b는 제약조건 제한값(음수 가능), c는 최대화할 목적함수의 계수
    double_t res;

public:
    template <typename T>
    LP(const vector<T> &v, int constraints = 0) : c(v.begin(), v.end()), sol(v.size()) { // c는 목적함수의 계수들임, 1-based임
        n = c.size();
        m = 0;
        b.reserve(constraints);
        a.reserve(constraints);
    }

    void add(const vector<double_t> &_a, double_t _b) { // a0x0 + a1x1 + ... + a(n-1)x(n-1) <= b
        assert(_a.size() == n);
        a.push_back(_a);
        b.push_back(_b);
        ++m;
    }
    
    // https://zigui.tistory.com/5
    // 0: found solution, 1: no feasible solution, 2: unbounded
    int simplex() {
        fill(sol.begin(), sol.end(), 0);
        res = 0;

        vector<double_t> left(m), down(n);
        for (int i = 0; i < n; i++) down[i] = i;
        for (int i = 0; i < m; i++) left[i] = n + i;

        auto pivot = [&](int x, int y) {
            swap(left[x], down[y]); // 기저 변수 교체?
            double_t k = a[x][y];
            a[x][y] = 1;
            vector<int> nz;
            for (int i = 0; i < n; i++) { // 행 스케일링?
                a[x][i] /= k;
                if (!eq(a[x][i], 0)) nz.push_back(i);
            }
            b[x] /= k;
    
            for (int i = 0; i < m; i++) { // 가우스 소거?
                if (i == x || eq(a[i][y], 0)) continue;
                k = a[i][y]; a[i][y] = 0;
                b[i] -= k * b[x];
                for (int j : nz) a[i][j] -= k * a[x][j];
            }
            if (eq(c[y], 0)) return;
            k = c[y];
            c[y] = 0;
            res += k * b[x];
            for (int i : nz) c[i] -= k * a[x][i];
        };

        while (1) { // Eliminating negative b[i]
            int x = -1, y = -1;
            for (int i = 0; i < m; i++) if (lt(b[i], 0) && (!~x || b[x] > b[i])) x = i;
            if (x == -1) break;
            for (int i = 0; i < n; i++) if (lt(a[x][i], 0) && (!~y || a[x][y] > a[x][i])) y = i;
            if (y == -1) return 1;
            pivot(x, y);
        }

        while (1) {
            int x = -1, y = -1;
            for (int i = 0; i < n; i++) if (lt(0, c[i]) && (!~y || c[y] < c[i])) y = i;
            if (y == -1) break;
            for (int i = 0; i < m; i++) if (lt(0, a[i][y]) && (!~x || b[x]/a[x][y] > b[i]/a[i][y])) x = i;
            if (x == -1) return 2;
            pivot(x, y);
        }
        
        for (int i = 0; i < m; i++) if (left[i] < n) sol[left[i]] = b[i];
        return 0;
    }
    
    pair<double_t, vector<double_t> > getSolution() {
        return {res, sol};
    }
};
```
# TODO 아직 제대로 모름 공부중임 일단 그냥 적어놓은 거임   
### 시간복잡도

$O(2^N)$이지만 보통은 $O(NM(N+M))$으로 동작한다고 함      

최악의 경우(Klee-Minty) $O(2^N)$번 피봇팅이 발생할 수 있지만 보통 $O(M+N)$번 이하라고 함   
일반적으로 $O(NM(N+M))$   
빠르게 수렴하는 경우 $O(NM)$?   

### 구현 주의사항


### 사용설명
ex)   
    Maximize: $6x + 14y + 13z$   
    Subject to: $0.5x + 2y + z \le 24$, $x + 2y + 4z \le 60$   
    -> n = 2, m = 3, a = \[\[0.5, 2, 1\], \[1, 2, 4\]\], b = \[24, 60\], c = \[6, 14, 13\]

__LP Duality__   
tableu를 대각선으로 뒤집고 음수 부호를 붙인 답 = -(원 문제의 답)   
ex)   
n = 2, m = 3, a = [[0.5, 2, 1], [1, 2, 4]], b = [24, 60], c = [6, 14, 13]   
n = 3, m = 2, a = [[-0.5, -1], [-2, -2], [-1, -4]], b = [-6, -14, -13], c = [-24, -60]   

### 문제
[Cheese, If You Please](https://www.acmicpc.net/problem/17854)   

### 원리


### 참고링크
https://m.blog.naver.com/kks227/220967218183   
https://koosaga.com/226   
https://gazelle-and-cs.tistory.com/17

https://junstar92.tistory.com/382#simplex-algorithms - simplex법(원리)   
https://blog.naver.com/ksj8406/221431580870 - simplex법(구현)   
https://blog.naver.com/ksj8406/221432990250 - simplex법   
https://zigui.tistory.com/5 - simplex법 코드   

<!-- TODO
아직 안 읽어봤음 

한글자료(서울대)
https://ocw.snu.ac.kr/node/15734
https://ocw.snu.ac.kr/node/14955

영어자료
https://www.geeksforgeeks.org/linear-programming/
https://codeforces.com/blog/entry/105049
https://codeforces.com/blog/entry/105789

-->