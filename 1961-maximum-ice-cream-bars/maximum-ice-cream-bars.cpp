class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        // Find maximum cost
        int maxCost = 0;
        
        for (int cost : costs) {
            maxCost = max(maxCost, cost);
        }
        
        // Counting array
        vector<int> count(maxCost + 1, 0);
        
        // Count frequency of each cost
        for (int cost : costs) {
            count[cost]++;
        }
        
        int bars = 0;
        
        // Start buying from cheapest cost
        for (int price = 1; price <= maxCost; price++) {
            
            if (count[price] == 0)
                continue;
            
            // Maximum bars of this price we can afford
            int canBuy = min(count[price], coins / price);
            
            bars += canBuy;
            coins -= canBuy * price;
            
            // Cannot afford anything else
            if (coins < price)
                break;
        }
        
        return bars;
    }
};