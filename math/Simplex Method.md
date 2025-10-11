[카테고리](/README.md)
## Simplex Method
```cpp
// a[m][n], b[m], c[n+1], sol[n+1] : 0-based // x >= 0, Ax <= b일 때 c^Tx의 최대값
// 0: found solution, 1: no feasible solution, 2: unbounded // res랑 sol은 0일 때만 사용
template <typename double_t>
tuple<int, double_t, vector<double_t> > simplex(int n, vector<vector<double_t> > a, vector<double_t> b, vector<double_t> c) {
    assert(n == a[0].size() && n == c.size()); // n: 변수 개수
    assert(a.size() == b.size());
    int m = b.size(); // m: 제약조건 개수

    vector<double_t> sol(c.size());
    double_t res = 0;

    const double_t eps = 1e-7;
    auto eq = [&](double_t a, double_t b) { return abs(a - b) < eps; };
    auto lt = [&](double_t a, double_t b) { return a < b && !eq(a, b); };

    vector<double_t> left(m), down(n);
    for (int i = 0; i < n; i++) down[i] = i;
    for (int i = 0; i < m; i++) left[i] = n + i;

    auto pivot = [&](int x, int y) {
        swap(left[x], down[y]);
        double_t k = a[x][y];
        vector<int> nz;
        for (int i = 0; i < n; i++) {
            a[x][i] /= k;
            if (!eq(a[x][i], 0)) nz.push_back(i);
        }
        a[x][y] = 1;
        b[x] /= k;

        for (int i = 0; i < m; i++) if (i != x && !eq(a[i][y], 0)) {
            k = a[i][y];
            a[i][y] = 0;
            b[i] -= k * b[x];
            for (int j : nz) a[i][j] -= k * a[x][j];
        }
        if (eq(c[y], 0)) return;
        k = c[y];
        c[y] = 0;
        res += k * b[x];
        for (int i : nz) c[i] -= k * a[x][i];
    };

    while (1) {
        int x = -1, y = -1;
        for (int i = 0; i < m; i++) if (lt(b[i], 0) && (!~x || b[x] > b[i])) x = i;
        if (x == -1) break;
        for (int i = 0; i < n; i++) if (lt(a[x][i], 0) && (!~y || a[x][y] > a[x][i])) y = i;
        if (y == -1) return {1, res, sol};
        pivot(x, y);
    }

    while (1) {
        int x = -1, y = -1;
        for (int i = 0; i < n; i++) if (lt(0, c[i]) && (!~y || c[y] < c[i])) y = i;
        if (y == -1) break;
        for (int i = 0; i < m; i++) if (lt(0, a[i][y]) && (!~x || b[x]/a[x][y] > b[i]/a[i][y])) x = i;
        if (x == -1) return {2, res, sol};
        pivot(x, y);
    }
    
    for (int i = 0; i < m; i++) if (left[i] < n) sol[left[i]] = b[i];
    return {0, res, sol};
}
```
### 시간복잡도
최악은 $O(NM 2^N)$ 보통 $O(N^3 M)$ 정도로 동작한다고 함   

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