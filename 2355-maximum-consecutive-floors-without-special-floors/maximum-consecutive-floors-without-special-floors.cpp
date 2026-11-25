class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());

        int n = special.size();

        int ans = max(special[0] - bottom,
                      top - special[n - 1]);

        for (int i = 1; i < n; i++) {
            int gap = special[i] - special[i - 1] - 1;

            ans = max(ans, gap);
        }

        return ans;
    }
};