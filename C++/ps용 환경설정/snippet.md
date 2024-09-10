[카테고리](/README.md)
# VSC Snippet
---
## cpp용 snippet
- __1. vsc Command Palette 열기 (Ctrl + Shift + p)__
- __2. Snippets: Configure Snippets__ 선택
- __3. cpp.json__ 선택

```json
{
	"ps default code": {
		"prefix": "SNIP ps_default",
		"body": [
			"#include <bits/stdc++.h>",
			"using namespace std;",
			"using ld = double;",
			"using ll = long long;",
			"using ull = unsigned long long;",
			"using pii = pair<int, int>;",
			"using pll = pair<ll, ll>;",
			"using tii = tuple<int, int, int>;",
			"using qii = tuple<int, int, int, int>;",
			"",
			"int main() {",
			"\tcin.tie(0) -> sync_with_stdio(0);",
			"\t",
			"\t$0",
			"\t",
			"\treturn 0;",
			"}"
		],
		"description": "ps default code"
	},

	"GCC optimize": {
		"prefix": "#pragma GCC",
		"body": [
			"#pragma GCC optimize(\"O3\")",
			"#pragma GCC optimize(\"Ofast\")",
			"#pragma GCC optimize(\"unroll-loops\")",
			""
		],
		"description": "GCC optimize"
	},

	"include ext/rope": {
		"prefix": "#include <ext/rope>",
		"body": [
			"#include <ext/rope>",
			"using namespace __gnu_cxx;",
			"",
			""
		],
		"description": "include ext/rope"
	},

	"include ext/pb_ds": {
		"prefix": "#include <ext/pb_ds>",
		"body": [
			"#include <ext/pb_ds/assoc_container.hpp>",
			"#include <ext/pb_ds/tree_policy.hpp>",
			"using namespace __gnu_pbds;",
			"using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;",
			"",
			""
		],
		"description": "include ext/pb_ds"
	},

	"fastio": {
		"prefix": "SNIP fastio",
		"body": [
			"class Fastio {",
			"private:",
			"\tstatic constexpr bool noNegative = false;",
			"\tstatic_assert(false, \"noNegative true로 바꿔도 되는지 확인\");",
			"\tstatic constexpr int buf_size = 1 << 18;",
			"\t// | n   | 2^n     |",
			"\t// | --- | ------- |",
			"\t// | 16  | 65536   |",
			"\t// | 17  | 131072  |",
			"\t// | 18  | 262144  |",
			"\t// | 19  | 524288  |",
			"\t// | 20  | 1048576 |",
			"\t// | 21  | 2097152 |",
			"\tchar buf[buf_size];",
			"\tint len, pos;",
			"",
			"\tchar write_buf[buf_size];",
			"\tint write_pos;",
			"",
			"\tbool eof;",
			"",
			"\tinline int getBuf() {",
			"\t\tif (pos == len) {",
			"\t\t\tlen = fread(buf, 1, buf_size, stdin);",
			"\t\t\tpos = 0;",
			"",
			"\t\t\tif (!len) {",
			"\t\t\t\teof = true;",
			"\t\t\t\treturn -1;",
			"\t\t\t}",
			"\t\t}",
			"",
			"\t\treturn buf[pos++];",
			"\t}",
			"",
			"\tinline int readChar() { // eof일 경우 -1 리턴",
			"\t\tint c;",
			"\t\tdo { c = getBuf(); } while (!eof && c <= 32);",
			"\t\treturn c;",
			"\t}",
			"\t",
			"\ttemplate <class T>",
			"\tT readInt() { // eof일 경우 0 리턴",
			"\t\tif constexpr (noNegative) {",
			"\t\t\tint val = 0, c = readChar();",
			"\t\t\twhile ('0' <= c && c <= '9') val = (val << 1) + (val << 3) + (c & 15), c = getBuf();",
			"\t\t\treturn val;",
			"\t\t}",
			"\t\telse {",
			"\t\t\tint sign = 1, c = readChar();",
			"\t\t\tT val = 0;",
			"\t\t\tif (c == '-') sign = -1, c = getBuf();",
			"\t\t\twhile ('0' <= c && c <= '9') val = (val << 1) + (val << 3) + (c & 15), c = getBuf();",
			"\t\t\treturn sign == 1 ? val : -val;",
			"\t\t}",
			"\t}",
			"",
			"\tinline string readString() { // eof일 경우 \"\" 리턴",
			"\t\tint c = readChar();",
			"\t\tstring st = \"\";",
			"\t\twhile (c > 32) {",
			"\t\t\tst += c;",
			"\t\t\tc = getBuf();",
			"\t\t}",
			"\t\treturn st;",
			"\t}",
			"",
			"\tinline void writeChar(int x){",
			"\t\tif (write_pos == buf_size) fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;",
			"\t\twrite_buf[write_pos++] = x;",
			"\t}",
			"",
			"\ttemplate <class T>",
			"\tvoid writeInt(T x, char end=0){",
			"\t\tif (x < 0) writeChar('-'), x = -x;",
			"\t\tchar s[24]; int n = 0;",
			"\t\twhile (x || !n) s[n++] = '0' + x % 10, x /= 10;",
			"\t\twhile (n--) writeChar(s[n]);",
			"\t\tif (end) writeChar(end);",
			"\t}",
			"",
			"\tinline void writeWord(const char *s){",
			"\t\twhile (*s) writeChar(*s++);",
			"\t}",
			"",
			"public:",
			"\tFastio() : len(0), pos(0), write_pos(0), eof(false) {}",
			"\t~Fastio() { // flusher // write_pos == buf_size되기 전까진 출력 안하고 모아둠. 프로그램 종료전까지 출력 안된건 자동으로 종료 전에 소멸자 호출하며 출력",
			"\t\tif (write_pos) {",
			"\t\t\tfwrite(write_buf, 1, write_pos, stdout);",
			"\t\t\twrite_pos = 0;",
			"\t\t}",
			"\t}",
			"",
			"\tFastio& operator>>(char& c) { c = readChar(); return *this; }",
			"\ttemplate<class T> Fastio& operator>>(T& x) { x = readInt<T>(); return *this; }",
			"\tFastio& operator>>(string& st) { st = readString(); return *this; }",
			"\tFastio& operator<<(const char& c) { writeChar(c); return *this; }",
			"\ttemplate<class T> Fastio& operator<<(const T& x) { writeInt(x); return *this; }",
			"\tFastio& operator<<(const string& st) { writeWord(st.c_str()); return *this; }",
			"\tFastio& operator<<(const char* st) { writeWord(st); return *this; }",
			"\texplicit operator bool() const { return !eof; }",
			"",
			"} fio;",
			"",
			"#define cin fio",
			"#define cout fio",
			"assert (false, \"cin.tie(0) 주석처리 하기\");",
			""
		],
		"description": "fastio"
	},

	"codeforces testcase for loop": {
		"prefix": "SNIP ps_TC",
		"body": [
			"int TC;",
			"for (cin >> TC; TC--;) {",
			"\t$0",
			"}",
		],
		"description": "codeforces testcase for loop"
	},

	"cin n": {
		"prefix": "SNIP cin_n",
		"body": [
			"int n;",
			"cin >> n;",
			"",
			""
		],
		"description": "int n"
	},

	"cin nm": {
		"prefix": "SNIP cin_nm",
		"body": [
			"int n, m;",
			"cin >> n >> m;",
			"",
			""
		],
		"description": "int n, m"
	},

	"cin nmk": {
		"prefix": "SNIP cin_nmk",
		"body": [
			"int n, m, k;",
			"cin >> n >> m >> k;",
			"",
			""
		],
		"description": "int n, m, k"
	},

	"cin nk": {
		"prefix": "SNIP cin_nk",
		"body": [
			"int n, k;",
			"cin >> n >> k;",
			"",
			""
		],
		"description": "int n, k"
	},

	"cin v": {
		"prefix": "SNIP cin_v",
		"body": [
			"vector<int> v(n);",
			"for (auto &e : v) cin >> e;",
			"",
			""
		],
		"description": "vector<int> v(n)"
	},

	"cin vec2D": {
		"prefix": "SNIP cin_v2",
		"body": [
			"vector v(${1:n}, vector<int>(${2:m}));",
			"for (auto &r : v) for (auto &e : r) cin >> e;",
			"",
			""
		],
		"description": "vector v(n, vector<int>(m))"
	},

	"cin x": {
		"prefix": "SNIP cin_x",
		"body": [
			"int x;",
			"cin >> x;",
			"",
			""
		],
		"description": "int x"
	},

	"cin c": {
		"prefix": "SNIP cin_c",
		"body": [
			"char c;",
			"cin >> c;",
			"",
			""
		],
		"description": "char c"
	},

	"cin st": {
		"prefix": "SNIP cin_st",
		"body": [
			"string st;",
			"cin >> st;",
			"",
			""
		],
		"description": "string st"
	},

	"lambdaWrap": {
		"prefix": "SNIP lambdaWrap",
		"body": [
			"[&]() {",
			"\t$0",
			"}()${1:;}"
		],
		"description": "wrap with lambda"
	},

	"inRange": {
		"prefix": "SNIP inRange",
		"body": [
			// "auto inRange = [&](int ${1:i}, int ${2:j}) { return $1 >= 0 && $1 < ${3:n} && $2 >= 0 && $2 < ${4:m}; };"
			"auto inRange = [&](int i, int j) { return i >= 0 && i < ${1:n} && j >= 0 && j < ${2:m}; };"
		],
		"description": "inRange lambda function"
	},
	
	// 오토핫키 핫스트링으로 쓰던 것들
	"cout vector": {
		"prefix": "dkdnt ",
		"body": [
			"for (auto &e : ${1:v}) cout << e << \" \"; cout << \"\\n\";",
			""
		],
		"description": "cout vector"
	},
	
	"cout vector2D": {
		"prefix": "dkdnt2 ",
		"body": [
			"for (auto &r : ${1:v}) {",
			"\tfor (auto &e : r) cout << e << \" \";",
			"\tcout << \"\\n\";",
			"}"
		],
		"description": "cout vector2D"
	},

	"for [0:n)": {
		"prefix": "vhf ",
		"body": [
			"for (int ${1:idxName} = 0; $1 < ${2:n}; $1++) {",
			"\t$0",
			"}"
		],
		"description": "for [0:n)"
	},

	"for [1:n]": {
		"prefix": "v=f ",
		"body": [
			"for (int ${1:idxName} = 1; $1 <= ${2:n}; $1++) {",
			"\t$0",
			"}"
		],
		"description": "for [1:n]"
	},
}
```
## 단축키 지정
- __1. Ctrl + Shift + e 등으로 editorTextFocus 벗어나기__
- __2. Ctrl + k + s 후 keybinding.json 열기__

