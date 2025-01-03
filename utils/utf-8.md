[카테고리](/README.md)
## utf-8
```cpp
// todo
```

### utf-8의 인코딩 방식
UTF-8은 가변 길이 인코딩을 사용함
| 문자 종류 | 바이트 수 | 바이트 패턴 |
| - | - | - |
| 영어(A~Z) | 1바이트 | 0xxxxxxx |
| 한글(가~힣) | 3바이트 | 1110xxxx 10xxxxxx 10xxxxxx |
| 이모지 | 4바이트 | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx |

문자의 종류에 따라 첫 바이트의 바이트 패턴이 다르고, 이어지는 바이트는 모두 10으로 시작함   
따라서 `(c & 0b11000000) != 0b10000000`으로 첫 바이트인지 아닌지를 판단할 수 있고, 이를 16진법으로 표현하면 `(c & 0xC0) != 0x80`가 됨

```cpp
int utf8_length(const string& s) { // 테스트 안 해본 코드니 주의
    int length = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char c = s[i];
        if ((c & 0xC0) != 0x80) ++length;
    }
    return length;
}
```

### 문제
[한글 LCS](https://www.acmicpc.net/problem/15482)   