class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = 0;
        for (int x : arr) total += x;

        // Total must be divisible by 3
        if (total % 3 != 0) return false;

        int target = total / 3;
        int currSum = 0;
        int count = 0;

        // We only need to find first two parts
        for (int i = 0; i < arr.size() - 1; i++) {
            currSum += arr[i];
            if (currSum == target) {
                count++;
                currSum = 0;
                if (count == 2) return true;
            }
        }

        return false;
    }
};
