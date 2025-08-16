class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort by width asc, and for equal widths by height DESC
        // (to avoid counting same-width envelopes in LIS)
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[1] > b[1];
             });

        // Now find LIS on heights
        vector<int> tails;
        for (const auto& e : envelopes) {
            int h = e[1];
            auto it = lower_bound(tails.begin(), tails.end(), h);
            if (it == tails.end()) tails.push_back(h);
            else *it = h;
        }
        return (int)tails.size();
    }
};
