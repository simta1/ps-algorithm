[카테고리](/README.md)
## Erasable Priority Queue (코드 출처 : https://nyaannyaan.github.io/library/data-structure/erasable-priority-queue.hpp)
```cpp
template <typename T, bool Maximize=true> // https://nyaannyaan.github.io/library/data-structure/erasable-priority-queue.hpp
class ErasablePQ {
private:
    using PQ = conditional_t<Maximize, priority_queue<T>, priority_queue<T, vector<T>, greater<T> > >;
    PQ pq, del;

    void clean() {
        while (!pq.empty() && !del.empty() && pq.top() == del.top()) pq.pop(), del.pop();
    }

public:
    void push(const T& val) { pq.push(val); }
    void erase(const T& val) { del.push(val); } // 이미 존재하는 원소만 들어온다고 가정함

    T top() {
        clean();
        assert(!pq.empty());
        return pq.top();
    }

    void pop() {
        clean();
        assert(!pq.empty());
        pq.pop();
    }
};
```

### 시간복잡도
$O(\log{N})$

### 사용설명
erase의 매개변수로 보내는 값은 우선순위큐에 이미 있는 원소여야 함   

### 문제
[대표 선수](https://www.acmicpc.net/problem/2461)   
<!-- TODO https://www.acmicpc.net/problem/13513     -->

### 참고링크
https://overnap.com/erasable-heap/   
https://nyaannyaan.github.io/library/data-structure/erasable-priority-queue.hpp   