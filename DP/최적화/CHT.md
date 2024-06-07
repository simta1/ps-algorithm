[카테고리](/README.md)
### CHT
```cpp
template <typename T>
class CHT {
private:
    struct Line { // y = ax + b (x >= s)
        T a, b;
        double s;

        T getY(T x) {
            return a * x + b;
        }
    };

    double intersect(const Line &l1, const Line &l2) {
        // assert(l1.a != l2.a);
        return double(l2.b - l1.b) / (l1.a - l2.a);
    }

    vector<Line> lines;
    int idx = 0; // query(x)에서 x가 단조증가하며 들어올 때 O(N)으로 바꾸는 용

public:
    CHT() {}

    void add(T a, T b) {
        Line cur = {a, b, 0};
        while (!lines.empty()) {
            cur.s = intersect(cur, lines.back());
            if (cur.s <= lines.back().s) lines.pop_back();
            else break;
        }
        lines.push_back(cur);
        idx = min(idx, int(lines.size() - 1));
    }

    T fastQuery(T x) {
        while (idx + 1 < lines.size() && lines[idx + 1].s <= x) ++idx;
        return lines[idx].getY(x);
    }
    
    T query(T x) {
        int idx = upper_bound(lines.begin(), lines.end(), x, [](double x, const Line &f) {
            return x < f.s;
        }) - lines.begin() - 1;
        return lines[idx].getY(x);
    }
};
```
### int main()
```cpp
vector<ll> dp(n);
CHT<ll> cht;

auto x = [&](int i) { return _; };
auto slope = [&](int j) { return _; };
auto yIntercept = [&](int j) { return _; };

dp[0] = _;
for (int i = 1; i < n; i++) {
    cht.add(slope(i - 1), yIntercept(i - 1));
    dp[i] = cht.query(x(i));
}

cout << dp.back();
```
### 시간복잡도
dp[n]을 계산하는데 걸리는 시간:   
x(i)가 단조증가인 경우(CHT::fastQuery 사용) $O(N)$   
x(i)가 불규칙한 경우(CHT::query 사용) $O(N~logN)$   

### 사용관련
$dp[i] = min_{j < i} \left[ slope(j) \cdot x(i) + y \_ intercept(j) \right]$   
수식에 맞게 람다함수 작성   

x(i)값이 단조증가한다면 CHT::fastQuery() 사용   
x(i)값이 불규칙하게 바뀌는 경우 CHT::query() 사용, CHT::query()에선 매번 이분탐색으로 x에 해당하는 직선의 방정식 찾아서 계산함   
fastQuery()쓸꺼면 fastQuery()만 호출. 중간에 CHT::query() 섞어쓰면 꼬임      

### 백준문제
[나무 자르기](https://www.acmicpc.net/problem/13263)   
[특공대](https://www.acmicpc.net/problem/4008)   

### 참고문헌
https://justicehui.github.io/hard-algorithm/2019/01/25/CHT/   
https://seastar105.tistory.com/21   
https://g-egg.tistory.com/7   