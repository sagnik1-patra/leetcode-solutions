class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> candidates = {
            arr[n / 4],
            arr[n / 2],
            arr[(3 * n) / 4]
        };
        
        for (int x : candidates) {
            int left = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
            
            if (right - left > n / 4) {
                return x;
            }
        }
        
        return -1; // guaranteed not to happen
    }
};