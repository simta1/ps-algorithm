[카테고리](/README.md)
## LineContainer
### kactl 코드 그대로 가져왔음, 코드 출처 : https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
### TODO upper=false일 땐 내가 추가한 거고 아직 테스트 안 된 코드임
```cpp
struct Line { // https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

template <bool upper>
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b);
    }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
        if constexpr (!upper) k = -k, m = -m;
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		if constexpr (upper) return l.k * x + l.m;
        else return -(l.k * x + l.m);
	}
};
```
### 시간복잡도
$O()$   

### 구현 주의사항


### 사용설명


### 문제
[반평면 땅따먹기](https://www.acmicpc.net/problem/12795)

### 참고링크
https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h   