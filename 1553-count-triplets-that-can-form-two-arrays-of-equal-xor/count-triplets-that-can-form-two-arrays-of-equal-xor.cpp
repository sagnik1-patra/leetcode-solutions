class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int x = 0;
            for (int k = i; k < n; k++) {
                x ^= arr[k];
                
                if (x == 0 && k > i) {
                    count += (k - i);
                }
            }
        }
        
        return count;
    }
};