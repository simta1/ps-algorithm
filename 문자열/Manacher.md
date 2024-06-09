[카테고리](/README.md)
### Manacher
```cpp
class Manacher {
private:
    vector<int> radius;

public:
    Manacher(const string &orig) : radius(orig.size() << 1 | 1) {
        string st = "#";
        for (auto &c : orig) {
            st += c;
            st += '#';
        }
        
        int maxJ = 0;

        for (int i = 1; i < st.size(); i++) {
            if (maxJ + radius[maxJ] < i) radius[i] = 0;
            else radius[i] = min(radius[2 * maxJ - i], maxJ + radius[maxJ] - i);
            
            while (i - radius[i] - 1 >= 0 && i + radius[i] + 1 < st.size() && st[i - radius[i] - 1] == st[i + radius[i] + 1]) ++radius[i];

            if (maxJ + radius[maxJ] < i + radius[i]) maxJ = i;
        }
    }

    int longestPalindromeLength() {
        return *max_element(radius.begin(), radius.end());
    }

    long long countPalindromeSubstring() {
        long long res = 0;
        for (auto &r : radius) res += r + 1 >> 1;
        return res;
    }
};
```
### 시간복잡도 
$O(N)$   

### 주의사항
문자열 사이에 '#' 끼워넣을 때 주의   
st += (c + '#'); 으로 하면 c와 '#'이 각각 char형이기 때문에, c와 '#'의 아스키코드를 합한 값에 해당하는 char형 문자 하나가 st의 끝에 추가되어 st가 제대로 만들어지지 않음   
st += (c + "#"); 의 경우에도 이유는 모르겠으나 st가 제대로 만들어지지 않음   
그냥 st += c, st += '#';으로 나누어 적는 게 낫다.   

### 사용관련
i를 중심으로 하는 최장 펠린드롬 부분문자열의 길이는 radius[i]   
따라서 i를 중심으로 하는 펠린드롬 부분문자열의 개수는 (radius[i] + 1) / 2개   


### 백준문제
[가장 긴 팰린드롬 부분 문자열](https://www.acmicpc.net/problem/13275)   
[#15164번_제보](https://www.acmicpc.net/problem/16163) - 회문 부분 문자열의 개수   

### 원리
radius[i]가 펠린드롬의 길이와 동일한 이유   
* if (i & 1)인 경우   
'#'이 삽입된 문자열 st에서 i & 1인 경우 st[i]는 orig의 문자   
ex) #a#b#a#, radius[i] = 3   
양쪽으로 맨끝의 #을 제외하면 한쪽으로 (radius[i] - 1)만큼의 문자 존재   
'#'제외하면 한 쪽엔 (radius[i] - 1) / 2만큼의 문자 존재   
반대쪽의 문자까지 고려하면 (radius[i] - 1) / 2 * 2 = (radius[i] - 1)개의 문자 존재   
$\therefore$ 중앙지점에 있는 문자 1개 고려하면 (radius[i] - 1) + 1 = radius[i]개   

* if (~i & 1)인 경우   
'#'이 삽입된 문자열 st에서 ~i & 1인 경우 st[i]는 삽입한 문자 '#'에 해당   
ex) #a#a#, radius[i] = 2   
한쪽으로 radius[i]만큼의 문자 존재   
'#'제외하면 한 쪽엔 radius[i] / 2만큼의 문자 존재   
반대쪽의 문자까지 고려하면 radius[i] / 2 * 2 = radius[i]개의 문자 존재   
$\therefore$ 중앙지점에 있는 문자는 '#'이므로 고려되지 않고, 따라서 radius[i]개   

### 참고문헌
https://m.blog.naver.com/jqkt15/222108415284   
https://nicotina04.tistory.com/250
https://www.crocus.co.kr/1075   