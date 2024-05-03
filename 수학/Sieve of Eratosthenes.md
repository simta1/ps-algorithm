[카테고리](/README.md)
### Sieve of Eratosthenes code 1) primes 계산
```cpp
vector<int> getPrime(int n) {
    vector<int> isPrime(n + 1, 1), primes;

    for (long long i = 2; i <= n; i++) if (isPrime[i]) {
        primes.push_back(i);
        for (long long j = i * i; j <= n; j += i) isPrime[j] = 0;
    }

    return primes;
}
```
### code 2) isPrime만 계산
```cpp
vector<int> getPrime(int n) {
    vector<int> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;

    for (long long i = 2; i * i <= n; i++) if (isPrime[i]) {
        for (long long j = i * i; j <= n; j += i) isPrime[j] = 0;
    }

    return isPrime;
}
```
### 시간복잡도 
$O(N~log(logN))$   

### 주의사항
for문에서 곱셈할 때 overflow나지 않도록 long long으로 선언

### 사용관련
isPrime만 구하면 되는 경우 code 2) 사용하는 게 더 빠름

### 백준문제
[소수 구하기](https://www.acmicpc.net/problem/1929)