
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> ans;

        int half = (intLength + 1) / 2;

        long long start = 1;

        for (int i = 1; i < half; i++) {
            start *= 10;
        }

        long long total = 9 * start;

        for (int q : queries) {

            if (q > total) {
                ans.push_back(-1);
                continue;
            }

            long long num = start + q - 1;

            string left = to_string(num);
            string right = left;

            if (intLength % 2 == 1) {
                right.pop_back();
            }

            reverse(right.begin(), right.end());

            ans.push_back(stoll(left + right));
        }

        return ans;
    }
};
