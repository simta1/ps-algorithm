[메르텐스 함수](/수학/메르텐스.md)   
[카테고리](/README.md)
## Xudyh's sieve (Mertens Trick)
```cpp
template <typename T, T mod>
class Xudyh {
private:
    vector<T> pfsF; // precomputation
    map<ll, T> mp; // memoization

    T positiveMod(ll x) {
        return (x % mod + mod) % mod;
    }

    T pfs_fg(ll x) { // (f * g)(x) = 
        x %= mod;
        // return positiveMod();
    };

    T pfs_g(ll x) { // g(x) = 
        x %= mod;
        // return positiveMod();
    };

    T pfs_f(ll x) { // f(x) = mu(x) * x
        if (x < pfsF.size()) return pfsF[x]; // precomputation

        if (mp.count(x)) return mp[x];
        auto &res = mp[x];

        res = pfs_fg(x); // S_f(N) = (  S_f*g(N) - sum {d = 2~N} g(d)S_f(N/d)  ) / g(1)
        for (ll i = 2, j; i <= x; i = j + 1) {
            j = x / (x / i);
            res -= pfs_f(x / i) * (pfs_g(j) - pfs_g(i - 1) + mod) % mod;
            res %= mod;
        }
        res = (res + mod) % mod;
        // res /= g(1);

        return res;
    }

public:
    Xudyh(ll maxN) {
        int fSize = pow(2 * maxN, 2.0 / 3);
        // pfsF = getMulFunc(fSize);
        for (int i = 1; i < pfsF.size(); i++) pfsF[i] = (pfsF[i] + pfsF[i - 1]) % mod;
    }

    T getSum(ll i, ll j) {
        return positiveMod(pfs_f(j) - pfs_f(i - 1));
    }
};
```
### 시간복잡도
$O(N^{2/3})$   

### 구현 주의사항
뫼비우스 함수나 harmonic lemma 등등 쓰는 모든 문제에 적용되는 거긴 한데   
일단 틀리면 오버플로우 나는지부터 확인   
모든 연산 사이사이에 positiveMod형태로 계산돼도록 해야 함   

### 사용설명
주석처리 해둔 부분만 상황에 맞게 바꿔서 사용   
[메르텐스 함수](/수학/메르텐스.md)는 바로 쓸 수 있도록 따로 구현해둠   
<!-- TODO xudyh 코드랑 비슷하게 클래스로 바꿔야 함 -->

### 문제
[비로소 서로소](https://www.acmicpc.net/problem/32240)

### 원리
$g(1)S_f(N) = S_{f*g}(N) - \displaystyle\sum_{d=2}^{N} g(d) S_f \left(\left\lfloor \dfrac{N}{d} \right\rfloor \right) $   
증명은 [메르텐스 함수](/수학/메르텐스.md) 원리 참고   

$S_f(N) = \dfrac {S_{f*g}(N) - \displaystyle\sum_{d=2}^{N} g(d) S_f \left(\left\lfloor \dfrac{N}{d} \right\rfloor \right) }{g(1)} $   


### 참고링크
https://codeforces.com/blog/entry/54150   
https://gbroxey.github.io/blog/2023/04/30/mult-sum-1.html   
https://xy-plane.tistory.com/19   
https://gratus-blog.tistory.com/108   