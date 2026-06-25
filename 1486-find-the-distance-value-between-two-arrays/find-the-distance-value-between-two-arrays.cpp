class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        
        int count = 0;
        
        for (int x : arr1) {
            // find closest element in arr2
            auto it = lower_bound(arr2.begin(), arr2.end(), x);
            
            bool valid = true;
            
            // check current
            if (it != arr2.end() && abs(*it - x) <= d) {
                valid = false;
            }
            
            // check previous
            if (it != arr2.begin()) {
                it--;
                if (abs(*it - x) <= d) {
                    valid = false;
                }
            }
            
            if (valid) count++;
        }
        
        return count;
    }
};