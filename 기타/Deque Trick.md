[카테고리](/README.md)
# 작성중.. 코드 실험 안 끝남 <!-- TODO -->
## Deque Trick
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

### 구현 주의사항


### 사용설명


### 문제
[최솟값 찾기](https://www.acmicpc.net/problem/11003) - min   
[상자 빌리기](https://www.acmicpc.net/problem/21982) - max   

### 원리
[작은 새](https://www.acmicpc.net/problem/10129)처럼 조건 복잡해졌을 때 안 헷갈리는 법.   

결과적으로 최대(최소)값은 항상 front()에 위치   
ex) min을 구하려 한다면 `v[dq.front()] <= v[dq.front() + 1] <= ... <= v[dq.back()]`   
push_back()하기 전에 조건 만족하지 않는 것들을 pop해야되므로   
`while (!dq.empty() && !(v[dq.back()] <= v[i])) dq.pop_back();`이고   
따라서 정리하면 `while (!dq.empty() && v[dq.back()] >  v[i]) dq.pop_back();`   
<!-- TODO monotone deque, monotone stack 등등 클래스로 구현해서 써도 괜찮을 듯. 생성자에서 람다함수로 cmp함수 받고. while (!empty() && !cmp) pop(); 하면 될 듯 -->   