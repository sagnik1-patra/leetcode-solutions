class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> result;
        
        for (int den = 2; den <= n; den++) {
            for (int num = 1; num < den; num++) {
                if (__gcd(num, den) == 1) {
                    result.push_back(to_string(num) + "/" + to_string(den));
                }
            }
        }
        
        return result;
    }
};