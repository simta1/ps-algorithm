[카테고리](/README.md)
### Palindromic Tree (eertree) - time $O(N~log \sigma)$, space $O(N)$
```cpp
class PalindromicTree {
private:
    struct Node {
        map<char, int> edge;
        int len, link; // suffix link
        int cnt, lazy;

        Node() {}
        Node(int len, int link) : len(len), link(link), cnt(0), lazy(0) {}

        bool haveEdge(char c) {
            return edge.find(c) != edge.end();
        }
    };

    void propagate(int node) {
        tree[node].cnt += tree[node].lazy;
        tree[tree[node].link].lazy += tree[node].lazy;
        tree[node].lazy = 0;
    }

    int newNode(int len, int link) {
        tree.push_back(Node(len, link));
        return tree.size() - 1;
    }

    vector<Node > tree;
    string st;
    int last; // longest suffix palindrome of st

    bool canAttach(int node, char c) {
        if (tree[node].len == -1) return true;

        int idx = st.size() - 1 - tree[node].len;
        return idx >= 0 && st[idx] == c;
    }
    
    void insert(char c) {
        int cur = last;

        while (!canAttach(cur, c)) cur = tree[cur].link;

        if (!tree[cur].haveEdge(c)) {
            if (tree[cur].len == -1) tree[cur].edge[c] = newNode(tree[cur].len + 2, 2);
            else {
                int tmp = cur;
                do { tmp = tree[tmp].link; } while (!canAttach(tmp, c));
                tree[cur].edge[c] = newNode(tree[cur].len + 2, tree[tmp].edge[c]);
            }
        }

        last = tree[cur].edge[c];
        ++tree[last].lazy;
        
        st += c;
    }

    void print(int cur, string palindrome) {
        cout << "tree[" << cur << "] = \"" << palindrome << "\" (len : " <<  tree[cur].len <<  ", cnt : " << tree[cur].cnt << ")\n";
        
        for (auto [ch, next] : tree[cur].edge) {
            if (tree[cur].len == -1) print(next, string(1, ch));
            else print(next, ch + palindrome + ch);
        }
    }

public:
    PalindromicTree() : PalindromicTree("") {}
    PalindromicTree(string st) : tree(3) {
        tree[1] = Node(-1, 1);
        tree[2] = Node(0, 1);
        last = 2;

        for (auto &c : st) insert(c);
    }

    void propagate() {
        vector<int> suffixLinkIndegree(tree.size());

        for (int i = 3; i < tree.size(); i++) suffixLinkIndegree[tree[i].link]++;

        queue<int> q;
        for (int i = 3; i < tree.size(); i++) {
            if (suffixLinkIndegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (!tree[cur].lazy) continue;

            propagate(cur);
            int next = tree[cur].link;
            if (--suffixLinkIndegree[next] == 0) q.push(next);
        }
    }

    void print() {
        print(1, "");
        print(2, "");
    }
};
```
### Palindromic Tree (eertree) - time $O(N)$, space $O(26N)$
```cpp
class PalindromicTree {
private:
    struct Node {
        array<int, 26> edge;
        int len, link; // suffix link
        int cnt, lazy;

        Node() {}
        Node(int len, int link) : edge({}), len(len), link(link), cnt(0), lazy(0) {}

        bool haveEdge(char c) {
            return edge[c - 'a'];
        }
    };

    void propagate(int node) {
        tree[node].cnt += tree[node].lazy;
        tree[tree[node].link].lazy += tree[node].lazy;
        tree[node].lazy = 0;
    }

    int newNode(int len, int link) {
        tree.push_back(Node(len, link));
        return tree.size() - 1;
    }

    vector<Node > tree;
    string st;
    int last; // longest suffix palindrome of st

    bool canAttach(int node, char c) {
        if (tree[node].len == -1) return true;

        int idx = st.size() - 1 - tree[node].len;
        return idx >= 0 && st[idx] == c;
    }
    
    void insert(char c) {
        int cur = last;

        while (!canAttach(cur, c)) cur = tree[cur].link;

        if (!tree[cur].haveEdge(c)) {
            if (tree[cur].len == -1) tree[cur].edge[c - 'a'] = newNode(tree[cur].len + 2, 2);
            else {
                int tmp = cur;
                do { tmp = tree[tmp].link; } while (!canAttach(tmp, c));
                tree[cur].edge[c - 'a'] = newNode(tree[cur].len + 2, tree[tmp].edge[c - 'a']);
            }
        }

        last = tree[cur].edge[c - 'a'];
        ++tree[last].lazy;
        
        st += c;
    }

public:
    PalindromicTree() : PalindromicTree("") {}
    PalindromicTree(string st) : tree(3) {
        tree[1] = Node(-1, 1);
        tree[2] = Node(0, 1);
        last = 2;

        for (auto &c : st) insert(c);
    }

    void propagate() {
        vector<int> suffixLinkIndegree(tree.size());

        for (int i = 3; i < tree.size(); i++) suffixLinkIndegree[tree[i].link]++;

        queue<int> q;
        for (int i = 3; i < tree.size(); i++) {
            if (suffixLinkIndegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (!tree[cur].lazy) continue;

            propagate(cur);
            int next = tree[cur].link;
            if (--suffixLinkIndegree[next] == 0) q.push(next);
        }
    }

    ll solve() {
        propagate();
        
        ll res = 0;
        for (int i = 3; i < tree.size(); i++) if (tree[i].len > 0) res = max(res, ll(tree[i].len) * tree[i].cnt);
        return res;
    }
};
```
### Joint Palindromic Tree - time $O(N)$, space $O(N~I)$
```cpp
template <int N>
class JointPalindromicTree {
private:
    struct Node {
        map<char, int> edge;
        int len, link; // suffix link
        bitset<N> bs;

        Node() {}
        Node(int len, int link) : len(len), link(link) {}

        bool haveEdge(char c) {
            return edge.find(c) != edge.end();
        }

        bool isCommon(int n) {
            return bs.count() == n;
        }
    };

    int newNode(int len, int link) {
        tree.push_back(Node(len, link));
        return tree.size() - 1;
    }

    vector<Node > tree;
    vector<string> strings;
    int last; // longest suffix palindrome of st

    bool canAttach(int node, char c) {
        if (tree[node].len == -1) return true;

        int idx = strings.back().size() - 1 - tree[node].len;
        return idx >= 0 && strings.back()[idx] == c;
    }
    
    void insert(char c) {
        int cur = last;

        while (!canAttach(cur, c)) cur = tree[cur].link;

        if (!tree[cur].haveEdge(c)) {
            if (tree[cur].len == -1) tree[cur].edge[c] = newNode(tree[cur].len + 2, 2);
            else {
                int tmp = cur;
                do { tmp = tree[tmp].link; } while (!canAttach(tmp, c));
                tree[cur].edge[c] = newNode(tree[cur].len + 2, tree[tmp].edge[c]);
            }
        }

        last = tree[cur].edge[c];
        tree[last].bs[strings.size() - 1] = 1;
        
        strings.back() += c;
    }

    void print(int cur, string palindrome) {
        cout << "tree[" << cur << "] = \"" << palindrome << "\" (len : " <<  tree[cur].len <<  ")\n";
        
        for (auto [ch, next] : tree[cur].edge) {
            if (tree[cur].len == -1) print(next, string(1, ch));
            else print(next, ch + palindrome + ch);
        }
    }

    int lcpLen(int cur) {
        int res = tree[cur].len;
        for (auto [_, next] : tree[cur].edge) if (tree[next].isCommon(strings.size())) {
            res = max(res, lcpLen(next));
        }
        return res;
    }

public:
    JointPalindromicTree() : tree(3) {
        tree[1] = Node(-1, 1);
        tree[2] = Node(0, 1);
    }

    void insert(const string &st) {
        last = 2;
        strings.push_back("");
        for (auto &c : st) insert(c);
    }

    void print() {
        print(1, "");
        print(2, "");
    }

    int lcpLen() { // length of longest palindrome common to all strings
        return max(lcpLen(1), lcpLen(2));
    }
};
```
### 시간, 공간복잡도
구현1) time $O(N~log \sigma)$, space $O(N)$   
구현2) time $O(N)$, space $O(N \sigma)$   
$\sigma$는 문자열에 사용되는 문자 종류의 수   
구현 2의 경우 소문자 알파벳만 있을 때를 가정하여 $\sigma = 26$으로 구현했음   

