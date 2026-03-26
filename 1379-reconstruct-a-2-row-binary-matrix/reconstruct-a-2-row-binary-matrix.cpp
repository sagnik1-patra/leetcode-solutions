class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<int> top(n, 0), bottom(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                if (upper <= 0 || lower <= 0) return {};
                top[i] = 1;
                bottom[i] = 1;
                --upper; --lower;
            } else if (colsum[i] == 1) {
                if (upper >= lower && upper > 0) {
                    top[i] = 1;
                    --upper;
                } else if (lower > 0) {
                    bottom[i] = 1;
                    --lower;
                } else {
                    return {}; // no place for 1
                }
            }
        }
        
        if (upper != 0 || lower != 0) return {};
        return {top, bottom};
    }
};