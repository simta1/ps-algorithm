[카테고리](/README.md)
## 공백 포함 입력
### getline(cin, st)
'\n'이 나오기 전까지 문자들을 받아 st에 저장   

### cin.ignore()
이전에 cin >> 으로 입력받은 적이 있다면 cin.ignore() 한 번 호출 후 사용   
getline() 사이에서는 cin.ignore()호출할 필요 없음(정확히는, 호출하면 안 됨)   

cin >>는 여러 개의 값을 연속으로 입력받을 때, 개행 문자와 공백 문자를 자동으로 무시하기 때문에 별도의 처리가 필요하지 않음   
```md
4
apple
```
예를 들어 입력이 위처럼 주어질 때, cin >> n;을 사용하면 4를 입력받게 되고 입력 스트림의 커서는 4 다음의 줄바꿈 문자에 위치하게 됨.   
이후 cin >> st를 사용하면 cin >> 는 자동으로 '\n'을 무시하고 다음 단어에 해당하는 "apple"을 st에 입력받음   

만약 cin >> 과 getline()을 섞어쓰는 경우, cin >> n; 이후 입력 스트림의 커서가 4 다음의 줄바꿈 문자에 위치한 상황에서 getline()을 사용하면 이미 현재 위치에 '\n'이 있으므로 아무것도 입력받지 않게 됨.   

또한 getline()은 개행 문자를 만나기 전까지의 모든 문자를 읽어서 지정된 문자열 변수에 저장한 뒤, 개행 문자를 버퍼에서 제거하기 때문에 getline()을 연속해서 호출할 때는 중간에 cin.ignore()를 할 필요가 없음   
getline() 후 cin.ignore()를 사용할 경우, 이미 개행문자는 제거된 이후이므로 그다음에 나오는 진짜 문자를 제거하게 되어 다음 입력이 잘리게 됨

당연한 얘기지만, getline()을 쓰다가 cin >>을 사용하게 될 경우에도 마찬가지로 cin.ignore()를 쓰면 안 됨   

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
#### istringstream good(), eof(), fail(), bad()
```cpp
```

### substr(pos)
st[pos:] 리턴

### substr(pos, cnt)
st[pos:(pos+cnt)] 리턴

## 문자열 형변환
```cpp
int num = stoi(st); // s(tring) to i(int)
int num = stoi(st, nullptr, n); // st를 n진법으로 해석해서 변환 (2 <= n <= 36)
crope rp(st.c_str()); // std::string to c_str
if (isdigit(ch)) ; // 숫자인지 확인
```

## 소수점 n자리로 반올림한 실수 문자열변환
```cpp
double d;
stringstream ss;
ss << fixed << setprecision(n) << d;
string str_d = ss.str();
```
iomanip로 stringstream에 출력하고 문자열로 변환하면 편하다.   
[fastio](/utils/fastio.md)에서 실수형 출력 함수를 오버로딩하지 않았기에 실수를 빠른입출력 하는 경우 문자열로 변환해서 출력하면 된다.   