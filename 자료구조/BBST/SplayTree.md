### splay
```cpp
template <typename T>
class SplayTree {
private:
    struct Data {
        T val, mn, mx, sum;

        Data() {}
        Data(T val) : val(val) { init(); }

        void init() {
            mn = mx = sum = val;
        }

        void merge(const Data &other) {
            mn = min(mn, other.mn);
            mx = max(mx, other.mx);
            sum += other.sum;
        }
    };

    struct Node {
        Node *l, *r, *p;
        int sz;
        bool flipLazy, dummy;
        // int key;

        Data data;

        Node() :  l(nullptr), r(nullptr), p(nullptr), sz(1), flipLazy(false), dummy(false) {}
        Node(int val, Node *p) : l(nullptr), r(nullptr), p(p), sz(1), flipLazy(false), dummy(false), data(val) {}
        ~Node() {
            if (l) delete l;
            if (r) delete r;
        }
    };

    Node *root;
    vector<Node *> ptr;

    void update(Node *cur) {
        cur->sz = 1;
        if (cur->l) cur->sz += cur->l->sz;
        if (cur->r) cur->sz += cur->r->sz;

        // merge data
        cur->data.init();
        if (cur->l && !cur->l->dummy) cur->data.merge(cur->l->data);
        if (cur->r && !cur->r->dummy) cur->data.merge(cur->r->data);
    }

    void lazy(Node *cur) {
        if (!cur->flipLazy) return;

        swap(cur->l, cur->r);
        if (cur->l) cur->l->flipLazy ^= 1;
        if (cur->r) cur->r->flipLazy ^= 1;
        cur->flipLazy = false;
    }

    void rotate(Node *cur) {
        if (!cur->p) return;

        Node *parent = cur->p;
        Node *child;

        lazy(parent);
        lazy(cur);

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

    Node* gather(int l, int r) {
        kth(l - 1);
        Node *originRoot = root;
        root = root->r;
        root->p = nullptr;

        kth(r - l + 1);
        root->p = originRoot;
        originRoot->r = root;
        root = originRoot;

        return root->r->l;
    }

    Node* kth(int k) { // 1-based
        Node *cur = root;
        lazy(cur);

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
        return root;
    }

    void inorder(Node *cur) {
        lazy(cur);
        if (cur->l) inorder(cur->l);
        if (!cur->dummy) cout << cur->data.val << " ";
        if (cur->r) inorder(cur->r);
    }

public:
    SplayTree(const vector<T> &v) : ptr(v.size() + 2) {
        // left dummy
        ptr[0] = root = new Node(0, nullptr);
        root->dummy = true;

        // real nodes
        Node *cur = root;
        for (int i = 0; i < v.size(); i++) {
            ptr[i + 1] = cur->r = new Node(v[i], cur);
            cur = cur->r;
        }
        
        // right dummy
        ptr[v.size() + 1] = cur->r = new Node(0, cur);
        cur->r->dummy = true;

        // init
        for (cur = cur->r; cur; cur = cur->p) update(cur);
    }

    ~SplayTree() {
        if (root) delete root;
    }

    void flip(int l, int r) {
        gather(l, r)->flipLazy ^= 1;
    }

    void shift(int l, int r, int k) {
        int length = r - l + 1;
        k %= length;
        if (!k) return;

        gather(l, r);
        int num = (k > 0) ? k : (length + k); // length - abs(k)

        flip(l, r);
        flip(l, l + num - 1);
        flip(l + num, r);
    }

    Data query(int l, int r) { // 1-based
        return gather(l, r)->data;
    }

    Data query(int idx) { // 1-based
        return kth(idx)->data;
    }

    int getIdx(int x) { // 1-based
        splay(ptr[x]);
        return root->l->sz;
    }

    void print() {
        inorder(root);
        cout << "\n";
    }
};
```
