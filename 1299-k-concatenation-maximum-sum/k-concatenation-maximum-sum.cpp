class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        const int MOD = 1e9 + 7;
        long long total = 0;

        for(int x : arr)
            total += x;

        int n = arr.size();

        // Kadane for single array
        long long curr = 0, best = 0;
        for(int i = 0; i < n; i++){
            curr = max((long long)arr[i], curr + arr[i]);
            best = max(best, curr);
        }

        if(k == 1)
            return best % MOD;

        // Kadane for two arrays
        curr = 0;
        long long best2 = 0;

        for(int i = 0; i < 2*n; i++){
            curr = max((long long)arr[i % n], curr + arr[i % n]);
            best2 = max(best2, curr);
        }

        if(total > 0)
            best2 += (long long)(k-2) * total;

        return best2 % MOD;
    }
};