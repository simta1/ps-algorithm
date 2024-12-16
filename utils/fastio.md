[카테고리](/README.md)
## fastio
```cpp
class Fastio {
private:
    static constexpr bool noNegative = false;
    static_assert(false, "noNegative true로 바꿔도 되는지 확인");
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

    inline void writeChar(int x) {
        if (write_pos == buf_size) fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
        write_buf[write_pos++] = x;
    }

    template <class T>
    void writeInt(T x, char end=0) {
        if (x < 0) writeChar('-'), x = -x;
        char s[24]; int n = 0;
        while (x || !n) s[n++] = '0' + x % 10, x /= 10;
        while (n--) writeChar(s[n]);
        if (end) writeChar(end);
    }

    inline void writeWord(const char *s) {
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
assert (false, "cin.tie(0) 주석처리 하기");
```
### 버퍼 크기 정할 때 참고
| $n$ | $2^n$   |
| --- | ------- |
| 16  | 65536   |
| 17  | 131072  |
| 18  | 262144  |
| 19  | 524288  |
| 20  | 1048576 |
| 21  | 2097152 |

### 양수 최적화
```cpp
static constexpr bool noNegative = true;
```

### 사용설명
<!-- TODO readDouble, getLine -->
```cpp
int a, b;
fin >> a >> b;
fio << a + b;

// input, output 한 줄에 섞어서 사용 가능   
int a, b;
fio >> a >> b << a + b << "\n";
```

### 문제
[빠른 A+B](https://www.acmicpc.net/problem/15552)   
[0.1](https://www.acmicpc.net/problem/11921)

### 원리
'0' ~ '9'를 char -> int 변환 시 15와 bit AND 연산 사용   
'0' -> 48 -> 0b11 0000 -> 0x30   
'9' -> 57 -> 0b11 1001 -> 0x39   

`while (c >= '0' && c <= '9')` 대신 `while (c & 16)` 사용하는 구현도 있는 것 같은데   
내 구현에선 쓸 거면 `while (!eof && c & 16)`로 해야 됨   
솔직히 시간차이 별로 없는 듯 해서 좀 더 직관적인 코드로 사용

### 사용설명
실수의 출력은 오버로딩하지 않았다.   
코드 추가하긴 귀찮아서 그냥 stringstream으로 실수->문자열로 변환한 뒤 출력하는 식으로 사용 중이다.   
TODO 언젠가 할거없으면 오버로딩 코드 추가하지 않을까   
```cpp
double d;
// fio << d; // 오버로딩 안 되어있어서 에러 남
stringstream ss;
ss << fixed << setprecision(n) << d;
fio << ss.str();
```

### 참고링크
https://github.com/justiceHui/AlgorithmImplement/blob/master/misc/FastInput.cpp   
https://www.acmicpc.net/blog/view/105   
https://blog.naver.com/jinhan814/222400578937   
https://blog.naver.com/jinhan814/222401181859   
https://blog.naver.com/jinhan814/222406997159   