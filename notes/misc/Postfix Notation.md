[카테고리](/README.md)
## Infix to Postfix
```cpp
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0; // c == '('
}

string infixToPostFix(const string &st) {
    string res = "";
    stack<char> S;

    auto addAndPop = [&]() {
        res += S.top();
        S.pop();
    };

    for (auto &c : st) {
        if (c >= 'A' && c <= 'Z') res += c;
        else if (c == '(') S.push(c);
        else if (c == ')') {
            while (S.top() != '(') addAndPop();
            S.pop();
        }
        else {
            while (!S.empty() && precedence(c) <= precedence(S.top())) addAndPop();
            S.push(c);
        }
    }
    while (!S.empty()) addAndPop();

    return res;
}
```
### 시간복잡도 
$O(N)$   

### 문제
[후위 표기식](https://www.acmicpc.net/problem/1918)