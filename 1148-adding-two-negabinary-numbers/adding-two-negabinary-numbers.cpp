class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        int carry = 0;

        vector<int> res;

        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;

            if (i >= 0) sum += arr1[i--];
            if (j >= 0) sum += arr2[j--];

            int bit = sum & 1;
            res.push_back(bit);

            carry = (sum - bit) / -2;
        }

        // Remove leading zeros
        while (res.size() > 1 && res.back() == 0) {
            res.pop_back();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
