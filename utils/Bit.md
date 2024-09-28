[카테고리](/README.md)
## Bit
```cpp
bool adjOneBitExist(int bit) { // 연속한 1비트 존재하는지 확인
    for (int neighborPattern = 0b11;  neighborPattern <= bit;  neighborPattern <<= 1) {
        if ((neighborPattern & bit) == neighborPattern) return true;
    }
    return false;
}
```