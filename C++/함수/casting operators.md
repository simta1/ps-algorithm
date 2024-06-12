### C
* ### type cast
    타입 검사를 수행하지 않아 잘못된 타입 변환 시 런타임 에러 발생할 수 있음
    ```cpp
    // C 스타일 타입 변환 (C++도 가능)
    int iVal = 10;
    double dVal = (double)iVal;
    ```
### C++
* ### type cast
    ```cpp
    // 함수 스타일 타입 변환 (C++만 가능)
    int iVal = 10;
    double dVal = double(iVal);
    ```

* ### casting operators
    1. ### static_cast
        컴파일 타입에 타입 검사를 수행하므로 잘못된 타입 변환을 사전에 감지 가능
        ```cpp
        int iVal = 10;
        double dVal = static_cast<double>(iVal);
        ```

    2. ### dynamic_cast
        기본 자료형간의 형변환은 불가능   
        ```cpp
        ```

    3. ### const_cast
        ```cpp
        ```
        
    4. ### reinterpret_cast
        ```cpp
        ```

        https://www.geeksforgeeks.org/casting-operators-in-cpp/