[카테고리](/README.md)
## Deque Trick
### Deque Trick (min)
```cpp
vector<int> dequeTrickMin(int len, const vector<int> &v) { // res[i]는 v[max(0, i - len + 1)]~v[i]의 최솟값 // 즉, 정확히 길이가 len인 구간의 최솟값은 res[len-1:n)에 저장됨
    vector<int> res(v.size());
    deque<int> dq;

    for (int i = 0; i < v.size(); i++) {
        while (!dq.empty() && v[dq.back()] > v[i]) dq.pop_back();
        dq.push_back(i);
        if (i - dq.front() + 1 > len) dq.pop_front();
        res[i] = v[dq.front()];
    }

    return res;
}
```
### Deque Trick (max)
```cpp
vector<int> dequeTrickMax(int len, const vector<int> &v) { // res[i]는 v[max(0, i - len + 1)]~v[i]의 최댓값 // 즉, 정확히 길이가 len인 구간의 최솟값은 res[len-1:n)에 저장됨
    vector<int> res(v.size());
    deque<int> dq;

    for (int i = 0; i < v.size(); i++) {
        while (!dq.empty() && v[dq.back()] < v[i]) dq.pop_back();
        dq.push_back(i);
        if (i - dq.front() + 1 > len) dq.pop_front();
        res[i] = v[dq.front()];
    }

    return res;
}
```
### Deque Trick (cmp 함수 복잡한 경우)
```cpp
deque<int> dq;

auto cmp = [&](int front, int back) { // front에 구하려는 값이 들어가야 함
    // ex) min이면 return v[front] <= v[back];
};

for (int i = 0; i < v.size(); i++) {
    while (!dq.empty() && !cmp(dq.back(), i)) dq.pop_back();
    dq.push_back(i);
    if (i - dq.front() + 1 > len) dq.pop_front();
}
```
### 시간복잡도 
$O(N)$   

### 문제
[최솟값 찾기](https://www.acmicpc.net/problem/11003) - min   
[상자 빌리기](https://www.acmicpc.net/problem/21982) - max   
[작은 새](https://www.acmicpc.net/problem/10129) - cmp 복잡한 경우   

### 원리
[작은 새](https://www.acmicpc.net/problem/10129)처럼 조건 복잡해졌을 때 안 헷갈리는 법.   

결과적으로 최대(최소)값은 항상 front()에 위치   
ex) min을 구하려 한다면 `v[dq.front()] <= v[dq.front() + 1] <= ... <= v[dq.back()]`   
push_back()하기 전에 조건 만족하지 않는 것들을 pop해야되므로   
`while (!dq.empty() && !(v[dq.back()] <= v[i])) dq.pop_back();`이고   
따라서 정리하면 `while (!dq.empty() && v[dq.back()] >  v[i]) dq.pop_back();`   