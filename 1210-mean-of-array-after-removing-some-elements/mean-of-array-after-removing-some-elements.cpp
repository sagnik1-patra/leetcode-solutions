class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int k = n / 20;
        
        double sum = 0;
        
        for (int i = k; i < n - k; i++) {
            sum += arr[i];
        }
        
        return sum / (n - 2 * k);
    }
};