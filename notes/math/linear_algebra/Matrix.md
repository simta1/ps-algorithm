[카테고리](/README.md)
# TODO operator* 캐시히트 높이기, https://memoacmicpc.tistory.com/entry/PS%EC%97%90%EC%84%9C-%EC%93%B0%EB%8A%94-Matrix-multiplication%EC%9D%98-%EA%B5%AC%ED%98%84%EA%B3%BC-%EC%B5%9C%EC%A0%81%ED%99%94   
# TODO SIMD 사용하는 O(N^3 / 8) 행렬 곱셈 추가하기 <!-- https://m.blog.naver.com/jinhan814/223082489883 -->
## Matrix
```cpp
template <typename T, T mod>
class Matrix {
private:
    int rows, cols;
    vector<vector<T> > v;

public:
    Matrix() = default;
    Matrix(int rows, int cols, bool identity=false) : rows(rows), cols(cols), v(rows, vector<T>(cols)) {
        if (identity) {
            assert(rows == cols);
            for (int i = 0; i < rows; i++) v[i][i] = 1;
        }
    }

    vector<T>& operator[](int i) { return v[i]; } // 0-based
    const vector<T>& operator[](int i) const { return v[i]; }

    Matrix<T, mod> operator*(const Matrix<T, mod> &other) const {
        assert(cols == other.rows);
        Matrix<T, mod> res(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) res[i][j] = (res[i][j] + (*this)[i][k] * other[k][j]) % mod;
            }
        }
        return res;
	}

    template <typename F>
	friend Matrix<T, mod> power(Matrix a, F n) {
        assert(a.rows == a.cols);
        Matrix<T, mod> res(a.rows, a.rows, true);

        while (n > 0) {
            if (n & 1) res = res * a;
            a = a * a;
            n >>= 1;
        }

		return res;
	}
};
```
### 시간복잡도 
operator* $O(R^3)$   
power $O(R^3 logN)$

<!-- TODO -->
power $O(R^3 + R logN)$ 구현도 존재하나 나중에 작성   

### 문제
[행렬 제곱](https://www.acmicpc.net/problem/10830)