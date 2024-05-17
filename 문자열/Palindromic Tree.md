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
        int len = tree[cur].len;

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

    ll solve(int cur) {
        ll res = ll(tree[cur].len > 0) * tree[cur].len * tree[cur].cnt;
        for (auto [_, next] : tree[cur].edge) res = max(res, solve(next));
        return res;
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
### Palindromic Tree ( = eertree ) - time $O(N)$, space $O(26N)$
```cpp

```
### 시간, 공간복잡도
구현1) time $O(N~log \sigma)$, space $O(N)$   
구현2) time $O(N)$, space $O(N \sigma)$   
$\sigma$는 문자열에 사용되는 문자 종류의 수   
구현 2의 경우 소문자 알파벳만 있을 때를 가정하여 $\sigma = 26$으로 구현했음

### 구현설명
tree[0]은 혹시나 존재하지 않는 엣지(edge[c] == 0)에 들어가게 될 때를 대비해서 만들어놓은 더미   
tree[node].cnt의 효율적인 계산을 위해서 lazy propagation 사용했음   
public propagate()함수에서는 suffix link를 기준으로 위상정렬하여 lazy를 전파   

각 노드의 cnt는 suffix link의 역방향 간선들로 트리를 만들었을 때 해당 노드를 부모로 하는 하위 트리의 노드 개수와 동일하기 때문에 suffix link의 역방향 간선을 adj에 저장하고 dfs로 각 노드에의 cnt를 계산하는 식으로도 구현 가능   

### 사용관련
그래프 순회할 때 traversal(1), traversal(2)로 두 개의 루트에 대해 모두 봐야 됨   
원래 구현은 tree[1].edge에 tree[2]를 연결해줘서 루트를 하나로 만들지만 이러면 간선에 어떤 문자를 할당할지 애매해서 그냥 루트 2개로 쓸 생각   

print()함수는 그냥 디버깅할 때 쓰려고 만들어둠   

당연히 tree[node].cnt사용할 거면 사용하기 전에 미리 public propagate() 한 번 실행해줘야 됨   
propagate() 시간복잡도는 $O(N)$   

### 백준문제
[팰린드롬](https://www.acmicpc.net/problem/10066)

### 참고문헌
https://algoshitpo.github.io/2020/03/23/eertree/
https://etyu39.tistory.com/4
https://koosaga.com/249