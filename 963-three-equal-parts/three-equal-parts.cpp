class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int totalOnes = 0;

        for (int x : arr) totalOnes += x;

        // Case 1: total ones not divisible by 3
        if (totalOnes % 3 != 0) return {-1, -1};

        // Case 2: all zeros
        if (totalOnes == 0) return {0, n - 1};

        int k = totalOnes / 3;
        int first = -1, second = -1, third = -1;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                count++;
                if (count == 1) first = i;
                else if (count == k + 1) second = i;
                else if (count == 2 * k + 1) third = i;
            }
        }

        // Compare the three parts
        while (third < n) {
            if (arr[first] != arr[second] || arr[second] != arr[third])
                return {-1, -1};
            first++;
            second++;
            third++;
        }

        return {first - 1, second};
    }
};
