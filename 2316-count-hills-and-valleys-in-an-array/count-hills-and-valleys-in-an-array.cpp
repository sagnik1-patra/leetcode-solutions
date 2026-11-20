
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr;

        // Remove consecutive duplicates
        for (int x : nums) {
            if (arr.empty() || arr.back() != x) {
                arr.push_back(x);
            }
        }

        int count = 0;

        for (int i = 1; i < arr.size() - 1; i++) {

            // Hill
            if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                count++;
            }

            // Valley
            else if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
                count++;
            }
        }

        return count;
    }
};
