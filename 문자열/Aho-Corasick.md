[카테고리](/README.md)
## Aho-Corasick
### map으로 구현
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

    void print() { print(root, 0); }

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
    
    long long countSubstring(const string &st) {
        Node *cur = root;
        long long cnt = 0;

        for (auto &e : st) {
            while (cur != root && !cur->have(e)) cur = cur->fail;
            if (cur->have(e)) cur = cur->go(e);
            if (cur->end) ++cnt;
        }
        return cnt;
    }
};
```
### array로 구현
```cpp
template <char alphabet, int N>
class AhoCorasickTrie {
private:
    struct Node {
        array<Node *, N> mp;
        Node *fail;
        bool end = false;

        Node() {
            mp.fill(nullptr);
        }

        ~Node() {
            for (auto &node : mp) delete node;
        }

        bool have(char val) {
            return mp[val - alphabet];
        }

        Node *go(char val) {
            if (!have(val)) {
                Node *node = new Node;
                mp[val - alphabet] = node;
            }

            return mp[val - alphabet];
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

            for (int i = 0; i < N; i++) {
                auto next = cur->mp[i];
                if (!next) continue;

                if (cur == root) next->fail = root;
                else {
                    Node *dest = cur->fail;

                    while (dest != root && !dest->have(i + alphabet)) dest = dest->fail;
                    if (dest->have(i + alphabet)) dest = dest->go(i + alphabet);
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
    
    long long countSubstring(const string &st) {
        Node *cur = root;
        long long cnt = 0;

        for (auto &e : st) {
            while (cur != root && !cur->have(e)) cur = cur->fail;
            if (cur->have(e)) cur = cur->go(e);
            if (cur->end) ++cnt;
        }
        return cnt;
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

### 구현 주의사항
소멸자 ~Node()에서 delete fail;하면 안 됨   
go방향으로 순서대로 delete하면 어차피 전부다 삭제되는데 중간에 delete fail; 넣으면 순서 엉킴   

countSubstring()에서 if (cur->end) ++cnt;를 cnt += cur->end;로 바꾸면 오히려 더 느려짐   
cnt는 long long, cur->end는 bool이므로 형변환 때문에 속도저하가 꽤 큼   
cnt += ll(cur->end);로 명시해줄 경우 속도저하가 줄어들긴 하지만 이 경우에는 그냥 if문 쓰는 게 더 나을 듯   

### 사용설명
findSubstring() 사용하기 전에 무조건 makeFailFunction()먼저 호출 후 사용   

1번째 구현은 문자 종류없이 항상 사용 가능하고 메모리도 적게 쓰지만 속도가 살짝 느림   
2번째 구현의 경우 map 대신 배열을 사용하므로 속도는 더 빠르지만 문자의 종류가 제한됨   

template \<char alphabet, int N>에서 alphabet은 문자열이 전부 소문자로 이루어졌다면 'a', 대문자라면 'A' 사용   
```cpp
// 소문자
AhoCorasickTrie<'a', 26> aho;

// 대문자
AhoCorasickTrie<'A', 26> aho;
```
array는 초기화할 때 fill을 사용하므로 O(N)의 시간복잡도가 들기 때문에 array크기는 줄일 수 있다면 최대한 줄이는 게 좋음   
알파벳의 종류가 26개 전부 주어지는 상황이 아니라면 template의 N을 조절해 사용   
대신 이 경우 미리 입력받은 문자열을 알맞게 변환해 사용해야 됨   
```cpp
// ex) 문자가 'A', 'G', 'C', 'T'만 주어지는 경우
for (auto &c : st) {
    if (c == 'A') c = 'a';
    else if (c == 'G') c = 'b';
    else if (c == 'C') c = 'c';
    else c = 'd';
}

AhoCorasickTrie<'a', 4> aho;
```
### 문제
[문자열 집합 판별](https://www.acmicpc.net/problem/9250)   
[돌연변이](https://www.acmicpc.net/problem/10256) - 문자 4종류만 주어짐, array 크기 조절   

### 참고링크
https://m.blog.naver.com/kks227/220992598966   
https://www.geeksforgeeks.org/aho-corasick-algorithm-pattern-searching/   