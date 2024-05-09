[카테고리](/README.md)
### Template Argument Deduction (C++17~)
```cpp
pair p(3, 4); // pair<int, int> p(3, 4);
vector v(n, vector(m, vector<int>(k))); // vector<vector<vector<int> > > v(n, vector<vector<int> >(m, vector<int>(k)));
```

다차원 벡터 선언할 때 편하다.