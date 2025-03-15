[카테고리](/README.md)
## std::array
일차원에서는 reserve()만 잘 해준다면 vector를 써도 array에 비해 오버헤드가 거의 없다.   
하지만 일차원이라고 해도 원소를 별로 담지 않을 거라면(대충 10개 이하) 유의미한 성능 차이를 보이며 array를 쓰는 것이 더 낫다.   
다차원에선 vector의 오버헤드가 꽤나 커진다. 정말 많이 커진다.   

```cpp
array<int, 4> v = {1, 2, 3, 4};
for (auto e : v) cout << e << " ";
```

## array 초기화
```cpp
array<pair<int, int>, 4> v = {pair<int, int>{1, 2}, pair<int, int>{2, 3}}; // 정상적으로 컴파일 됨
array<pair<int, int>, 4> v = {{1, 2}, {2, 3}}; // 오류 발생
array<pair<int, int>, 4> v = {{{1, 2}, {2, 3}}}; // 정상적으로 컴파일 됨
for (auto [a, b] : v) cout << a << " " << b << "\n";

const array<pair<int, int>, 4> dpos = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}}; // 이런식으로 이중 중괄호 해줘야 됨
```
어떻게 초기화해야 되는 건지 모르겠어서 gpt한테 물어봤더니:
```
std::array<T, N>은 내부적으로 T[N] 배열을 감싸는 구조이므로,
std::pair<int, int> 타입의 요소들을 리스트 초기화할 때 이중 중괄호 {{}}를 사용해야 합니다.
{}만 사용하면 std::array의 생성자가 std::initializer_list<std::pair<int, int>>를 받는 형태로 해석될 수도 있는데, std::array는 std::initializer_list를 직접 지원하지 않기 때문에 컴파일 오류가 발생합니다.
```
모르겠당 ㅋ

## array 초기화 없이 선언
`vector<int> v(N);`에서는 모든 값이 0으로 초기화되지만 `array<int, N> v;`는 자동으로 0으로 초기화되지 않고 쓰레기값이 남는다.   
`array<int, N> v = {};`처럼 해야 0으로 초기화된다.   