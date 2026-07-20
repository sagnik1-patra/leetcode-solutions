class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<long long>> comb;
    
    // Precompute combinations (Pascal triangle)
    void buildComb(int n) {
        comb.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
            }
        }
    }
    
    long long solve(vector<int>& nums) {
        if (nums.size() <= 2) return 1;
        
        vector<int> left, right;
        int root = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        
        long long leftWays = solve(left);
        long long rightWays = solve(right);
        
        int L = left.size();
        int R = right.size();
        
        long long ways = comb[L + R][L];
        
        return (((ways * leftWays) % MOD) * rightWays) % MOD;
    }
    
    int numOfWays(vector<int>& nums) {
        buildComb(nums.size());
        return (solve(nums) - 1 + MOD) % MOD;
    }
};