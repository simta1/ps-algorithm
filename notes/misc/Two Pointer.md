[카테고리](/README.md)
## Two Pointer
### 연속한 구간 검색
- 구간 정보 \[s:e\)로 저장
- s=0, e=0으로 같은 방향에서 시작
- 배열의 모든 원소가 양수여야 함

합이 sum인 연속한 부분 수열의 개수 구하기([수들의 합 2](https://www.acmicpc.net/problem/2003))   
```cpp
int f(int n, int sum, const vector<int> &v) {
    int cnt = 0;
    for (int s = 0, e = 0, cur = 0; s < n; cur -= v[s++]) {
        while (e < n && cur < sum) cur += v[e++];
        cnt += (cur == sum);
    }
    return cnt;
}
```

합이 sum 이상인 연속한 부분 수열 중 길이가 가장 짧은 수열 구하기([부분합](https://www.acmicpc.net/problem/1806))   
```cpp
int f(int n, int sum, const vector<int> &v) {
    int res = n + 1;
    for (int s = 0, e = 0, cur = 0; s < n; cur -= v[s++]) {
        while (e < n && cur < sum) cur += v[e++];
        if (cur >= sum) res = min(res, e - s);
    }
    return res == n + 1 ? -1 : res;
}
```

같은 수가 중복해서 나오지 않는 연속한 부분 수열의 개수 구하기([List of Unique Numbers](https://www.acmicpc.net/problem/13144))   
```cpp
long long f(int n, const vector<int> &v) {
    long long res = 0;
    vector<int> cnt(*max_element(v.begin(), v.end()) + 1);
    for (int s = 0, e = 0; s < n; --cnt[v[s++]]) {
        while (e < n && !cnt[v[e]]) ++cnt[v[e++]];
        res += e - s;
    }
    return res;
}
```

수열에서 최대 k번 원소를 삭제한 수열에서 짝수로 이루어져 있는 가장 긴 연속한 부분 수열의 길이([가장 긴 짝수 연속한 부분 수열 (large)](https://www.acmicpc.net/problem/22862))   
```cpp
int f(int n, int k, const vector<int> &v) {
    int res = 0, cnt = 0;
    for (int s = 0, e = 0; s < n; cnt -= v[s++] & 1) {
        while (e < n && (~v[e] & 1 || cnt + 1 <= k)) cnt += v[e++] & 1;
        res = max(res, e - s - cnt);
    }
    return res;
}
```

### 원소 두 개 검색
- 두 원소를 v\[s\], v\[e\]로 저장
- 배열이 정렬 되어 있어야 함

distinct한 배열에서 합이 sum인 두 수 고르는 경우의 수([주몽](https://www.acmicpc.net/problem/1940))   
```cpp
int f(int n, int sum, vector<int> v) { // v가 distinct일 때만 사용가능
    sort(v.begin(), v.end());

    int res = 0;
    for (int s = 0, e = n - 1; s < n; s++) {
        if (s >= e) break;
        while (e - 1 > s && v[s] + v[e - 1] >= sum) --e;
        res += v[s] + v[e] == sum;
    }
    return res;
}
```

차이가 m 이상인 두 수 중 가장 작은 차이 구하기([수 고르기](https://www.acmicpc.net/problem/2230))   
```cpp
int f(int n, int m, vector<int> v) {
    sort(v.begin(), v.end());

    int s = 0, e = lower_bound(v.begin(), v.end(), v[s] + sum) - v.begin();
    int res = v[e] - v[s];
    for (s = 1; s < n; s++) {
        while (e + 1 < n && v[e] - v[s] < sum) ++e;
        if (v[e] - v[s] >= sum) res = min(res, v[e] - v[s]);
        else break;
    }
    return res;
}
```

### 시간복잡도 
$O(N)$   

### 구현 주의사항
s나 e중 하나를 정해서 0부터 n-1까지 순회하고 다른 변수는 그에 맞춰 이동시킨다고 생각하며 구현하면 편하다.   
난 보통 s를 0부터 n-1까지 순회하고, 그에 맞춰 e를 이동시키며 푸는 편이다.   
[주몽](https://www.acmicpc.net/problem/1940)처럼 s, e가 반대방향으로 이동할 때는 if `(s >= e) break;`를 추가해야 한다.   