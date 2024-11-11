[카테고리](/README.md)
## Splay Tree
```cpp
template <typename T>
class SplayTree {
private:
    struct Data {
        T val;
        assert(false, "추가 변수 선언");
        // ex) T mn, mx, sum;

        Data() {}
        Data(ll val) : val(val) {}

        void init() {
            assert(false, "추가 변수 초기화");
            // ex) mn = mx = sum = val;
        }

        void merge(const Data &other) {
            assert(false, "추가 변수 merge");
            // ex)
            // mn = min(mn, other.mn);
            // mx = max(mx, other.mx);
            // sum += other.sum;
        }
    };

    struct Node {
        Data data;

        int l, r, p, sz; // l, r, p는 왼쪽자식, 오른쪽자식, 부모의 주소(인덱스), sz는 서브트리의 사이즈
        // int key; // insert, delete, find
        bool flipLazy, dummy;

        Node() :  l(0), r(0), p(0), sz(1), flipLazy(false), dummy(false) {}
        Node(int val, int p, bool dummy) : l(0), r(0), p(p), sz(1), flipLazy(false), dummy(dummy), data(val) {}
    };

    int root;
    vector<Node> tree;

    int newNode(int val, int p, bool dummy) {
        tree.push_back(Node(val, p, dummy));
        return tree.size() - 1;
    }

    void update(int cur) {
        tree[cur].sz = 1;
        if (tree[cur].l) tree[cur].sz += tree[tree[cur].l].sz;
        if (tree[cur].r) tree[cur].sz += tree[tree[cur].r].sz;

        // merge data
        tree[cur].data.init();
        if (tree[cur].l && !tree[tree[cur].l].dummy) tree[cur].data.merge(tree[tree[cur].l].data);
        if (tree[cur].r && !tree[tree[cur].r].dummy) tree[cur].data.merge(tree[tree[cur].r].data);
    }

    void propagate(int cur) {
        if (!tree[cur].flipLazy) return;

        swap(tree[cur].l, tree[cur].r);
        if (tree[cur].l) tree[tree[cur].l].flipLazy ^= 1;
        if (tree[cur].r) tree[tree[cur].r].flipLazy ^= 1;
        tree[cur].flipLazy = false;
    }

    void rotate(int cur) {
        if (!tree[cur].p) return;

        int parent = tree[cur].p;
        int grandParent = tree[parent].p;
        int child;

        propagate(parent);
        propagate(cur);

        if (!grandParent) root = cur; // grandParent 연결관게 수정
        else if (tree[grandParent].l == parent) tree[grandParent].l = cur;
        else tree[grandParent].r = cur;

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
        while (tree[cur].p) {
            int parent = tree[cur].p;
            int grandParent = tree[parent].p;
            
            if (grandParent) {
                if((cur == tree[parent].l) == (parent == tree[grandParent].l)) rotate(parent); // zig-zig
                else rotate(cur); // zig-zag
            }
            rotate(cur);
        }
    }

    int kth(int k) { // 1-based // 사실은 0-based지만 0번째 노드가 left dummy라서 사용자 입장에선 1-based임
        int cur = root;
        propagate(cur);

        while (1) {
            while (tree[cur].l && k < tree[tree[cur].l].sz) {
                cur = tree[cur].l;
                propagate(cur);
            }
            if (tree[cur].l) k -= tree[tree[cur].l].sz;
            if (!k--) break;
            cur = tree[cur].r;
            propagate(cur);
        }
        splay(cur);
        return root;
    }

    int gather(int l, int r) { // 1-based
        kth(l - 1);
        int originRoot = root;
        root = tree[root].r;
        tree[root].p = 0;

        kth(r - l + 1);
        tree[root].p = originRoot;
        tree[originRoot].r = root;
        root = originRoot;

        return tree[tree[root].r].l;
    }

    void inorder(int cur) {
        propagate(cur);
        if (tree[cur].l) inorder(tree[cur].l);
        if (!tree[cur].dummy) cout << tree[cur].data.val << " ";
        if (tree[cur].r) inorder(tree[cur].r);
    }

public:
    SplayTree(const vector<T> &v) { // v는 0-based로 받음
        tree.reserve(v.size() + 3);
        newNode(0, 0, true); // dummy // tree배열을 1-based로 만들기 위함

        root = newNode(0, 0, true); // left dummy

        int cur = root; // real nodes
        for (int i = 0; i < v.size(); i++) {
            tree[cur].r = newNode(v[i], cur, false);
            cur = tree[cur].r;
        }
        
        tree[cur].r = newNode(0, cur, true); // right dummy

        for (cur = tree[cur].r; cur; cur = tree[cur].p) update(cur); // init
    }

    void flip(int l, int r) { // 1-based
        tree[gather(l, r)].flipLazy ^= 1;
    }
    
    void shift(int l, int r, int k) { // 1-based // 오른쪽으로 k칸만큼 shift // 1, 2, ..., l-1 / r-k+1, ..., r-1, r, l, l+1, ..., r-k / r+1, ..., n
        int length = r - l + 1;
        k %= length;
        if (!k) return;

        int num = (k > 0) ? k : (length + k); // length - abs(k)

        flip(l, r);
        flip(l, l + num - 1);
        flip(l + num, r);
    }

    Data query(int l, int r) { return tree[gather(l, r)].data; } // 1-based

    int getIdx(int x) { // https://www.acmicpc.net/problem/13159 // query 4
        splay(x + 1);
        return tree[tree[x + 1].l].sz; // 1-based로 리턴
    }

    void print() {
        inorder(root);
        cout << "\n";
    }
};
```
### 시간복잡도 
$amortized~O(logN)$   

