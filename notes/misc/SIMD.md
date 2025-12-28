[카테고리](/README.md)
## SIMD
```cpp
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2")

#pragma omp simd
for (int i = 0; i < N; i++) {
    c[i] = a[i] + b[i];
}

```

코드에 __m256과 같이 직접 AVX 명령어를 명시적으로 작성하지 않고도 컴파일러가 자동으로 최적화하게 하는 법   
alignas(32)해둬야 함
적절한 최적화 레벨이 설정되어 있어야 함(gpt에 의하면 -O2 또는 -O3)라고 함
반복문에 데이터 종속성이 없다면 자동으로 최적화 되는듯?   

for문에서 컴파일러에 데이터가 독립적임을 알려주기 위해 `#pragma omp simd` 사용

`restrict`는 좀 구식인 듯   

### 시간복잡도
$O()$   

### 문제
[최대삼각형, 최소삼각형](https://www.acmicpc.net/problem/9484)   
wisqa라는 사람이 제출한 코드인데 공부하기 좋을 듯 https://www.acmicpc.net/source/21149775

### 참고링크