class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int evenSum = 0, oddSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                evenSum += nums[i];
            else
                oddSum += nums[i];
        }

        int leftEven = 0, leftOdd = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                evenSum -= nums[i];
            else
                oddSum -= nums[i];

            int newEven = leftEven + oddSum;
            int newOdd = leftOdd + evenSum;

            if (newEven == newOdd)
                ans++;

            if (i % 2 == 0)
                leftEven += nums[i];
            else
                leftOdd += nums[i];
        }

        return ans;
    }
};