class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        // For each index i, determine range of k that causes a "bad" rotation
        for (int i = 0; i < n; i++) {
            int low = (i - nums[i] + 1 + n) % n; // start of bad interval
            int high = (i + 1) % n;              // end of bad interval

            diff[low]--;  // losing a point
            diff[high]++; // regaining after high

            if (low > high) {  // interval wraps around
                diff[0]--;
            }
        }

        // Apply prefix sum to compute actual scores
        int maxScore = INT_MIN, bestK = 0, score = 0;
        for (int k = 0; k < n; k++) {
            score += diff[k];
            if (score > maxScore) {
                maxScore = score;
                bestK = k;
            }
        }
        return bestK;
    }
};