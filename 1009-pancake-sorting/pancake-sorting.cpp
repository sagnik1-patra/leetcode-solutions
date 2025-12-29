class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> flips;
        int n = arr.size();

        // Work from largest value to smallest
        for (int curr = n; curr > 1; curr--) {
            // Find index of curr element
            int idx = 0;
            for (int i = 0; i < curr; i++) {
                if (arr[i] == curr) {
                    idx = i;
                    break;
                }
            }

            // If already in correct position, continue
            if (idx == curr - 1) continue;

            // Step 1: Bring curr to front (if not already)
            if (idx != 0) {
                reverse(arr.begin(), arr.begin() + idx + 1);
                flips.push_back(idx + 1);
            }

            // Step 2: Move curr to its correct position
            reverse(arr.begin(), arr.begin() + curr);
            flips.push_back(curr);
        }

        return flips;
    }
};
