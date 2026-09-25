class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int pos = 0;

        for (auto& group : groups) {
            bool found = false;

            while (pos + group.size() <= nums.size()) {
                bool match = true;

                for (int j = 0; j < group.size(); j++) {
                    if (nums[pos + j] != group[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    pos += group.size();
                    found = true;
                    break;
                }

                pos++;
            }

            if (!found) {
                return false;
            }
        }

        return true;
    }
};