[카테고리](/README.md)
### XOR Trie
```cpp
class Trie {
private:
    struct Node {
        Node* child[2];
        int cnt;
    };

    const int MAX_BIT = ceil(log2(MAX_INPUT));
    Node* root;

public:
    Trie() : root(new Node()) {}

    void insert(int num) {
        Node* cur = root;

        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!cur->child[bit]) cur->child[bit] = new Node();
            cur = cur->child[bit];
            cur->cnt++;
        }
    }

    void erase(int num) {
        Node* cur = root;

        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;

            cur = cur->child[bit];
            cur->cnt--;
        }
    }

    int query(int num) {
        Node* cur = root;
        int res = 0;
        
        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (cur->child[1 - bit] && cur->child[1 - bit]->cnt) {
                cur = cur->child[1 - bit];
                res |= (1 << i);
            }
            else cur = cur->child[bit];
        }
        
        return res;
    }
};
```
### 시간복잡도 
$O(log(N))$   

### 백준문제
[수열과 쿼리 20](https://www.acmicpc.net/problem/16903)