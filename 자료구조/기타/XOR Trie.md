[카테고리](/README.md)
# 테스트 안 끝난 코드 : queryMin(), countLE() 함수
## XOR Trie
```cpp
template <typename T>
class Trie {
private:
    struct Node {
        Node* child[2];
        int cnt;
    };

    const int MAX_BIT;
    Node* root;

public:
    Trie(int max_bit = numeric_limits<T>::digits - 1) : MAX_BIT(max_bit), root(new Node()) {}

    void insert(T num) {
        Node* cur = root;

        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!cur->child[bit]) cur->child[bit] = new Node();
            cur = cur->child[bit];
            ++cur->cnt;
        }
        ++root->cnt;
    }

    bool erase(T num) {
        // check
        Node* cur = root;

        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (cur->child[bit] && cur->child[bit]->cnt) cur = cur->child[bit];
            else return false;
        }

        // delete
        cur = root;

        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;
            cur = cur->child[bit];
            --cur->cnt;
        }
        --root->cnt;

        return true;
    }

    T queryMax(T num) {
        assert(root->cnt);

        Node* cur = root;
        T res = 0;
        
        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (cur->child[1 - bit] && cur->child[1 - bit]->cnt) {
                cur = cur->child[1 - bit];
                res |= T(1) << i;
            }
            else cur = cur->child[bit];
        }
        
        return res;
    }

    T queryMin(T num) {
        assert(root->cnt);

        Node* cur = root;
        T res = 0;

        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (cur->child[bit] && cur->child[bit]->cnt) cur = cur->child[bit];
            else {
                cur = cur->child[1 - bit];
                res |= (T(1) << i);
            }
        }

        return res;
    }

    int countLE(T num, T mx) {
        Node* cur = root;
        int cnt = 0;

        for (int i = MAX_BIT; i >= 0; i--) {
            int bitNum = (num >> i) & 1;
            int bitMx = (mx >> i) & 1;

            if (bitMx == 1 && cur->child[bitNum]) cnt += cur->child[bitNum]->cnt;
            if (!cur->child[bitNum ^ bitMx]) return cnt;
            cur = cur->child[bitNum ^ bitMx];
        }

        cnt += cur->cnt;

        return cnt;
    }
};
```
### 시간복잡도 
$O(logN)$   

### 문제
[수열과 쿼리 20](https://www.acmicpc.net/problem/16903)