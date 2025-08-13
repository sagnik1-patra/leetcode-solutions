class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails; // tails[i] = smallest tail of any LIS of length i+1
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }
        return (int)tails.size();
    }
};
