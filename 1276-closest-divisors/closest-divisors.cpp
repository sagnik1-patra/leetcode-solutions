class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> ans;
        int bestDiff = INT_MAX;
        
        for (int x = num + 1; x <= num + 2; x++) {
            for (int i = sqrt(x); i >= 1; i--) {
                if (x % i == 0) {
                    int a = i;
                    int b = x / i;
                    
                    if (abs(a - b) < bestDiff) {
                        bestDiff = abs(a - b);
                        ans = {a, b};
                    }
                    break; // first valid pair is closest
                }
            }
        }
        
        return ans;
    }
};