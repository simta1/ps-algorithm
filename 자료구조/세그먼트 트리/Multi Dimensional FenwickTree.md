[카테고리](/README.md)
### Multi Dimensional FenwickTree (point update & range query)
```cpp
template <class T, int... Ns>
struct BIT {
	T val = 0;
	void upd(T v) { val += v; }
	T query() { return val; }
};

template <class T, int N, int... Ns>
struct BIT<T, N, Ns...> {
	BIT<T, Ns...> bit[N + 1];

	template <typename... Args>
    void upd(int pos, Args... args) {
		for (; pos <= N; pos += (pos & -pos)) bit[pos].upd(args...);
	}

	template <typename... Args>
    T sum(int r, Args... args) {
		T res = 0;
		for (; r; r -= (r & -r)) res += bit[r].query(args...);
		return res;
	}

	template <typename... Args>
    T query(int l, int r, Args... args) {
		return sum(r, args...) - sum(l - 1, args...);
	}
};

// BIT<int, 1024, 1024> fw;
```
### 시간복잡도
update $O(log^D(N))$, D는 차원

### 주의사항
배열로 구현된거라 어느정도 크기부터는 지역변수로 선언 시 메모리 터짐   
전역변수로 선언해야 됨   
코드 출처 : https://usaco.guide/plat/2DRQ?lang=cpp   

### 백준 문제
[구간 합 구하기 3](https://www.acmicpc.net/problem/11658)