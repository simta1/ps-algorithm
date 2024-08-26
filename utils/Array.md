### swapLR
```cpp
void swapLR(vector<int> &v, int idx) {
    // cout << "operate(" << -~idx << ") before : ";
    // for (auto &e : v) cout << e << " "; cout << "\n";

    rotate(v.begin(), v.begin() + idx, v.end());
    rotate(v.begin(), v.begin() + 1, v.begin() + v.size() - idx);

    // cout << "operate(" << -~idx << ") after : ";
    // for (auto &e : v) cout << e << " "; cout << "\n\n";
}
```

{ v[0], ..., v[idx - 1], v[idx], v[idx + 1], ..., v[n - 1] } -> { v[idx + 1], ..., v[n - 1], v[idx], v[0], ..., v[idx - 1]}

[두 순열 (Easy)](https://www.acmicpc.net/problem/30240)
