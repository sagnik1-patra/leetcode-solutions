class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> frequency(101, 0);

        for (int num : nums) {
            frequency[num]++;
        }

        int sum = 0;

        for (int num = 1; num <= 100; num++) {
            if (frequency[num] == 1) {
                sum += num;
            }
        }

        return sum;
    }
};