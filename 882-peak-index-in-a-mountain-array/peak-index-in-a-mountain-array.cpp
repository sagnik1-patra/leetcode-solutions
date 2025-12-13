class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // Peak is on the right side
                low = mid + 1;
            } else {
                // Peak is at mid or on the left side
                high = mid;
            }
        }

        // low == high -> peak index
        return low;
    }
};
