[카테고리](/README.md)
# 테스트 안 한 코드. 아직 작성중... 임시 코드 <!-- TODO -->
해쉬 클래스 만들어야 되고   
#define d 대신 상수 정의해서 쓰는 쪽으로 변경하고   
소수 q의 자료형을 ll까지 쓸 수 있게 하거나 아니면 소수 여러개 쓰는 방식으로.. <- 해쉬 클래스로 구현하게 될 듯   

## Rabin-Karp
```cpp
#define d 256 // ASCII 문자 집합 크기

vector<int> rabinKarp(const string &text, const string &pattern, int q=10007) {
    int n = text.size();
    int m = pattern.size();

    vector<int> res;
    if (n < m) return res;

    int h = 1;
    // h = modInverse(d, q);
    for (int i = 1; i < m; i++) h = (h * d) % q;

    int p = 0;
    int t = 0;
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j = 0;
            while (j < m && text[i + j] == pattern[j]) ++j;
            res.push_back(i);
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t = (t + q);
        }
    }

    return res;
}
```
### 시간복잡도 
$O()$   

### 구현 주의사항


### 사용설명


### 문제
[]()

### 원리


### 참고링크