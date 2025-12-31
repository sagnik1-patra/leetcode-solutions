class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int i = num.size() - 1;
        int carry = 0;

        while (i >= 0 || k > 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += num[i--];
            }

            if (k > 0) {
                sum += k % 10;
                k /= 10;
            }

            result.push_back(sum % 10);
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
