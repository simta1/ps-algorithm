[카테고리](/README.md)
## utf-8
```cpp
vector<int> utf8ToInt(const string& st) {
    vector<int> res;
    if (!st.size()) return res;

    int cur = 0;
    for (int i = 0; i < st.size(); i++) {
        cur = cur << 8 | (int)(unsigned char)st[i];
        if (i == st.size() - 1 || ((unsigned char)st[i + 1] & 0xC0) != 0x80) { // 문자의 끝 바이트인지
            res.push_back(cur);
            cur = 0;
        }
    }

    return res;
}
```

### 구현 주의사항
char을 int로 형변환 할경우 sign extension이 적용된다.   
만약 알파벳이라면 가능한 아스키코드 값의 최대값이 128 미만이므로('z'일 때 122) 어차피 sign extension과 zero extension의 결과가 같아 int로 바로 형변환을 해도 괜찮지만,   
한글이나 이모지등이 저장될 때는 char형 변수에 128 이상의 값이 저장 되어있을 수 있다. 이 때 바로 int로 형변환할 경우 sign extension이므로 앞쪽에 추가되는 24비트가 모두 1이 되고, `cur`변수에 값을 누적할 때 앞쪽비트에 저장된 값들이 날라가게 되므로 문제가 된다.   
unsigned char을 int로 변환할 땐 zero extension이 일어나므로 char->unsigned char->int순서로 변환해 사용하면 문제없이 작동한다.   
char->unsigned char로의 변환은 값을 해석하는 방식이 변하는 것 뿐 저장되어있는 비트들의 값은 변하지 않으므로 문제되지 않는다.   
```cpp
// 틀린 코드, sign extension이 되므로 만약 st[i]>=128이라면 앞쪽 24비트는 1이 채워지고 cur의 앞쪽 24비트또한 1로 덮어씌워진다.
cur = cur << 8 | (int)st[i];

// 맞는 코드
cur = cur << 8 | (int)(unsigned char)st[i];
```

### 원리
UTF-8은 가변 길이 인코딩을 사용   
| 문자 종류 | 바이트 수 | 바이트 패턴 |
| - | - | - |
| 영어(A~Z) | 1바이트 | 0xxxxxxx |
| 한글(가~힣) | 3바이트 | 1110xxxx 10xxxxxx 10xxxxxx |
| 이모지 | 4바이트 | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx |

문자의 종류에 따라 첫 바이트의 바이트 패턴이 다르고, 이어지는 바이트는 모두 10으로 시작   
따라서 `(c & 0b11000000) != 0b10000000`으로 첫 바이트인지 아닌지를 판단할 수 있고, 이를 16진법으로 표현하면 `(c & 0xC0) != 0x80`가 됨

### 문제
[한글 LCS](https://www.acmicpc.net/problem/15482)   