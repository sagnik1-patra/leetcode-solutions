class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> rem(k, 0);

        for (int x : arr) {
            int r = ((x % k) + k) % k;
            rem[r]++;
        }

        if (rem[0] % 2 != 0) return false;

        for (int r = 1; r < k; r++) {
            if (rem[r] != rem[k - r]) {
                return false;
            }
        }

        return true;
    }
};