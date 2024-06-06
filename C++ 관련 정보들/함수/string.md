## 공백 포함 입력
### getline(cin, st)
'\n'이 나오기 전까지 문자들을 받아 st에 저장   

### cin.ignore()
이전에 뭔가 입력받은 적이 있다면 버퍼에 남아있던 '\n'이 getline으로 들어올 수 있으므로 cin.ignore() 후 사용
```md
4
this is string
```
```cpp
int n;
string st;

// 맞는 코드
cin >> n;
cin.ignore();
getline(cin, st);

// 틀린 코드
cin >> n;
getline(cin, st); // 4 뒤에 나오는 '\n'이 버퍼에 있는 상황, '\n'전까지 입력받으므로 아무것도 입력받지 않음
```

getline()으로 입력받은 후라면 애초에 버퍼 비어있으므로 cin.ignore()하면 안 됨
```cpp
int n;
string st1, st2;

// 맞는 코드
cin >> n;
cin.ignore();
getline(cin, st1);
getline(cin, st2);

// 틀린 코드 (st2의 맨 앞 문자 잘림)
cin >> n;
cin.ignore();
getline(cin, st1);
cin.ignore();
getline(cin, st2);
```

## 문자열 split
### getline(cin, st, delim)
구분자(delim)가 나오기 전까지 문자들을 받아 st에 저장

### istringstream
```cpp
vector<string> split(const string &st) { // 공백 기준 split
    vector<string> words;

    istringstream iss(st);
    string word;
    while (iss >> word) words.push_back(word);

    return words;
}
```

```cpp
vector<string> splitString(const string &str, char delimiter) {
    vector<string> words;

    istringstream iss(str);
    string token;
    while (getline(iss, token, delimiter)) words.push_back(token);

    return words;
}
```
### substr(pos)
st[pos:] 리턴

### substr(pos, cnt)
st[pos:(pos+cnt)] 리턴