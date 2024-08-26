[카테고리](/README.md)
# 코드 실험 안 했음 <!-- TODO -->
## BigInt
```cpp
template <int N>
class BaseInt {
private:
    vector<int> digits;

public:
    BaseInt() : digits(1, 0) {}

    size_t size() { return digits.size(); }
    void resize(int newSize) { digits.resize(newSize); }
    int& operator[](size_t idx) { return digits[idx]; }
    const int& operator[](size_t idx) const { return digits[idx]; }

    BaseInt& operator+=(const BaseInt &other) {
        int maxSize = max(size(), other.size());

        for (int i = 0, carry = 0; i < digits.size() || carry; i++) {
            if (i >= size()) digits.push_back(0);

            carry += (*this)[i] + other[i];
            (*this)[i] = carry % N;
            carry /= N;
        }
        return *this;
    }

    BaseInt operator*(int num) {
        BaseInt res;
        for (int i = 0, carry = 0; i < a.size(); i++) {
            if (i >= size()) digits.push_back(0);

            carry += a[i] * num;
            res[i] = carry % N;
            carry /= N;
        }
        return res;
    }
}


// gpt
// template<int N>
// class BigInt {
// public:
//     // Constructor to initialize BigInt to zero
//     BigInt() : digits(N, 0) {}

//     // Constructor to initialize BigInt from a string in base N
//     BigInt(const string& s) : digits(N, 0) {
//         int len = s.size();
//         int pos = len - 1;
//         for (char c : s) {
//             int value = (isdigit(c) ? c - '0' : c - 'A' + 10);
//             digits[pos--] = value;
//         }
//     }

//     // Addition operator
//     BigInt<N> operator+(const BigInt<N>& other) const {
//         BigInt<N> result;
//         int carry = 0;
//         for (int i = 0; i < N; ++i) {
//             carry += digits[i] + other.digits[i];
//             result.digits[i] = carry % N;
//             carry /= N;
//         }
//         return result;
//     }

//     // Addition assignment operator
//     BigInt<N>& operator+=(const BigInt<N>& other) {
//         int carry = 0;
//         for (int i = 0; i < N; ++i) {
//             carry += digits[i] + other.digits[i];
//             digits[i] = carry % N;
//             carry /= N;
//         }
//         return *this;
//     }

//     // Multiplication operator with an integer
//     BigInt<N> operator*(int b) const {
//         BigInt<N> result;
//         int carry = 0;
//         for (int i = 0; i < N; ++i) {
//             carry += digits[i] * b;
//             result.digits[i] = carry % N;
//             carry /= N;
//         }
//         return result;
//     }

//     // Less-than comparison operator
//     bool operator<(const BigInt<N>& other) const {
//         for (int i = N - 1; i >= 0; --i) {
//             if (digits[i] != other.digits[i]) {
//                 return digits[i] < other.digits[i];
//             }
//         }
//         return false;
//     }

//     // Print method
//     void print() const {
//         int idx = N - 1;
//         while (idx >= 0 && digits[idx] == 0) {
//             --idx;
//         }

//         if (idx == -1) {
//             cout << '0';
//             return;
//         }

//         for (int i = idx; i >= 0; --i) {
//             cout << (digits[i] < 10 ? '0' + digits[i] : 'A' + digits[i] - 10);
//         }
//     }

// private:
//     vector<int> digits;
// };
```
### 시간복잡도 
$O()$   

### 구현 주의사항


### 사용설명


### 문제
[36진수](https://www.acmicpc.net/problem/1036)   

### 원리


### 참고링크