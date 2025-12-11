class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        int longest = 0;
        int i = 1;

        while (i < n - 1) {

            // check if arr[i] is a peak
            if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {

                int left = i - 1;
                int right = i + 1;

                // expand left (strictly increasing)
                while (left > 0 && arr[left] > arr[left - 1])
                    left--;

                // expand right (strictly decreasing)
                while (right < n - 1 && arr[right] > arr[right + 1])
                    right++;

                longest = max(longest, right - left + 1);

                i = right; // optimization: skip to end of this mountain
            } else {
                i++;
            }
        }

        return longest;
    }
};
