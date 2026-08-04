void grayCode(int n) { // O(2^N)
    for (int i = 0; i < (1 << n); ++i) {
        int gray = i ^ (i >> 1);
        cout << bitset<32>(gray).to_string().substr(32 - n) << "\n";
    }
}