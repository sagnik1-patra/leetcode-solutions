class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: prefix
        int left = 0;
        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            left++;
        }
        
        // already sorted
        if (left == n - 1) return 0;
        
        // Step 2: suffix
        int right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }
        
        // Step 3: initial answer
        int ans = min(n - left - 1, right);
        
        // Step 4: merge
        int i = 0, j = right;
        
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                ans = min(ans, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        
        return ans;
    }
};