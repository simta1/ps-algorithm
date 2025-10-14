#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Fastio {
private:
    static constexpr bool noNegative = false;
    static constexpr int buf_size = 1 << 18;
    // | n   | 2^n     |
    // | --- | ------- |
    // | 16  | 65536   |
    // | 17  | 131072  |
    // | 18  | 262144  |
    // | 19  | 524288  |
    // | 20  | 1048576 |
    // | 21  | 2097152 |
    char buf[buf_size];
    int len, pos;

    char write_buf[buf_size];
    int write_pos;

    bool eof;

    inline int getBuf() {
        if (pos == len) {
            len = fread(buf, 1, buf_size, stdin);
            pos = 0;

            if (!len) {
                eof = true;
                return -1;
            }
        }

        return buf[pos++];
    }

    inline int readChar() { // eof일 경우 -1 리턴
        int c;
        do { c = getBuf(); } while (!eof && c <= 32);
        return c;
    }
    
    template <class T>
    T readInt() { // eof일 경우 0 리턴
        if constexpr (noNegative) {
            int val = 0, c = readChar();
            while ('0' <= c && c <= '9') val = (val << 1) + (val << 3) + (c & 15), c = getBuf();
            return val;
        }
        else {
            int sign = 1, c = readChar();
            T val = 0;
            if (c == '-') sign = -1, c = getBuf();
            while ('0' <= c && c <= '9') val = (val << 1) + (val << 3) + (c & 15), c = getBuf();
            return sign == 1 ? val : -val;
        }
    }

    inline string readString() { // eof일 경우 "" 리턴
        int c = readChar();
        string st = "";
        while (c > 32) {
            st += c;
            c = getBuf();
        }
        return st;
    }

    inline void writeChar(int x){
        if (write_pos == buf_size) fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
        write_buf[write_pos++] = x;
    }

    template <class T>
    void writeInt(T x, char end=0){
        if (x < 0) writeChar('-'), x = -x;
        char s[24]; int n = 0;
        while (x || !n) s[n++] = '0' + x % 10, x /= 10;
        while (n--) writeChar(s[n]);
        if (end) writeChar(end);
    }

    inline void writeWord(const char *s){
        while (*s) writeChar(*s++);
    }

public:
    Fastio() : len(0), pos(0), write_pos(0), eof(false) {}
    ~Fastio() { // flusher // write_pos == buf_size되기 전까진 출력 안하고 모아둠. 프로그램 종료전까지 출력 안된건 자동으로 종료 전에 소멸자 호출하며 출력
        if (write_pos) {
            fwrite(write_buf, 1, write_pos, stdout);
            write_pos = 0;
        }
    }

    Fastio& operator>>(char& c) { c = readChar(); return *this; }
    template<class T> Fastio& operator>>(T& x) { x = readInt<T>(); return *this; }
    Fastio& operator>>(string& st) { st = readString(); return *this; }
    Fastio& operator<<(const char& c) { writeChar(c); return *this; }
    template<class T> Fastio& operator<<(const T& x) { writeInt(x); return *this; }
    Fastio& operator<<(const string& st) { writeWord(st.c_str()); return *this; }
    Fastio& operator<<(const char* st) { writeWord(st); return *this; }
    explicit operator bool() const { return !eof; }

} fio;

#define cin fio
#define cout fio

template <typename T>
class SegmentTree {
private:
    int n;
    vector<T> tree, lazy;
    
    void init(const vector<T> &v, int node, int s, int e) {
        if (s == e) {
            tree[node] = v[s];
            return;
        }

        int m = s + e >> 1;
        init(v, node * 2, s, m);
        init(v, node * 2 + 1, m + 1, e);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void updateLazy(int node, int s, int e) {
        if (!lazy[node]) return;

        tree[node] += (e - s + 1) * lazy[node];
        if (s != e) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void updateRange(int node, int s, int e, int l, int r, T add) {
        updateLazy(node, s, e);

        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            tree[node] += (e - s + 1) * add;
            if (s != e) {
                lazy[node * 2] += add;
                lazy[node * 2 + 1] += add;
            }
            return;
        }
        
        int m = s + e >> 1;
        updateRange(node * 2, s, m, l, r, add);
        updateRange(node * 2 + 1, m + 1, e, l, r, add);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    T query(int node, int s, int e, int l, int r) {
        updateLazy(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];

        int m = s + e >> 1;
        T lq = query(node * 2, s, m, l, r);
        T rq = query(node * 2 + 1, m + 1, e, l, r);
        return lq + rq;
    }

public:
    SegmentTree(int n) : n(n), tree(4 * n), lazy(4 * n) {}
    SegmentTree(const vector<T> &v) : n(v.size()), tree(4 * v.size()), lazy(4 * v.size()) {
        init(v, 1, 0, n - 1);
    }

    void update(int l, int r, T add) {
        updateRange(1, 0, n - 1, l - 1, r - 1, add);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l - 1, r - 1);
    }
};

int main() {
    // cin.tie(0) -> sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> v(n);
    for (auto &e : v) cin >> e;
    SegmentTree<ll> seg(v);

    for (m += k; m--;) {
        int a;
        cin >> a;

        if (a == 1) {
            ll b, c, d;
            cin >> b >> c >> d;
            seg.update(b, c, d);
        }
        else {
            ll b, c;
            cin >> b >> c;
            cout << seg.query(b, c) << "\n";
        }
    }
}