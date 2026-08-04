template <typename T>
vector<Point<T>> getConvexHull(vector<Point<T>> p) { // O(NlogN)
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    if (p.size() <= 1) return p;
    vector<Point<T>> h;
    for (auto x : p) {
        while (h.size() >= 2 && ccw(h[h.size() - 2], h.back(), x) <= 0) h.pop_back();
        h.push_back(x);
    }
    int lower = h.size();
    for (int i = p.size() - 2; i >= 0; i--) {
        while (h.size() > lower && ccw(h[h.size() - 2], h.back(), p[i]) <= 0) h.pop_back();
        h.push_back(p[i]);
    }
    h.pop_back();
    return h;
}