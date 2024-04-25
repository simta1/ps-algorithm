### splay
```cpp
// 참고한 코드
// https://seastar105.tistory.com/59
// https://justicehui.github.io/hard-algorithm/2019/10/23/SplayTree4/
// https://cubelover.tistory.com/10

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SplayTree {
private:
    struct Node {
        Node *l, *r, *p;
        int sz;
        bool flip;
        // int key;
        T val, ans[11];

        Node() : l(nullptr), r(nullptr), p(nullptr), sz(1), flip(false) {};
        Node(T val) : Node(), val(val) {
            for (int i = 0; i < 11; i++) ans[i] = val;
        }
        Node(T val, Node *p) : Node(val), p(p) {}
    } *root;

    // void insert(int key) {
    //     Node *x = new Node;
    //     x->l = x->r = x->p = NULL;
    //     x->key = key;

    //     if (!root) {
    //         root = x;
    //         return;
    //     }
        
    //     Node *cur = root;

    //     while (1) {
    //         if(key == cur->key) { // 중복
    //             delete x;
    //             return;
    //         }

    //         if(key < cur->key) {
    //             if (cur->l) cur = cur->l;
    //             else {
    //                 x->p = cur;
    //                 cur->l = x;
    //                 splay(x);
    //                 return;
    //             }
    //         }
    //         else{
    //             if (cur->r) cur = cur->r;
    //             else {
    //                 x->p = cur;
    //                 cur->r = x;
    //                 splay(x);
    //                 return;
    //             }
    //         }
    //     }
    // }

    // bool find(int key) {
    //     if (!root) return false;

    //     Node *cur = root;

    //     while (cur && key != cur->key) {
    //         Node *next = (key < cur->key ? cur->l : cur->r);
    //         if (!next) break;
    //         cur = next;
    //     }

    //     splay(cur);
    //     return key == cur->key;
    // }

    // void remove(int key) {
    //     if (!find(key)) return;

    //     Node *originRoot = root;
    //     if (root->l && root->r) {
    //         root = root->l;
    //         root->p = NULL;
    //         Node *cur = root;
    //         while (cur->r) cur = cur->r;
    //         cur->r = originRoot->r;
    //         originRoot->r->p = cur;
    //         splay(cur);
    //     }
    //     else if (root->l) {
    //         root = root->l;
    //         root->p = NULL;
    //     }
    //     else if (root->r) {
    //         root = originRoot->r;
    //         root->p = NULL;
    //     }
    //     else {
    //         root = NULL;
    //     }

    //     delete originRoot;
    // }

    void update(Node *cur) {
        cur->sz = 1;
        if (cur->l) cur->sz += cur->l->sz;
        if (cur->r) cur->sz += cur->r->sz;
    }

    void lazy(Node *cur) {
        if (!cur->flip) return;

        swap(cur->l, cur->r);
        if (cur->l) cur->l->flip = !cur->l->flip;
        if (cur->r) cur->r->flip = !cur->r->flip;
        cur->flip = false;
    }

    void rotate(Node *cur) {
        if (!cur->p) return;

        Node *parent = cur->p;
        Node *child;

        // 있어야 되나? 일단 주석상태로 제출해보고 통과되면 삭제할지 고민
        // lazy(parent);
        // lazy(cur);

        if (cur == parent->l) {
            parent->l = child = cur->r;
            cur->r = parent;
        }
        else {
            parent->r = child = cur->l;
            cur->l = parent;
        }

        if (child) child->p = parent;

        Node *grandParent = parent->p;
        cur->p = grandParent;
        parent->p = cur;

        if (!grandParent) root = cur;
        else if (grandParent->l == parent) grandParent->l = cur;
        else grandParent->r = cur;

        update(parent);
        update(cur);
    }

    void splay(Node *cur) {
        while (cur->p) {
            Node *parent = cur->p;
            Node *grandParent = parent->p;
            
            if (grandParent) {
                if((cur == parent->l) == (parent == grandParent->l)) rotate(parent); // zig-zig
                else rotate(cur); // zig-zag
            }
            rotate(cur);
        }
    }

    // split
    // merge

    void splayKth(int k) { // 1-based
        Node *cur = root;
        // 있어야 되나? 일단 주석상태로 제출해보고 통과되면 삭제할지 고민 2
        // lazy(cur); 
        while (1) {
            while (cur->l && k < cur->l->sz) {
                cur = cur->l;
                lazy(cur);
            }
            if (cur->l) k -= cur->l->sz;
            if (!k--) break;
            cur = cur->r;
            lazy(cur);
        }
        splay(cur);
    }

    Node* gather(int l, int r) {
        splayKth(l - 1);
        Node *originRoot = root;
        root = root->r;
        root->p = nullptr;

        splayKth(r - l + 1);
        originRoot->r = root;
        root->p = originRoot;
        root = originRoot;

        return root->r->l;
    }

public:
    SplayTree(const vector<T> &v) { // 0 : left dummy, 1 ~ n : element, n+1 : right dummy
        // left dummy
        root = new Node(0);

        // real nodes
        Node *cur = root;
        for (int i = 0; i < n; i++) {
            cur->r = new Node(v[i], cur);
            cur = cur->r;
        }
        
        // right dummy
        cur->r = new Node(0, cur);
        cur = cur->r;

        // update sz
        while (cur) {
            update(cur);
            cur = cur->p;
        }
    }

    // void reverse(int l, int r) {
    //     Node *x = gather(l, r);
    //     x->flip = !x->flip;
    // }

    void insertBeforeKth(int k, T val) { // 1-based
        splayKth(k);
        Node *cur = root->l;
        while (cur->r) cur = cur->r;
        cur->r = new Node(val, cur);
        splay(cur->r);
    }

    void removeKth(int k) { // 1-based
        splayKth(k);

        Node *originRoot = root;
        if (root->l && root->r) {
            root = root->l;
            root->p = NULL;
            Node *cur = root;
            while (cur->r) cur = cur->r;
            cur->r = originRoot->r;
            originRoot->r->p = cur;
            splay(cur);
        }
        else if (root->l) {
            root = root->l;
            root->p = NULL;
        }
        else if (root->r) {
            root = originRoot->r;
            root->p = NULL;
        }
        else {
            root = NULL;
        }

        delete originRoot;
    }

    void changeKth(int k, T val) { // 1-based
        splayKth(k);
        root->val = val;
        update(root);
        return root;
    }

    T query(int l, int r, int k) { // 1-based
        return gather(l, r)->ans[k];
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<long long> v(n);
    for (auto &e : v) cin >> e;

    SplayTree<long long> spl(v);

    int m;
    for (cin >> m; m--;) {
        int a;
        cin >> a;

        if (a == 1) {
            long long idx, val;
            cin >> idx >> val;
            spl.insertBeforeKth(idx + 1, val);
        }
        else if (a == 2) {
            int idx;
            cin >> idx;
            spl.removeKth(idx + 1);
        }
        else if (a == 3) {
            long long idx, val;
            cin >> idx >> val;
            spl.changeKth(idx + 1, val);
        }
        else {
            int l, r, k;
            cin >> l >> r >> k;
            cout << spl.query(l + 1, r + 1, k) << "\n";
        }
    }

    return 0;
}
```
