
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int ones = 0, zeros = 0;

        for (int x : nums) {
            if (x == 1) ones++;
        }

        int maxScore = -1;
        vector<int> ans;

        for (int i = 0; i <= nums.size(); i++) {
            int score = zeros + ones;

            if (score > maxScore) {
                maxScore = score;
                ans.clear();
                ans.push_back(i);
            }
            else if (score == maxScore) {
                ans.push_back(i);
            }

            if (i < nums.size()) {
                if (nums[i] == 0)
                    zeros++;
                else
                    ones--;
            }
        }

        return ans;
    }
};
