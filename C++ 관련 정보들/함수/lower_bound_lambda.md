### lower_bound
```cpp
print(*lower_bound(v.begin(), v.end(), value, [](const pii &p, int val) {
    return p.first < val;
}));
```
### upper_bound
```cpp
print(*upper_bound(v.begin(), v.end(), value, [](int val, const pii &p) {
    return val < p.first;
}));
```
### test code
```cpp
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void print(pii p) {
    cout << p.first << " " << p.second << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    vector<pii> v = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}};
    // vector<pii> v = {{1, 0}, {2, 0}, {3, 0}, {5, 0}, {6, 0}, {7, 0}};
    sort(v.begin(), v.end());
    for (auto &[x, y] : v) cout << x << " " << y << "\n";
    cout << "\n";

    cout << "LOWER_BOUND\n";
    print(*lower_bound(v.begin(), v.end(), 4, [](const pii &p, int val) {
        return p.first < val;
    }));
    // print(*lower_bound(v.begin(), v.end(), 4, [](const pii &p, int val) {
    //     return p.first <= val;
    // }));
    // print(*lower_bound(v.begin(), v.end(), 4, [](const pii &p, int val) {
    //     return p.first > val;
    // }));
    // print(*lower_bound(v.begin(), v.end(), 4, [](const pii &p, int val) {
    //     return p.first >= val;
    // }));

    cout << "UPPER_BOUND\n";
    print(*upper_bound(v.begin(), v.end(), 4, [](int val, const pii &p) {
        return val < p.first;
    }));
    // print(*upper_bound(v.begin(), v.end(), 4, [](int val, const pii &p) {
    //     return val <= p.first;
    // }));
    // print(*upper_bound(v.begin(), v.end(), 4, [](int val, const pii &p) {
    //     return val > p.first;
    // }));
    // print(*upper_bound(v.begin(), v.end(), 4, [](int val, const pii &p) {
    //     return val >= p.first;
    // }));
}
```