Joint Tree) time $O(N)$, space $O(N~I)$   
$I$는 트리에 넣을 문자열의 개수   

### 구현설명
tree[0]은 혹시나 존재하지 않는 간선(edge[c] == 0)에 들어가게 될 때를 대비해 만들어놓은 더미   
tree[node].cnt의 효율적인 계산을 위해 lazy propagation 사용   
public propagate()함수에서는 suffix link를 기준으로 위상정렬하여 lazy를 전파   

각 노드의 cnt는 suffix link의 역방향 간선들로 트리를 만들었을 때 해당 노드를 부모로 하는 하위 트리의 노드 개수와 동일하기 때문에 suffix link의 역방향 간선을 adj에 저장하고 dfs로 각 노드의 cnt를 계산하는 방식으로도 구현 가능   

Joint Tree는 tree[node].bitset[i]에 i번째 문자열이 해당 노드를 만들 수 있는지 여부를 저장   

Joint Palindromic Tree에서 lcpLen() 함수는 time $O(N~I)$로 구현했다.    
bitset<$I$>.count()이 $O(1)$인 줄 알았는데 $O(I)$였다.   
그냥 모든 문자열에 공통인지만 알아도 되는 상황이면 굳이 bitset으로 모든 I개 문자열에 대한 정보를 저장할 필요없이 int형 변수 하나만 사용해서 time $O(N)$, space $O(N)$으로 구현 가능하다.   
```cpp
// void insert(char c) 코드
    // I개 전부 저장
    tree[last].bs[strings.size() - 1] = 1;

    // int 하나만 사용
    tree[last].firstZeroIdx = strings.size();

// bool isCommon(int n) 코드
    // I개 전부 저장
    return bs.count() == n;

    // int 하나만 사용
    return firstZeroIdx == n;
```

### 사용관련
그래프 순회할 때 traversal(1), traversal(2) 두 개의 루트에 대해 모두 순회   
tree[1].edge에 tree[2]를 연결해서 루트를 하나로 만드는 구현도 있지만, 이 경우 간선에 어떤 문자를 할당할지 애매해서 그냥 루트 2개로 구현했음   

구현1의 경우 print()함수도 만들어둠. 그냥 트리구조 확인하는 용   

tree[node].cnt 사용하려면 미리 public propagate()부터 호출   
propagate() 시간복잡도는 $O(N)$   

Joint Tree로 문자열 여럿에 공통으로 포함된 팰린드롬에 대한 쿼리를 다룰 수 있음   

### 백준문제
[팰린드롬](https://www.acmicpc.net/problem/10066)   
[가장 긴 공통부분 팰린드롬](https://www.acmicpc.net/problem/15893) - Joint Palincromic Tree   

### 참고문헌
https://algoshitpo.github.io/2020/03/23/eertree/   
https://etyu39.tistory.com/4   
https://koosaga.com/249   
https://en.wikipedia.org/wiki/Palindrome_tree   