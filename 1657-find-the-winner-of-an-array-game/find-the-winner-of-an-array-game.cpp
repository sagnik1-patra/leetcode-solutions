class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int curr = arr[0];
        int win = 0;
        
        int n = arr.size();
        
        for (int i = 1; i < n; i++) {
            if (arr[i] > curr) {
                curr = arr[i];
                win = 1;
            } else {
                win++;
            }
            
            if (win == k) return curr;
        }
        
        // if k is large → max element wins
        return curr;
    }
};