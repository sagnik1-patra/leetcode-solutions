
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());

        return solve(n, sums);
    }

    vector<int> solve(int n, vector<int>& sums) {
        if (n == 0) {
            return {};
        }

        int diff = sums[1] - sums[0];

        map<int, int> freq;

        for (int x : sums) {
            freq[x]++;
        }

        vector<int> without, with;

        for (int x : sums) {
            if (freq[x] == 0) {
                continue;
            }

            without.push_back(x);
            with.push_back(x + diff);

            freq[x]--;
            freq[x + diff]--;
        }

        // Check which group contains the empty subset sum
        if (find(without.begin(), without.end(), 0)
            != without.end()) {

            vector<int> ans = solve(n - 1, without);
            ans.push_back(diff);

            return ans;
        }

        vector<int> ans = solve(n - 1, with);
        ans.push_back(-diff);

        return ans;
    }
};
