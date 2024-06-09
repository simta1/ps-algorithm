[카테고리](/README.md)
### Aho-Corasick (map 구현)
```cpp
class AhoCorasickTrie {
private:
    struct Node {
        map<char, Node *> mp;
        Node *fail;
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
    AhoCorasickTrie() : root(new Node()) {}
    ~AhoCorasickTrie() { delete root; }

    void insert(const string &st) {
        Node *cur = root;
        for (auto &ch : st) cur = cur->go(ch);
        cur->end = true;
    }

    void makeFailFunction() {
        root->fail = root;

        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            Node *cur = q.front();
            q.pop();

            for (auto [val, next] : cur->mp) {
                if (cur == root) next->fail = root;
                else {
                    Node *dest = cur->fail;

                    while (dest != root && !dest->have(val)) dest = dest->fail;
                    if (dest->have(val)) dest = dest->go(val);
                    next->fail = dest;
                }

                next->end |= next->fail->end;
                q.push(next);
            }
        }
    }

    bool findSubstring(const string &st) {
        Node *cur = root;
        for (auto &e : st) {
            while (cur != root && !cur->have(e)) cur = cur->fail;
            if (cur->have(e)) cur = cur->go(e);
            if (cur->end) return true;
        }
        return false;
    }
};
```
### Aho-Corasick (array 구현, 소문자 알파벳 전용)
```cpp
class AhoCorasickTrie {
private:
    struct Node {
        array<Node *, 26> mp;
        Node *fail;
        bool end = false;

        Node() {
            mp.fill(nullptr);
        }

        ~Node() {
            for (auto &node : mp) delete node;
        }

        bool have(char val) {
            return mp[val - 'a'];
        }

        Node *go(char val) {
            if (!have(val)) {
                Node *node = new Node;
                mp[val - 'a'] = node;
            }

            return mp[val - 'a'];
        }
    } *root;

public:
    AhoCorasickTrie() : root(new Node()) {}
    ~AhoCorasickTrie() { delete root; }

    void insert(const string &st) {
        Node *cur = root;
        for (auto &ch : st) cur = cur->go(ch);
        cur->end = true;
    }

    void makeFailFunction() {
        root->fail = root;

        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            Node *cur = q.front();
            q.pop();

            for (int i = 0; i < 26; i++) {
                auto next = cur->mp[i];
                if (!next) continue;

                if (cur == root) next->fail = root;
                else {
                    Node *dest = cur->fail;

                    while (dest != root && !dest->have(i + 'a')) dest = dest->fail;
                    if (dest->have(i + 'a')) dest = dest->go(i + 'a');
                    next->fail = dest;
                }

                next->end |= next->fail->end;
                q.push(next);
            }
        }
    }

    bool findSubstring(const string &st) {
        Node *cur = root;
        for (auto &e : st) {
            while (cur != root && !cur->have(e)) cur = cur->fail;
            if (cur->have(e)) cur = cur->go(e);
            if (cur->end) return true;
        }
        return false;
    }
};
```
### 시간복잡도 
길이 $m_1, m_2, \cdots , m_k$의 단어들을 길이 $n$의 문자열에서 검색할 때   
makeFailFunction $O(\sum m_i)$   
findSubstring $O(N + z)$   
z는 단어들이 문자열에서 나타나는 횟수   

1번째 구현의 경우 map을 사용해서 트라이를 구현하므로 시간복잡도에 약 $log \sigma$가 곱해짐   

### 구현설명
[트라이](/문자열/Trie.md)에서 바뀐 점은 3가지   
struct Node의 내부에 fail변수 추가   
AhoCorasickTrie::makeFailFunction()함수 추가   
AhoCorasickTrie::find()함수 변경   

### 주의사항
소멸자 ~Node()에서 delete fail;하면 안 됨   
go방향으로 순서대로 delete하면 어차피 전부다 삭제되는데 중간에 delete fail; 넣으면 순서 엉킴   

### 사용관련
findSubstring() 사용하기 전에 무조건 makeFailFunction()먼저 호출 후 사용   

1번째 구현은 문자 종류없이 항상 사용 가능하고 메모리도 적게 쓰지만 속도가 살짝 느림   
2번째 구현의 경우 map 대신 배열을 사용하므로 속도는 더 빠르지만 문자의 종류가 알파벳 소문자만 있을 때로 제한 됨.   
알파벳 대문자만 있는 경우는 코드에서 직접 'a'부분을 전부 'A'로 바꿔서 사용   
'A'로 바꾼 코드도 추가할까 싶었는데 너무 필요없는 내용으로 문서가 길어지게 될 것 같아 vim매크로로 대체   
ggqq/'a'{Enter}l~q5@q   

### 백준문제
[문자열 집합 판별](https://www.acmicpc.net/problem/9250)   

### 참고문헌
https://m.blog.naver.com/kks227/220992598966
https://www.geeksforgeeks.org/aho-corasick-algorithm-pattern-searching/   