#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

template <typename T>
struct Point {
    T x, y;

    bool operator<(const Point &other) const { return tie(x, y) < tie(other.x, other.y); }
    Point operator-(const Point &other) const { return {x - other.x, y - other.y}; }
};

template <typename T>
T crossProduct(const Point<T> &p1, const Point<T> &p2) {
    return (p1.x * p2.y - p2.x * p1.y);
}

template <typename T>
int ccw(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3) { // -1 : 시계, 0 : 일직선, 1 : 반시계
    T cp = crossProduct(p2 - p1, p3 - p1);
    return (cp > 0) - (cp < 0);
}

template <typename T>
vector<Point<T> > getConvexHull(vector<Point<T> > points) { // points 원본 배열 바껴도 괜찮으면 &points로 받기
	assert (points.size() >= 3);

	swap(points[0], *min_element(points.begin(), points.end()));
	sort(points.begin() + 1, points.end(), [&](const Point<T> &a, const Point<T> &b) {
		int dir = ccw(points[0], a, b);
		return dir ? dir > 0 : a < b;
	});

	vector<Point<T> > v;
	for (auto &point : points) {
		while (v.size() >= 2 && ccw(v[v.size() - 2], v[v.size() - 1], point) <= 0) v.pop_back();
		v.push_back(point);
	}

	return v;
}

template <typename T>
ld dist(const Point<T> &a, const Point<T> &b) {
    return hypotl((ld)a.x - b.x, (ld)a.y - b.y);
}

template <typename T>
ld rotatingCalipers(const vector<Point<T>> &hull) {
	int n = hull.size();
	if (n == 1) return 0.0L;
	if (n == 2) return 2.0L * dist(hull[0], hull[1]);

    auto proj = [&](const Point<T> &p, ld ax, ld ay) {
        return (ld)p.x * ax + (ld)p.y * ay;
    };

    Point<T> e0 = hull[1] - hull[0];
    ld len0 = hypotl(e0.x, e0.y);
    ld ux = e0.x / len0, uy = e0.y / len0;
    ld vx = -uy, vy = ux;

    int top = 0, bot = 0, right = 0, left = 0;
    for (int i = 1; i < n; i++) {
        ld pu = proj(hull[i], ux, uy),  qu = proj(hull[right], ux, uy);
        ld ru = proj(hull[left], ux, uy);
        ld pv = proj(hull[i], vx, vy),  tv = proj(hull[top], vx, vy);
        ld bv = proj(hull[bot], vx, vy);
        if (pv > tv) top = i;
        if (pv < bv) bot = i;
        if (pu > qu) right = i;
        if (pu < ru) left = i;
    }

    ld res = numeric_limits<ld>::infinity();

    for (int i = 0; i < n; i++) {
		auto e = hull[(i + 1) % n] - hull[i];
        ld L = hypotl(e.x, e.y);
        ld ux = e.x / L, uy = e.y / L;
        ld vx = -uy, vy = ux;

        while (proj(hull[(top + 1) % n], vx, vy) > proj(hull[top], vx, vy)) ++top %= n;
        while (proj(hull[(bot + 1) % n], vx, vy) < proj(hull[bot], vx, vy)) ++bot %= n;
        while (proj(hull[(right + 1) % n], ux, uy) > proj(hull[right], ux, uy)) ++right %= n;
        while (proj(hull[(left + 1) % n], ux, uy) < proj(hull[left], ux, uy)) ++left %= n;

		res = min(res, proj(hull[right], ux, uy) - proj(hull[left], ux, uy) + proj(hull[top], vx, vy) - proj(hull[bot], vx, vy));
    }
    return res * 2;
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int n;
	cin >> n;

	vector<Point<ll> > v(n);
	for (auto &[x, y] : v) cin >> x >> y;

	cout << fixed << setprecision(10);
	if (n == 2) cout << 2 * dist(v[0], v[1]);
	else {
		auto hull = getConvexHull(v);
		cout << rotatingCalipers(hull);
	}

	return 0;
}