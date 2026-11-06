
class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int m = nums.size();

        for (int j = 1; j < m; j++) {
            int diff = nums[j] - nums[0];

            // diff must equal 2*k, where k > 0
            if (diff <= 0 || diff % 2 != 0)
                continue;

            int k = diff / 2;

            unordered_map<int, int> freq;

            for (int x : nums)
                freq[x]++;

            vector<int> ans;

            for (int x : nums) {
                if (freq[x] == 0)
                    continue;

                if (freq[x + 2 * k] == 0)
                    break;

                freq[x]--;
                freq[x + 2 * k]--;

                ans.push_back(x + k);
            }

            if (ans.size() == m / 2)
                return ans;
        }

        return {};
    }
};
