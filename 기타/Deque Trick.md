[카테고리](/README.md)
# 작성중.. 코드 실험 안 끝남
### Deque Trick (min)
```cpp
vector<int> dequeTrick(int len, const vector<int> &v) {
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
vector<int> dequeTrick(int len, const vector<int> &v) {
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
### 시간복잡도 
$O()$   

### 주의사항


### 사용관련


### 백준문제
[최솟값 찾기](https://www.acmicpc.net/problem/11003) - min   
[상자 빌리기](https://www.acmicpc.net/problem/21982) - max   