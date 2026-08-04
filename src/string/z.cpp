template <typename Container>
vector<int> getZ(const Container &st) { // O(N)
    vector<int> z(st.size());
    for (int i = 1, p = 0; i < st.size(); i++) {
        if (i <= p + z[p] - 1) z[i] = min(p + z[p] - 1 - i + 1, z[i - p]);
        while (i + z[i] < st.size() && st[z[i]] == st[i + z[i]]) ++z[i];
        if (p + z[p] < i + z[i]) p = i;
    }
    z[0] = st.size();
    return z;
} // z[i] = lcp(st, st[i:])