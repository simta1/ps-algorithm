[카테고리](/README.md)
## Two Pointer <!-- TODO -->
### 같은방향에서 시작
- 연속한 구간 검색 시 사용
- 모두 양수여야 함
- 구간 정보 [s:e)로 저장
```cpp
int s = 0, e = 0, cur = 0, cnt = 0;
while (e <= n) {
    // cout << cnt << ":::" <<  s << " " << e << " " << cur << " ?= " << sum << "\n";
    cnt += (cur == sum);
    
    if (cur < sum) {
        if (e < n) cur += v[e++];
        else break;
    }
    else cur -= v[s++];
}
```
### 반대방향에서 시작
- 원소 두 개 검색 시 사용
- 정렬 되어 있어야 함
```cpp

```
### 시간복잡도 
$O()$   

### 구현 주의사항


### 사용설명


### 문제
[주몽](https://www.acmicpc.net/problem/1940) - 반대 방향   
[Building a Field](https://www.acmicpc.net/problem/16522) - 같은 방향   

### 원리


### 참고링크