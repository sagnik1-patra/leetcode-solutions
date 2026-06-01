class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int target = k * threshold;
        int sum = 0, count = 0;
        
        // Step 1: first window
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        
        if (sum >= target) count++;
        
        // Step 2: sliding window
        for (int i = k; i < arr.size(); i++) {
            sum += arr[i];
            sum -= arr[i - k];
            
            if (sum >= target) count++;
        }
        
        return count;
    }
};