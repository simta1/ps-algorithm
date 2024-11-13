[카테고리](/README.md)
## Splay Tree
```cpp
template <bool flippable, typename T>
class SplayTree {
private:
    struct Data {
        T val;
        assert(false, "추가 변수 선언");
        // ex) T sum;

        Data() {}
        Data(T val) : val(val) {}
        void setVal(T val) { this->val = val; } // changeKth에서 사용

        void init() {
            assert(false, "추가 변수 초기화");
            // ex) sum = val;
        }

        void initDummy() {
            assert(false, "추가 변수 초기화(dummy이므로 항등원으로 초기화해야 함)");
            // ex) sum = 0;
            /*  이유는 모르겠지만 initDummy()함수 비어놔도 잘 작동함
                실제로 디버깅해보니 dummy가 중간에 끼면서 루트쪽 노드에 정확한 값이 계산되지 못하는 경우가 있긴 하지만,
                query()함수로 값을 읽을 때는 gather() 범위 내에는 dummy가 없어서인지 값이 잘 계산됨
                BBST특성상 항상 이럴수밖에 없는건지, 아니면 반례가 존재하지만 내가 아직 겪지 못한 것인지는 모르겠지만
                아직까진 initDummy()를 비어놔도 틀린 문제 없음. 그래도 혹시모르니 일단 initDummy작성하는 게 나을 듯
                항등원 애매하거나 쓰기 귀찮을 땐 그냥 비어둔 채로 제출해보고 proof by AC 노려볼만 한 듯 */
        }

        void merge(const Data &other) {
            assert(false, "추가 변수 merge");
            // ex) sum += other.sum;
        }
    };

    struct Node {
        Data data;

        int l, r, p, sz; // l, r, p는 왼쪽자식, 오른쪽자식, 부모의 주소(인덱스), sz는 서브트리의 사이즈
        bool flipLazy, dummy;

        Node(T val, int p, bool dummy) : l(0), r(0), p(p), sz(1), flipLazy(false), dummy(dummy), data(val) {}
    };

    int root;
    vector<Node> tree;

    int newNode(T val, int p, bool dummy) {
        tree.emplace_back(val, p, dummy);
        return tree.size() - 1;
    }

    void update(int cur) {
        tree[cur].sz = 1;
        if (tree[cur].l) tree[cur].sz += tree[tree[cur].l].sz;
        if (tree[cur].r) tree[cur].sz += tree[tree[cur].r].sz;

        // merge data
        if (!tree[cur].dummy) tree[cur].data.init();
        else tree[cur].data.initDummy();
        if (tree[cur].l) tree[cur].data.merge(tree[tree[cur].l].data);
        if (tree[cur].r) tree[cur].data.merge(tree[tree[cur].r].data);
    }

    void propagate(int cur) { if constexpr (!flippable) assert(false);
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

        if constexpr (flippable) propagate(parent);
        if constexpr (flippable) propagate(cur);

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
        if constexpr (flippable) propagate(cur);

        while (1) {
            while (tree[cur].l && k < tree[tree[cur].l].sz) {
                cur = tree[cur].l;
                if constexpr (flippable) propagate(cur);
            }
            if (tree[cur].l) k -= tree[tree[cur].l].sz;
            if (!k--) break;
            cur = tree[cur].r;
            if constexpr (flippable) propagate(cur);
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
        if constexpr (flippable) propagate(cur);
        if (tree[cur].l) inorder(tree[cur].l);
        if (!tree[cur].dummy) cout << tree[cur].data.val << " ";
        if (tree[cur].r) inorder(tree[cur].r);
    }

public:
    SplayTree(const vector<T> &v, int numberOfQuery=0) { // v는 0-based로 받음
        tree.reserve(v.size() + 3 + numberOfQuery);
        
        newNode(0, 0, true);
        root = newNode(0, 0, true);

        int cur = root;
        for (int i = 0; i < v.size(); i++) cur = tree[cur].r = newNode(v[i], cur, false);

        tree[cur].r = newNode(0, cur, true);

        for (cur = tree[cur].r; cur; cur = tree[cur].p) update(cur);
    }

    void insertBeforeKth(int k, T val) { // 1-based, 1<=k<=n+1
        kth(k);
        int cur = newNode(val, 0, false);

        int leftChild = tree[root].l;
        tree[cur].l = leftChild;
        tree[cur].r = root;

        tree[leftChild].p = cur;
        tree[root].l = 0;
        tree[root].p = cur;

        root = cur;
        update(root);
    }
    
    void changeKth(int k, T val) { // 1-based
        kth(k);
        tree[root].data.setVal(val);
        update(root);
    }
    
    void deleteKth(int k) { // 1-based
        kth(k);

        if (tree[root].l && tree[root].r) {
            int cur = tree[root].l;
            while (tree[cur].r) cur = tree[cur].r;
            tree[tree[cur].r = tree[root].r].p = cur;
            root = tree[root].l;
            tree[root].p = 0;
            splay(cur);
        }
        else {
            root = tree[root].l ? tree[root].l : tree[root].r;
            assert(root); // left dummy, right dummy 있어서 최소한 자식 하나는 존재할 수밖에 없음
            tree[root].p = 0;
        }
    }
    
    T query(int l, int r) { // 1-based
        return tree[gather(l, r)].data.val;
        assert(false, "문제에 맞게 리턴값 바꾸기");
    }

    void flip(int l, int r) { if constexpr (!flippable) assert(false); // 1-based
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

    void inorder() {
        inorder(root);
        cout << "\n";
    }
};
```
### Splay tree에서 이분 탐색
```cpp
public:
    int findMnIdx(int l, int r) { // v[l]~v[r]에서 최솟값 가지는 곳의 인덱스
        int cur = gather(l, r);
        if constexpr (flippable) propagate(cur);

        T target = tree[cur].data.mn;
        
        while (target != tree[cur].data.val) {
            if (tree[cur].l && target == tree[tree[cur].l].data.mn) {
                cur = tree[cur].l;
                if constexpr (flippable) propagate(cur);
            }
            else {
                cur = tree[cur].r;
                if constexpr (flippable) propagate(cur);
            }
        }
        
        splay(cur);
        return tree[tree[root].l].sz;
    }
```
### 시간복잡도 
$amortized~O(logN)$   

### 구현설명
dummy는 총 3개 있음   
tree[]배열을 1-based로 만들기 위해 `tree[0]`에 있는 더미   
`gather()`와 `insertBeforeKth()` 등에서 예외처리를 하지 않기 위해 트리의 양끝단에 추가하는 left dummy, right dummy   

### 사용설명
`SplayTree<bool flippable, typename T>`에서 flippable는 flip연산 사용할 건지의 여부.   
flip을 사용하지 않을 때 false로 설정해주면 불필요한 코드를 `if constexpr`로 걸러내므로 속도개선이 꽤 된다.   
물론 그냥 true로 놓고 사용해도 상관은 없다.   

매번 상황에 맞게 Data구조체의 `assert(false)` 부분 코드만 작성해서 사용   

스플레이 트리의 모든 연산에서 트리의 inorder 순서는 유지됨   

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
[수열과 쿼리 2](https://www.acmicpc.net/problem/13543)   
[Robotic Sort](https://www.acmicpc.net/problem/3444)   

### 참고링크
https://cubelover.tistory.com/10   
https://blog.chodaeho.com/posts/2021/splay-tree-1/   
https://justicehui.github.io/hard-algorithm/2018/11/12/SplayTree1/   