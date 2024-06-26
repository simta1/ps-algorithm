
### 최대힙
```cpp
priority_queue<template> pq;
```

### 최소힙
```cpp
priority_queue<template, vector<template>, greater<template> > pq;
```

### functor
```cpp
struct Compare {
    bool operator()(const Edge &bottom, const Edge &top) const {
        // ex) return bottom.cost > top.cost; 최소 우선순위 큐
    }
};

priority_queue<template, vector<template>, Compare> pq;
```
operator()에서 오른쪽 매개변수가 top()쪽 방향


