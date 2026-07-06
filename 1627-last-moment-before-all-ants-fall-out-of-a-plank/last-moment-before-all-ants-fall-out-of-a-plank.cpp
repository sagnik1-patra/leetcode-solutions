class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;

        for (int pos : left) {
            ans = max(ans, pos);
        }

        for (int pos : right) {
            ans = max(ans, n - pos);
        }

        return ans;
    }
};