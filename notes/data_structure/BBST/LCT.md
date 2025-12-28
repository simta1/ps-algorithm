[카테고리](/README.md)
## 링크/컷 트리(Link/cut tree)
```cpp
class LinkCutTree {
private:
    struct Node {
        int l, r, p, sz;
        Node() : l(0), r(0), p(0), sz(0) {}
    };
    
    vector<Node> tree;
    
    bool isRoot(int cur) {
        return (!tree[cur].p || (tree[tree[cur].p].l != cur && tree[tree[cur].p].r != cur));
    }
    
    void update(int cur) {
        tree[cur].sz = 1;
        if (tree[cur].l) tree[cur].sz += tree[tree[cur].l].sz;
        if (tree[cur].r) tree[cur].sz += tree[tree[cur].r].sz;
    }
    
    void rotate(int cur) {
        int parent = tree[cur].p;
        int grandParent = tree[parent].p;
        int child;

        // // if constexpr (flippable) propagate(parent);
        // // if constexpr (flippable) propagate(cur);

        if (grandParent) { // grandParent 연결관게 수정
            if (tree[grandParent].l == parent) tree[grandParent].l = cur;
            else if (tree[grandParent].r == parent) tree[grandParent].r = cur; // else로 하면 안 됨. splay tree랑 다르게 parent가 grandParent의 자식이 아닐수도 있으므로 직접 else if로 확인해야 됨
        }

        if (cur == tree[parent].l) { // parent, cur 연결관게 수정
            tree[parent].l = child = tree[cur].r;
            tree[cur].r = parent;
        }
        else {
            tree[parent].r = child = tree[cur].l;
            tree[cur].l = parent;
        }
        tree[parent].p = cur;
        tree[cur].p = grandParent;

        if (child) tree[child].p = parent; // child 연결관게 수정
        
        update(parent);
        update(cur);
    }

    void splay(int cur) {
        for (; !isRoot(cur); rotate(cur)) {
            int parent = tree[cur].p;
            if (!isRoot(parent)) {
                if((cur == tree[parent].l) == (parent == tree[tree[parent].p].l)) rotate(parent); // zig-zig
                else rotate(cur); // zig-zag
            }
        }
    }
    
    int access(int cur) {
        splay(cur);
        tree[cur].r = 0;
        update(cur);

        int res = cur;
        for (; tree[cur].p; splay(cur)) {
            int parent = res = tree[cur].p;
            splay(parent);
            tree[parent].r = cur;
            update(parent);
        }
        return res;
    }

public:
    LinkCutTree(int n) : tree(n + 1) {}

    void link(int cur, int par) { // cur의 부모가 par가 되도록 간선 연결 // cur과 par가 다른 트리에 속해있어야 함 // cur은 실제 트리에서의 루트여야 함
        access(cur);
        access(par);
        tree[cur].l = par;
        tree[par].p = cur;
        update(cur);
    }

    void cut(int cur) { // cur과 cur의 부모 연결하는 간선을 끊음
        access(cur);
        tree[tree[cur].l].p = 0;
        tree[cur].l = 0;
        update(cur);
    }

    int lca(int x, int y) {
        access(x);
        return access(y);
    }
};
```
### 시간복잡도
$amortized~O(logN)$   

### 구현 주의사항
LCT의 구조는 실제 트리와 구조가 다름.   
https://justicehui.github.io/hard-algorithm/2021/01/01/link-cut-tree/ 에서 실제 트리와 해당 트리를 나타내느 LCT 그림을 여럿 보여주니 참고   


### 사용설명


### 문제
[트리와 쿼리 11](https://www.acmicpc.net/problem/13539)   

### 참고링크
https://cubelover.tistory.com/10 - 스플레이 트리(사전지식)   
https://justicehui.github.io/hard-algorithm/2021/01/01/link-cut-tree/ - 링크/컷 트리   
https://imeimi.tistory.com/27 - 링크/컷 트리   