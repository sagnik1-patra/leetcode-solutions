class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        
        const long long mod = 1e9 + 7;
        const long long base = 31;
        
        vector<long long> hash(n + 1, 0), power(n + 1, 1);
        
        // Precompute hash and powers
        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * base + (text[i] - 'a' + 1)) % mod;
            power[i + 1] = (power[i] * base) % mod;
        }
        
        // Function to get hash of substring [l, r)
        auto getHash = [&](int l, int r) {
            return (hash[r] - hash[l] * power[r - l] % mod + mod) % mod;
        };
        
        unordered_set<long long> st;
        
        // Check all even length substrings
        for (int len = 2; len <= n; len += 2) {
            int half = len / 2;
            
            for (int i = 0; i + len <= n; i++) {
                int mid = i + half;
                
                if (getHash(i, mid) == getHash(mid, i + len)) {
                    st.insert(getHash(i, i + len));
                }
            }
        }
        
        return st.size();
    }
};