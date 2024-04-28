[카테고리](/README.md)
### Mo's algorithm (push, pop)
```cpp
class Mo {
   private:
    struct Query {
        int s, e, idx;
    };

    vector<Query> queries;
    vector<int> answer, v;

    void push(int idx) {
        
    }

    void pop(int idx) {
        
    }
    
    int query() {
    
    }

  public:
    Mo(int m, vector<int> &v) : queries(m), answer(m), v(v) {
        int i = 0;
        for (auto &[s, e, idx] : queries) {
            cin >> s >> e;
            --s, --e;
            idx = i++;
        }
        
        int sq = sqrt(v.size());
        sort(queries.begin(), queries.end(), [&sq](const Query& a, const Query& b) {
            if (a.s / sq != b.s / sq) return a.s < b.s;
            return a.e < b.e;
        });
    }

    const vector<int>& solve() {
        int s = queries[0].s, e = queries[0].e;
        for (int i = s; i <= e; i++) push(i);
        answer[queries[0].idx] = query();

        for (int i = 1; i < queries.size(); i++) {
            int idx1 = queries[i].s, idx2 = queries[i].e;
            while (s > idx1) push(--s);
            while (e < idx2) push(++e);
            while (s < idx1) pop(s++);
            while (e > idx2) pop(e--);
            answer[queries[i].idx] = query();
        }

        return answer;
    }
};
```
### Mo's algorithm (push_front, push_back, pop_front, pop_back)
```cpp
class Mo {
   private:
    struct Query {
        int s, e, idx;
    };

    vector<Query> queries;
    vector<int> answer, v;

    void push_front(int idx) {
        
    }

    void push_back(int idx) {
        
    }

    void pop_front(int idx) {
        
    }

    void pop_back(int idx) {
        
    }
    
    int query() {
    
    }

  public:
    Mo(int m, vector<int> &v) : queries(m), answer(m), v(v) {
        int i = 0;
        for (auto &[s, e, idx] : queries) {
            cin >> s >> e;
            --s, --e;
            idx = i++;
        }
        
        int sq = sqrt(v.size());
        sort(queries.begin(), queries.end(), [&sq](const Query& a, const Query& b) {
            if (a.s / sq != b.s / sq) return a.s < b.s;
            return a.e < b.e;
        });
    }

    const vector<int>& solve() {
        int s = queries[0].s, e = queries[0].e;
        for (int i = s; i <= e; i++) push_back(i);
        answer[queries[0].idx] = query();

        for (int i = 1; i < queries.size(); i++) {
            int idx1 = queries[i].s, idx2 = queries[i].e;
            while (s > idx1) push_front(--s);
            while (e < idx2) push_back(++e);
            while (s < idx1) pop_front(s++);
            while (e > idx2) pop_back(e--);
            answer[queries[i].idx] = query();
        }

        return answer;
    }
};
```
### 시간복잡도 
$O((N+Q)\sqrt N \times T(N))$   
T(N)은 push(), pop()의 시간복잡도

### 주의사항
solve() 코드에서 push를 pop보다 먼저하지 않으면 구간 조정할 때 push()하지도 않은 부분을 pop()부터 하게 되어 에러날 수 있음   
무조건 push코드를 pop코드 위에 작성

### 백준문제
[배열의 힘](https://www.acmicpc.net/problem/8462)