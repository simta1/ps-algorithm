[카테고리](/README.md)
## vim script
vscode neovim extension 사용 중   
`vim ~/.config/nvim/init.vim`   
```vim
set ignorecase
set smartcase

call plug#begin('~/.config/nvim/plugged')
Plug 'tpope/vim-surround'
Plug 'phaazon/hop.nvim'
Plug 'nvim-tree/nvim-tree.lua'
call plug#end()

" Surround
nmap ds <Plug>Dsurround
nmap cs <Plug>Csurround
nmap ys <Plug>Ysurround
nmap yss <Plug>Yssurround

" Hop (easymotion 대용)
lua << EOF
require'hop'.setup()
EOF

nmap <Leader>w <cmd>lua require'hop'.hint_words()<cr>
xmap <Leader>w <cmd>lua require'hop'.hint_words()<cr>

function! GenerateCinCodeRange(startLine, endLine)
  let l:cin_line = ""
  for i in range(a:startLine, a:endLine)
    let l:line = getline(i)
    let l:indent = matchstr(l:line, '^\s*')
    let l:match = matchlist(l:line, '\(int\|float\|double\|string\|char\|bool\|ll\|ld\|ui\|ull\)\s\+\(.\+\);')

    if len(l:match) >= 2
      let l:variables = l:match[2]
      let l:variables = split(l:variables, '\s*,\s*')

      if l:cin_line == ""
        let l:cin_line = l:indent . "cin >> " . join(l:variables, " >> ")
      else
        let l:cin_line .= " >> " . join(l:variables, " >> ")
      endif
    endif
  endfor

  if l:cin_line != ""
    let l:cin_line .= ";"
    call append(a:endLine, l:cin_line)
	 call cursor(a:endLine + 1, len(l:cin_line))
  else
	 echo "No valid variable declaration found"
  endif
endfunction

xnoremap <leader>in :<C-u>call GenerateCinCodeRange(line("'<"), line("'>"))<CR>
nnoremap <leader>in :call GenerateCinCodeRange(line('.'), line('.'))<CR>

nnoremap <silent> <leader>/ :nohlsearch<CR>
nnoremap <leader>r :source $MYVIMRC<CR>
```

GenerateCinCodeRange는 선언된 변수 추출해서 cin으로 입력받는 코드 생성해주는 함수임   

### 사용예시 1
```cpp
int x, y, z;
```
변수 선언해둔 줄에 커서를 두고 Normal mode에서 `<leader>in` 입력하면 아래처럼 입력받는 코드 삽입됨
```cpp
int x, y, z;
cin >> x >> y >> z;
```

### 사용예시 2
여러 줄에 걸쳐 변수가 선언되어있는 경우 입력받을 변수들이 선언되어 있는 줄을 전부 visual모드로 선택한 뒤 `<leader>in` 입력하면 됨

```cpp
int n, m;
ll k;
double x, y, z;
```
위 코드의 맨 윗줄에 마우스 커서가 있다고 가정할 때 normal mode에서 `V2j<leader>in` 해주면 아래처럼 코드 삽입됨
```cpp
int n, m;
ll k;
double x, y, z;
cin >> n >> m >> k >> x >> y >> z;
```

### 이걸 만든 계기가 된 문제
[터렛](https://www.acmicpc.net/problem/1002) : (`x1, y1, r1, x2, y2, r2` 입력받아야 됨)   

애초에 어려운 문제라서 푸는 데 시간이 오래 걸린다면 입출력 코드 조금 빨리 짜도 별 의미가 없겠지만,   
UCPC 첫번째 문제 등 1분 내로 풀리는 문제에선 이런 시간 줄이는 게 퍼솔에 꽤 큰 도움이 됨   


근데 저런 상황 아니어도 가끔 변수 입력 많은 문제 나와서 유용함   