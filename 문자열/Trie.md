[카테고리](/README.md)
### Trie
```cpp
template <typename T>
class Trie {
private:
    struct Node {
        map<T, Node *> mp;
        bool end = false;

        ~Node() {
            for (auto &[val, node] : mp) delete node;
        }

        bool have(T val) {
            return mp.find(val) != mp.end();
        }

        Node *go(T val) {
            if (!have(val)) {
                Node *node = new Node;
                mp[val] = node;
            }

            return mp[val];
        }
    } *root;

    void print(Node *cur, int depth) {
        for (auto &[val, next] : cur->mp) {
            for (int i = 0; i < depth; i++) cout << "-";
            cout << val << "\n";
            print(next, depth + 1);
        }
    }

public:
    Trie() : root(new Node()) {}
    ~Trie() { delete root; }

    void insert(const vector<T> &v) {
        Node *cur = root;
        for (auto &e : v) cur = cur->go(e);
        cur->end = true;
    }

    bool find(const vector<T> &v) {
        Node *cur = root;
        for (auto &e : v) {
            if (!cur->have(e)) return false;
            cur = cur->go(e);
        }
        return cur->end;
    }

    void print() {
        print(root, 0);
    }
};
```
### 시간복잡도 
insert $O(N)$   
find $O(N)$

### 백준문제
[개미굴](https://www.acmicpc.net/problem/14725)