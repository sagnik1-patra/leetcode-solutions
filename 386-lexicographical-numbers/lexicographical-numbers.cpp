class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        res.reserve(n);

        int curr = 1;
        for (int i = 0; i < n; i++) {
            res.push_back(curr);

            if (curr * 10 <= n) {
                curr *= 10;  // go deeper
            } else {
                if (curr >= n) {
                    curr /= 10;
                }
                ++curr;
                while (curr % 10 == 0) {
                    curr /= 10; // backtrack
                }
            }
        }
        return res;
    }
};
