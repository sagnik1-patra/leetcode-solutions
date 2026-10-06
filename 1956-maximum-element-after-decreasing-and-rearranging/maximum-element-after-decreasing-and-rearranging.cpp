class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());

        // First element must be 1
        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++) {
            
            // Current value can be at most previous + 1
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }

        return arr.back();
    }
};