[카테고리](/README.md)
## RMQ(Range Minimum Query)
RMQ는 주어진 배열에서 임의의 범위 `[L:R]`에 대한 최소값을 찾는 문제로, 여러 구현이 가능하며 특정 구현만을 가리키는 말이 아니다.   
아래와 같이 여러 방식의 구현이 존재하며 특정 구현만을 가리키는 말은 아니지만 보통 RMQ라고 하면 정적 RMQ를 처리하는 아래의 1번째 구현을 말하는 경우가 많고, 이 문서에서도 첫번째 구현을 다룬다.   
1. 전처리 $O(N\log{N})$, 쿼리 $O(1)$, 업데이트 불가능(=정적)
2. 전처리 $O(N)$, 쿼리 $O(\log{N})$, 업데이트 $O(\log{N})$ ([세그먼트 트리](/자료구조/세그먼트%20트리/세그먼트%20트리.md) 사용)   
3. 전처리 $O(N)$, 쿼리 $O(\sqrt{N})$, 업데이트 $O(\sqrt{N})$ ([제곱근 분할법](/기타/제곱근%20분할법.md) 사용)
5. 특정 길이$L$에 대해 $N-L+1$개의 모든 구간에서 최솟값 계산 $O(N)$ ([덱을 이용한 구간 최댓값 트릭](/기타/Deque%20Trick.md) 사용)   
### RMQ
```cpp
template <typename T>
class RMQ {
private:
	vector<vector<T> > mn; // mn[i][j]에 v[j:j+2^i)의 최솟값 저장 // 즉, j로 시작하며 2^i길이인 구간의 최솟값 저장

public:
	RMQ(const vector<T> &v) : mn(1, v) {
		for (int i = 1, len = 1; len * 2 <= v.size(); ++i, len *= 2) {
			mn.emplace_back(v.size() - len * 2 + 1);
			for (int j = 0; j < mn[i].size(); j++) mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + len]);
		}
	}

	T query(int a, int b) const { // 0-based // [a:b]에서 최솟값
		assert(0 <= a && a <= b && b < mn[0].size());
		int i = __lg(b - a + 1);
		return min(mn[i][a], mn[i][b - (1 << i) + 1]);
	}
};
```
### 시간복잡도
전처리 $O(N\log{N})$   
query $O(1)$   

### 사용설명
문제 푸는 거랑 상관없긴 한데 정적 RMQ임을 드러내기 위해 RMQ 객체를 const로 선언하는 거 추천   
```cpp
vector<int> v(n);
for (auto &e : v) cin >> e;

const RMQ rmq(v); // const로 선언
```

### 문제
[Prefix와 Suffix](https://www.acmicpc.net/problem/13576) - RMQ가 메인인 문제도 아니고 RMQ를 알아야만 풀 수 있는 문제도 아니지만 rmq를 사용할 수 있는 문제긴 함   
<!-- TODO 문제 추가 -->

### 참고링크
https://growth-coder.tistory.com/161   
https://infossm.github.io/blog/2023/08/19/range-query/   