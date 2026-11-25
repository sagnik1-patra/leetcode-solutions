class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks,
                    int additionalRocks) {

        int n = capacity.size();
        vector<int> remaining(n);

        for (int i = 0; i < n; i++) {
            remaining[i] = capacity[i] - rocks[i];
        }

        sort(remaining.begin(), remaining.end());

        int count = 0;

        for (int required : remaining) {
            if (additionalRocks >= required) {
                additionalRocks -= required;
                count++;
            } else {
                break;
            }
        }

        return count;
    }
};