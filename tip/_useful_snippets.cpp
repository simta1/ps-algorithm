// 부호에 따라 1, 0, -1 변환
int sign = (x > 0) - (x < 0); // int -> sign(1, 0, -1)
char c = "-0+"[sign + 1]; // sign -> char('-', '0', '+')
int sign = (x >> 31) - (-x >> 31); // int -> sign(1, 0, -1)

// xy좌표 사분면 변환
assert(x != 0 && y != 0);
int quadrant = 1 + (y < 0) * 2 + (x * y < 0);

// 소수점 n자리에서 올림
cout << fixed << setprecision(2) << ans + 0.00499999 << "\n"; // 올림해서 둘째 자리까지 출력

// cyclic 순회
for (int i = 0, j = n - 1; i < n; j = i++) {}

// 정수 이등분
int half1 = x + 1 >> 1;
int half2 = x >> 1;

// 오차 없는 ceil, round
return (a + b - 1) / b; // ceil(a/b)
return (a + b / 2) / b; // round(a/b)

// 오차 없는 log2
__lg(n) // n=0일 때 UB

// v.begin() + idx가 v.begin()으로 이동하도록 rotate됨
rotate(v.begin(), v.begin() + idx, v.end());

// bitset
._Find_first()
._Find_next(int i)

// 삼각함수
const double PI = acos(-1);
auto rad = deg / 180 * PI;
cout << sin(rad) << " " << cos(rad); // 라디안 단위임

// atan, atan2
atan(y / x) // -PI/2 ~ PI/2 반환
atan2(y, x) // -PI ~ PI 반환 // 첫번째 매개변수가 y임
