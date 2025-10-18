#include <bits/stdc++.h>
using namespace std;
using ld = double;
using ll = long long;

template <typename T>
struct Point3D {
    T x, y, z;

    Point3D() = default;
    Point3D(T x, T y, T z) : x(x), y(y), z(z) {}
    template <typename U> Point3D(const Point3D<U> &other) : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)), z(static_cast<T>(other.z)) {}

    bool operator<(const Point3D &other) const { return tie(x, y, z) < tie(other.x, other.y, other.z); }
    Point3D operator-(const Point3D &other) const { return {x - other.x, y - other.y, z - other.z}; }
};

template <typename T>
Point3D<T> crossProduct(const Point3D<T> &p1, const Point3D<T> &p2) {
    return {p1.y * p2.z - p1.z * p2.y, p1.z * p2.x - p1.x * p2.z, p1.x * p2.y - p1.y * p2.x};
}

template <typename T>
inline T dotProduct(const Point3D<T> &p1, const Point3D<T> &p2) {
    return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

ld f(const vector<Point3D<int> > &points) {
	if (points.empty()) return 0;
	ll sx = 0, sy = 0, sz = 0;
	ll sx2 = 0, sy2 = 0, sz2 = 0;
	for (auto [x, y, z] : points) {
		sx += x;
		sy += y;
		sz += z;
		sx2 += x * x;
		sy2 += y * y;
		sz2 += z * z;
	}
	return sx2 + sy2 + sz2 - ld(sx * sx + sy * sy + sz * sz) / points.size();
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	vector<Point3D<int> > v(n);
	for (auto &[x, y, z] : v) cin >> x >> y >> z;

	cout << fixed << setprecision(6);
	if (k == 1) cout << f(v);
	else {
		if (n < 3) {
			cout << 0.0;
		}
		else {
			ld ans = 9e18;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					for (int k = j + 1; k < n; k++) {
						auto normal = crossProduct(v[j] - v[i], v[k] - v[i]);

						vector<Point3D<int> > points[2];

						for (int it = 0; it < n; it++) if (it != i && it != j && it != k) {
							points[dotProduct<ll>(normal, v[it] - v[i]) > 0].push_back(v[it]);
						}

						for (int mask = 0; mask < 8; mask++) {
							points[mask & 1].push_back(v[i]);
							points[mask >> 1 & 1].push_back(v[j]);
							points[mask >> 2 & 1].push_back(v[k]);
							ans = min(ans, f(points[0]) + f(points[1]));
							points[mask & 1].pop_back();
							points[mask >> 1 & 1].pop_back();
							points[mask >> 2 & 1].pop_back();
						}
					}
				}
			}
			cout << ans;
		}
	}

	return 0;
}