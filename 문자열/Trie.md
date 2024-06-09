[카테고리](/README.md)
### Trie (vector\<T>)
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
### Trie (string)
```cpp
class Trie {
private:
    struct Node {
        map<char, Node *> mp;
        bool end = false;

        ~Node() {
            for (auto &[val, node] : mp) delete node;
        }

        bool have(char val) {
            return mp.find(val) != mp.end();
        }

        Node *go(char val) {
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

    void insert(const string &st) {
        Node *cur = root;
        for (auto &ch : st) cur = cur->go(ch);
        cur->end = true;
    }

    bool find(const string &st) {
        Node *cur = root;
        for (auto &e : st) {
            if (!cur->have(e)) return false;
            cur = cur->go(e);
        }
        return cur->end;
    }
};
```
### 시간복잡도 
insert $O(N)$   
find $O(N)$

### 주의사항
노드에 end를 통해서 단어의 끝까지 도달했는지 저장할 필요가 있다.   
그렇지 않으면 find()함수에서 트라이에 속한 단어의 일부(정확히는 접두사)만 들어가도 true로 잘못 판별된다.   
ex) "apple"만 집어넣었는데 "a", "ap", ... 등이 전부 true

### 사용관련
단어의 접두사 전부 검색하려면 아래 코드 사용   
ex) "apple", "app" 있을 때 "apples" 넣으면 vector{2, 4} 리턴
```cpp
vector<int> find(const string &st) {
    vector<int> res;

    Node *cur = root;
    for (int i = 0; i < st.size() ; i++) {
        auto e = st[i];
        if (!cur->have(e)) break;
        cur = cur->go(e);
        if (cur->end) res.push_back(i);
    }

    return res;
}
```

### 백준문제
[개미굴](https://www.acmicpc.net/problem/14725)