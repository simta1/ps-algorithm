[카테고리](/README.md)
### FFT code 1) bitReverse 매번 직접 계산
```cpp
namespace FourierTransform {
    using ld = long double;
    // using ld = double;
    using cpx = complex<ld>;
    const ld PI = acos(-1); 

    int bitReverse(int n, int len) {
        int rev = 0;
        for (int i = 0; i < len; i++) {
            rev |= ((n >> i) & 1) << (len - i - 1);
        }
        return rev;
    }

    void fft(vector<cpx> &f, bool is_reverse) {
        int n = f.size();
        int len = __builtin_ctz(n);
        
        for (int i = 0; i < n; i++) {
            int j = bitReverse(i, len);
            if (i < j) swap(f[i], f[j]);
        }

        for (int m = 2; m <= n; m *= 2) {
            ld t = 2 * PI / m * (is_reverse ? -1 : 1);
            cpx w(cos(t), sin(t));

            for (int i = 0; i < n; i += m) {
                cpx w_j(1, 0);
                for (int j = 0; j < m / 2; j++, w_j *= w) {
                    cpx even = f[i + j];
                    cpx odd = w_j * f[i + j + m / 2];
                    f[i + j] = even + odd;
                    f[i + j + m / 2] = even - odd;
                }
            }
        }

        if (is_reverse) {
            for (auto &e : f) e /= n;
        }
    }

    vector<int> multiply(const vector<int> &v1, const vector<int> &v2) {
        vector<cpx> a(v1.begin(), v1.end());
        vector<cpx> b(v2.begin(), v2.end());

        int n = 1;
        while (n <= a.size() || n <= b.size()) n <<= 1;
        n <<= 1;

        a.resize(n);
        b.resize(n);
        
        fft(a, false);
        fft(b, false);

        for (int i = 0; i < n; i++) a[i] *= b[i];
        fft(a, true);

        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = round(a[i].real());
        return res;
    }
}
```
### FFT code 2) bitReverse 더 빠른 코드
```cpp
namespace FourierTransform {
    using ld = long double;
    // using ld = double;
    using cpx = complex<ld>;
    const ld PI = acos(-1); 

    void fft(vector<cpx> &f, bool is_reverse) {
        int n = f.size();
        
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n / 2;
            while (j >= bit) {
                j -= bit;
                bit /= 2;
            }
            j += bit;
            if (i < j) swap(f[i], f[j]);
        }

        for (int m = 2; m <= n; m *= 2) {
            ld t = 2 * PI / m * (is_reverse ? -1 : 1);
            cpx w(cos(t), sin(t));

            for (int i = 0; i < n; i += m) {
                cpx w_j(1, 0);
                for (int j = 0; j < m / 2; j++, w_j *= w) {
                    cpx even = f[i + j];
                    cpx odd = w_j * f[i + j + m / 2];
                    f[i + j] = even + odd;
                    f[i + j + m / 2] = even - odd;
                }
            }
        }

        if (is_reverse) {
            for (auto &e : f) e /= n;
        }
    }

    vector<int> multiply(const vector<int> &v1, const vector<int> &v2) {
        vector<cpx> a(v1.begin(), v1.end());
        vector<cpx> b(v2.begin(), v2.end());

        int n = 1;
        while (n <= a.size() || n <= b.size()) n <<= 1;
        n <<= 1;

        a.resize(n);
        b.resize(n);
        
        fft(a, false);
        fft(b, false);

        for (int i = 0; i < n; i++) a[i] *= b[i];
        fft(a, true);

        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = round(a[i].real());
        return res;
    }
}
```
### 시간복잡도 
$O(N~logN)$   

### 주의사항
실수 오차가 생각보다 커질 수 있다.   

### 사용관련
사용할 땐 code 2 사용   
code 1은 조금 더 직관적이기에 그저 이해용으로 넣은 코드임   
생각보다 실수 오차 없다 싶으면 using ld = long double; 부분 long double 대신 double로 선택   
long double과 double 시간 차이가 꽤 크게 난다.   
[큰 수 곱셈 (2)](https://www.acmicpc.net/problem/15576) 문제 기준으로 long double에서 688ms였던 코드가 double로 바꾸니 268ms까지 줄어듦

### 백준문제
[큰 수 곱셈 (2)](https://www.acmicpc.net/problem/15576)   
[큰 수 곱셈 (3)](https://www.acmicpc.net/problem/22289)