class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        
        vector<int> len(n + 2, 0);   // group lengths
        vector<int> count(n + 1, 0); // count of groups
        
        int ans = -1;
        
        for (int step = 0; step < n; step++) {
            int pos = arr[step];
            
            int left = len[pos - 1];
            int right = len[pos + 1];
            
            int total = left + right + 1;
            
            // remove old groups
            if (left > 0) count[left]--;
            if (right > 0) count[right]--;
            
            // add new group
            count[total]++;
            
            // update boundaries
            len[pos - left] = total;
            len[pos + right] = total;
            
            // check if group of size m exists
            if (count[m] > 0) {
                ans = step + 1;
            }
        }
        
        return ans;
    }
};