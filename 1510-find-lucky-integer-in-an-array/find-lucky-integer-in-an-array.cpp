class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501, 0);
        
        // Step 1: count frequency
        for (int x : arr) {
            freq[x]++;
        }
        
        int ans = -1;
        
        // Step 2: check lucky numbers
        for (int i = 1; i <= 500; i++) {
            if (freq[i] == i) {
                ans = max(ans, i);
            }
        }
        
        return ans;
    }
};