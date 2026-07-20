class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int waiting = 0;
        int profit = 0, maxProfit = 0;
        int ans = -1;
        int rotations = 0;
        int i = 0;
        int n = customers.size();
        
        while (i < n || waiting > 0) {
            
            // add arriving customers
            if (i < n) {
                waiting += customers[i];
                i++;
            }
            
            // board people
            int board = min(4, waiting);
            waiting -= board;
            
            rotations++;
            
            // update profit
            profit += board * boardingCost - runningCost;
            
            // check max profit
            if (profit > maxProfit) {
                maxProfit = profit;
                ans = rotations;
            }
        }
        
        return maxProfit > 0 ? ans : -1;
    }
};