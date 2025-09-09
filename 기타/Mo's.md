[카테고리](/README.md)
## Mo's
### Mo's algorithm
```cpp
template <typename T>
vector<T> mo(const vector<int> &v, const vector<pair<int, int> > &_queries, const bool is1based = true) {
	int q = _queries.size();

    struct Query { int s, e, idx; };
    vector<Query> queries(q);
    vector<T> answer(q);

	for (int i = 0; i < q; i++) {
		queries[i].s = _queries[i].first - is1based;
		queries[i].e = _queries[i].second - is1based;
		queries[i].idx = i;
	}

	int sq = sqrt(q);
	sort(queries.begin(), queries.end(), [&sq](const Query& a, const Query& b) {
		if (a.s / sq != b.s / sq) return a.s < b.s;
		return a.e < b.e;
	});

	// ----------------------------- 필요한 변수 선언 후 함수 채워서 사용
    auto push_back = [&](int idx) {};
    auto pop_back = [&](int idx) {};
    auto push_front = push_back;
    auto pop_front = pop_back;
    auto query = [&]() {};
	// -----------------------------

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
```
### 시간복잡도
$O((N+Q)\sqrt N \times T(N))$   
T(N)은 push(), pop()의 시간복잡도   
세그먼트 트리랑 같이 쓰는 경우 T(N)을 줄이기 위해 가능하다면 세그먼트 트리 대신 펜윅 트리 사용   

### 주의사항
solve() 코드에서 push를 pop보다 먼저하지 않으면 구간 조정할 때 push()하지도 않은 부분을 pop()부터 하게 되어 에러날 수 있음   
무조건 push코드를 pop코드 위에 작성   

### 백준문제
[배열의 힘](https://www.acmicpc.net/problem/8462)   
