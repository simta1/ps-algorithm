[카테고리](/README.md)
## BaseInt
```cpp
template <int N>
class BaseInt { // 알파벳의 경우 대문자 사용
private:
    vector<int> digits;

public:
    BaseInt() = default;
    BaseInt(const string &st) {
        digits.reserve(st.size());
        for (auto *it = st.rbegin(); it != st.rend(); it++) digits.push_back(ctoi(*it));
    }

    static int ctoi(char c) { return isdigit(c) ? c - '0' : c - 'A' + 10; }
    static char itoc(int x) { return x < 10 ? x + '0' : x - 10 + 'A'; }
    
    void update(int idx, int val) { // += val * N^idx;
        if (idx >= digits.size()) digits.resize(idx + 1, 0);
        for (int i = idx, carry = 0; i < digits.size() || carry; i++) {
            if (i == digits.size()) digits.push_back(0);
            digits[i] += carry + (i == idx);
            carry = digits[i] / N;
            digits[i] %= N;
        }
    }

    BaseInt<N>& operator+=(const BaseInt<N> &b) {
        int maxSize = max(digits.size(), b.digits.size());
        digits.reserve(maxSize + 1);
        for (int i = 0, carry = 0; i < maxSize || carry; i++) {
            if (i == digits.size()) digits.push_back(0);
            digits[i] += carry + (i < b.digits.size() ? b.digits[i] : 0);
            if (carry = (digits[i] >= N)) digits[i] -= N;
        }
        return *this;
    }
    BaseInt<N> operator+(const BaseInt<N> &b) const { BaseInt<N> res = *this; res += b; return res; }

    BaseInt<N>& operator*=(int b) {
        if (!b) digits.clear();
        else {
            for (int i = 0, carry = 0; i < digits.size() || carry; i++) {
                if (i == digits.size()) digits.push_back(0);
                long long cur = carry + digits[i] * 1LL * b;
                carry = cur / N;
                digits[i] = cur % N;
            }
        }
        return *this;
    }
    BaseInt<N> operator*(int b) const { BaseInt<N> res = *this; res *= b; return res; }
    
    bool operator<(const BaseInt<N> &b) const {
        if (!digits.empty()) assert(digits.back()!=0);
        if (!b.digits.empty()) assert(b.digits.back()!=0);

        if (digits.size() != b.digits.size()) return digits.size() < b.digits.size();
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != b.digits[i]) return digits[i] < b.digits[i];
        }
        return false;
    }

    friend ostream &operator<<(ostream &os, const BaseInt<N> &a) {
        if (a.digits.empty()) os << "0";
        else {
            assert(a.digits.back()!=0);
            for (auto it = a.digits.rbegin(); it != a.digits.rend(); it++) os << itoc(*it);
        }
        return os;
    }
};
```
### 사용설명


### 문제
[36진수](https://www.acmicpc.net/problem/1036)   