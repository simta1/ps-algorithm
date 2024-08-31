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
			"using ll = long long;",
			"using pii = pair<int, int>;",
			"using pll = pair<ll, ll>;",
			"using tii = tuple<int, int, int>;",
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

	// 오토핫키 핫스트링으로 쓰던 것들
	"cout vector": {
		"prefix": "dkdnt",
		"body": [
			"for (auto &e : ${1:v}) cout << e << \" \"; cout << \"\\n\";",
			"",
			""
		],
		"description": "cout vector"
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

    // 스니펫 (오토핫키 핫스트링으로 쓰던 것들)
    {
        "key": "shift+alt+f",
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