
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;

        for (string row : bank) {
            int curr = 0;

            for (char c : row) {
                if (c == '1') {
                    curr++;
                }
            }

            if (curr > 0) {
                ans += prev * curr;
                prev = curr;
            }
        }

        return ans;
    }
};
