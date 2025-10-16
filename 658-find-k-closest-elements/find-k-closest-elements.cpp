class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;

        // Binary search to find the left boundary of the window
        while (left < right) {
            int mid = left + (right - left) / 2;

            // Compare distances between x and the boundaries
            if (x - arr[mid] > arr[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }

        // Return the k closest elements
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
