class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        
        int n = piles.size();
        int left = 0;
        int right = n - 1;
        int ans = 0;
        
        while (left < right) {
            right--;             // Alice takes largest
            ans += piles[right]; // You take next largest
            right--;
            left++;              // Bob takes smallest
        }
        
        return ans;
    }
};