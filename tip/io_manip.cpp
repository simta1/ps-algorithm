// setfill은 패딩문자, setw는 패딩길이 설정   
cout << setfill('0') << setw(3) << num << "\n";

// 진법
cout << oct << 10 << "\n"; // 12 // 8진수, octal
cout << dec << 10 << "\n"; // 10 // 10진수, decimal
cout << hex << 10 << "\n"; // a // 12진수, hexadecimal

// 일시적: setw
// 영구적: setfill, fixed, setprecision, oct, dec, hex