
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mp;

        // Store indices of identical elements
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        for (auto& [val, indices] : mp) {
            long long total = 0;
            int k = indices.size();

            for (int idx : indices) {
                total += idx;
            }

            long long leftSum = 0;

            for (int j = 0; j < k; j++) {
                long long i = indices[j];

                long long left = i * j - leftSum;
                long long right = (total - leftSum - i)
                                  - i * (k - j - 1);

                ans[i] = left + right;

                leftSum += i;
            }
        }

        return ans;
    }
};
