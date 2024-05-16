[카테고리](/README.md)
### Palindromic Tree ( = eertree )
### time $O(N~log \sigma)$, space $O(N)$
```cpp
class PalindromicTree {
private:
    struct Node {
        map<char, int> edge;
        int len, link; // link to suffix
        int cnt;

        Node() {}
        Node(int len, int link) : len(len), link(link), cnt(0) {}
    };

    int newNode(int len, int link) {
        tree.push_back(Node(len, link));
        return tree.size() - 1;
    }

    vector<Node > tree;
    string st;
    int lsp; // longest suffix pelindrome of st

    bool canAttach(int cur, char c) {
        if (tree[cur].len == -1) return true;

        int idx = st.size() - 1 - tree[cur].len;
        return idx >= 0 && st[idx] == c;
    }
    
    void addLetter(char c) {
        int cur = lsp;
        int len = tree[cur].len;

        while (!canAttach(cur, c)) cur = tree[cur].link;

        if (!tree[cur].edge[c]) {
            if (tree[cur].len == -1) tree[cur].edge[c] = newNode(tree[cur].len + 2, 2);
            else {
                int tmp = cur;
                do { tmp = tree[tmp].link; } while (!canAttach(tmp, c));
                tree[cur].edge[c] = newNode(tree[cur].len + 2, tree[tmp].edge[c]);
            }
        }

        lsp = tree[cur].edge[c];
        ++tree[lsp].cnt;

        st += c;
        // if (tree[cur].len == -1) cout << "pushed : \"" << c << "\", parent : " << cur << "(len : " << tree[cur].len << ")" << ", new : " << lsp << "(len : " << tree[lsp].len << ")" << ", suffix : " << tree[lsp].link << "(len : " << tree[tree[lsp].link].len << ")" << "\n";
        // else cout << "pushed : \"" << c << "~" << c << "\", parent : " << cur << "(len : " << tree[cur].len << ")" << ", new : " << lsp << "(len : " << tree[lsp].len << ")" << ", suffix : " << tree[lsp].link << "(len : " << tree[tree[lsp].link].len << ")" << "\n";
    }

    void traversal(int cur, string st) {
        cout << cur << "(len : " << tree[cur].len << ")";
        if (tree[cur].len > 0) cout << " " << st;
        cout << "\n";
        for (auto [ch, next] : tree[cur].edge) {
            if (tree[cur].len == -1) traversal(next, st + ch);
            else traversal(next, ch + st + ch);
        }
    }

public:
    PalindromicTree() : PalindromicTree("") {}
    PalindromicTree(string st) : tree(3) {
        tree[1] = Node(-1, 1);
        tree[2] = Node(0, 1);
        lsp = 2;

        for (auto &c : st) addLetter(c);
    }

    void traversal() {
        traversal(1, "");
        traversal(2, "");
    }
};
```
### time $O(N)$, space $O(26N)$
```cpp

```
### 시간, 공간복잡도
구현1) time $O(N~log \sigma)$, space $O(N)$   
구현2) time $O(N)$, space $O(N \sigma)$   
$\sigma$는 문자열에 사용되는 문자 종류의 수   
구현 2의 경우 소문자 알파벳만 있을 때를 가정하여 $\sigma = 26$으로 구현했음

### 주의사항


### 사용관련


### 백준문제
[]()

### 원리


### 참고문헌
https://algoshitpo.github.io/2020/03/23/eertree/
https://etyu39.tistory.com/4
https://koosaga.com/249