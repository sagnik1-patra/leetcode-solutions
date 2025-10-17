class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

private:
    bool solve(vector<double> nums) {
        // Base case: only one number left → check if it's close to 24
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }

        // Try every pair of numbers
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;

                // Create a new vector with remaining numbers
                vector<double> next;
                for (int k = 0; k < nums.size(); ++k)
                    if (k != i && k != j)
                        next.push_back(nums[k]);

                // Generate possible results from nums[i] and nums[j]
                for (double val : compute(nums[i], nums[j])) {
                    next.push_back(val);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }

        return false;
    }

    // All possible operations between two numbers
    vector<double> compute(double a, double b) {
        vector<double> res = {a + b, a - b, b - a, a * b};
        if (fabs(b) > 1e-6) res.push_back(a / b);
        if (fabs(a) > 1e-6) res.push_back(b / a);
        return res;
    }
};
