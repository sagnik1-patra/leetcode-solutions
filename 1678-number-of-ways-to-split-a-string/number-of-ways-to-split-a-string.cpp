class Solution {
public:
    int numWays(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }
        
        // Case 1
        if (totalOnes % 3 != 0) return 0;
        
        // Case 2: all zeros
        if (totalOnes == 0) {
            long long ways = (long long)(n - 1) * (n - 2) / 2;
            return ways % MOD;
        }
        
        // Case 3
        int k = totalOnes / 3;
        int count = 0;
        
        long long gap1 = 0, gap2 = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') count++;
            
            if (count == k) gap1++;
            else if (count == 2 * k) gap2++;
        }
        
        return (gap1 * gap2) % MOD;
    }
};