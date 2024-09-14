[카테고리](/README.md)
## 오일러의 체 (Linear Sieve)
```cpp
vector<int> getLpf(int n) {
    vector<int> primes, lpf(n + 1); // least prime factor
    primes.reserve(n / log(n));

    for (ll i = 2; i <= n; i++) {
        if (!lpf[i]) {
            lpf[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > n) break;
            lpf[i * p] = p;
            if (i % p == 0) break;
        }
    }

    // return primes;
    return lpf;
}
```
### 시간복잡도 
$O(N)$   

### 구현 주의사항
array doubling 시간 생각보다 많이 걸림.   
primes.reserve() 해두는게 시간절약에 유의미한 영향 끼치는 듯   

### 사용설명
lpf\[n\]은 n의 최소소인수 저장   
즉, `lpf[n] == n`이면 `n은 소수`   
primes에는 소수 목록 저장됨   

### 문제
[어려운 소인수분해](https://www.acmicpc.net/problem/16563)   

### 참고링크
https://ahgus89.github.io/algorithm/Linear-sieve/   
https://ps.mjstudio.net/linear-sieve#%EC%9D%91%EC%9A%A9-1---%EC%86%8C%EC%9D%B8%EC%88%98%EB%B6%84%ED%95%B4   
https://codeforces.com/blog/entry/54090   