### 구현설명
rotate 전 `propagate()`와 rotate 후 `update()`는 필수   
`rotate(x)`함수에서 연결관계(`l, r, p`)가 바뀌는 노드는 x, x의 자식, x의 부모, x의 조부모 4가지임   
`int parent, grandParent, child, cur`는 const가 붙어있다고 생각하고 구현하면 편함. 실제로 붙일까 싶었는데 child는 선언만 미리 하고 값을 나중에 넣기 때문에 const를 쓰진 않았음   
```cpp
void rotate(int cur) {
    if (!tree[cur].p) return;

    int parent = tree[cur].p;
    int grandParent = tree[parent].p;
    int child;

    propagate(parent);
    propagate(cur);

    if (!grandParent) root = cur; // grandParent 연결관게 수정
    else if (tree[grandParent].l == parent) tree[grandParent].l = cur;
    else tree[grandParent].r = cur;

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
```

left dummy, right dummy는 gather()함수를 쉽게 구현하기 위한 더미임   

### 사용설명
매번 상황에 맞게 Data구조체의 `assert(false)` 부분 코드만 작성해서 사용   

`rotate(x)`는 x를 x의 부모노드 위치로 올림   
`splay(x)`는 rotate를 적절히 사용해 x를 루트로 옮김   
스플레이 트리의 모든 연산에서 트리의 inorder 순서는 유지됨   

dummy노드 만들 때 굳이 항등원 넣으려 고민할 필요 없음. 애초에 update()함수에서 dummy아닌 것들만 합치게 해둠  

어떤 노드의 정보를 읽고 싶다면 splay 후에 사용하는 게 안전함   
splay하지 않고 tree배열에 바로 접근할 경우 flipLazy가 남아있으면 이상한 값이 얻어짐   
splay를 호출하면 내부에서 `propagate()`가 실행되므로 안전함

```cpp
cout << tree[tree[x].l].sz; // 이상한 값 계산될 수 있음

splay(x);
cout << tree[tree[root].l].sz; // 안전
```

### 문제
[배열](https://www.acmicpc.net/problem/13159)

### 참고링크
https://cubelover.tistory.com/10   
https://blog.chodaeho.com/posts/2021/splay-tree-1/   
https://justicehui.github.io/hard-algorithm/2018/11/12/SplayTree1/   