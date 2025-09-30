class Solution {
public:
    vector<int> prefix;
    int total;
    mt19937 rng;

    Solution(vector<int>& w) {
        prefix.resize(w.size());
        prefix[0] = w[0];
        for (int i = 1; i < w.size(); i++) {
            prefix[i] = prefix[i-1] + w[i];
        }
        total = prefix.back();
        rng.seed(random_device{}());
    }
    
    int pickIndex() {
        uniform_int_distribution<int> dist(1, total);
        int x = dist(rng);
        int idx = lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin();
        return idx;
    }
};