class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int ans = 0;
        
        for (int mask = 0; mask < (1 << m); mask++) {
            vector<int> balance(n, 0);
            int count = 0;
            
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    count++;
                    balance[requests[i][0]]--;
                    balance[requests[i][1]]++;
                }
            }
            
            bool valid = true;
            for (int b : balance) {
                if (b != 0) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                ans = max(ans, count);
            }
        }
        
        return ans;
    }
};