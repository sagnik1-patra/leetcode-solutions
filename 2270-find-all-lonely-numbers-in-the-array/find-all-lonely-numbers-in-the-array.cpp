
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<int> ans;

        for (int num : nums) {
            if (freq[num] == 1 &&
                freq.find(num - 1) == freq.end() &&
                freq.find(num + 1) == freq.end()) {

                ans.push_back(num);
            }
        }

        return ans;
    }
};
