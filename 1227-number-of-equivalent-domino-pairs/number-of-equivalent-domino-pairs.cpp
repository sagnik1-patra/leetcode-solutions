class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> freq;
        int ans = 0;

        for (auto &d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            int key = a * 10 + b;   // unique encoding since values are 1..9

            ans += freq[key];      // count pairs formed so far
            freq[key]++;
        }

        return ans;
    }
};
