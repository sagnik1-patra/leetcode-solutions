
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int diff[52] = {0};

        for (auto& range : ranges) {
            diff[range[0]]++;
            diff[range[1] + 1]--;
        }

        int count = 0;

        for (int i = 1; i <= right; i++) {
            count += diff[i];

            if (i >= left && count == 0) {
                return false;
            }
        }

        return true;
    }
};
