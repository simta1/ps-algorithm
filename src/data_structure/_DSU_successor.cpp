DSU dsu(n);

// [l:r] 순회
for (int i = find(l); i <= r; i = find(i + 1))

// i 제거
merge(i, i + 1);