```json
[
    {
        "key": "f2",
        "command": "editor.action.rename",
        "when": "editorHasRenameProvider && editorTextFocus && !editorReadonly"
    },
    {
        "key": "ctrl+alt+n",
        "command": "python.execInTerminal"
    },

    // 파일 생성
    {
        "key": "ctrl+n",
        "command": "explorer.newFile",
        "when": "explorerViewletFocus"
    },
    {
        "key": "ctrl+shift+n",
        "command": "explorer.newFolder",
        "when": "explorerViewletFocus"
    },
    
    // 오토핫키 때문에 추가한 거긴 함
    {
        "key": "f5",
        "command": "code-runner.run",
        "when": "editorTextFocus"
    },// && editorLangId == 'ahk'"},
    {
        "key": "f6",
        "command": "code-runner.stop"
    },
    // {
    //     "key": "ctrl+shift+v",
    //     "command": "-java.action.filesExplorerPasteAction",
    //     "when": "config.editor.pasteAs.enabled && explorerViewletFocus"
    // },

    // 스니펫
    {
        "key": "shift+alt+i",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "ps default code"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+g",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "GCC optimize"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+r",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "include ext/rope"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+p",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "include ext/pb_ds"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+f",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "fastio"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+t",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "codeforces testcase for loop"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+n",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "cin n"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+m",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "cin nm"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+k",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "cin nmk"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+j",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "cin nk"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+v",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "cin v"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+2",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "cin vec2D"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+x",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "cin x"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+c",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "cin c"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+s",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "cin st"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+l",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "lambdaWrap"
        },
        "when": "editorTextFocus"
    },
    // {
    //     "key": "shift+alt+r",
    //     "command": "editor.action.insertSnippet",
    //     "args": {
    //         "langId": "cpp",
    //         "name": "inRange"
    //     },
    //     "when": "editorTextFocus"
    // },

    // 스니펫 (오토핫키 핫스트링으로 쓰던 것들)
    {
        "key": "shift+alt+,",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "for [0:n)"
        },
        "when": "editorTextFocus"
    },
    {
        "key": "shift+alt+=",
        "command": "editor.action.insertSnippet",
        "args": {
            "langId": "cpp",
            "name": "for [1:n]"
        },
        "when": "editorTextFocus"
    },
    
    // 스니펫 탭 정지점($) 이동
    {
        "key": "space",
        "command": "jumpToNextSnippetPlaceholder",
        "when": "editorTextFocus && hasNextTabstop"
    },
    {
        "key": "shift+space",
        "command": "jumpToPrevSnippetPlaceholder",
        "when": "editorTextFocus && hasPrevTabstop"
    }
]
```