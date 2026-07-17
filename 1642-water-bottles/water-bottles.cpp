class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = 0;
        int empty = 0;
        
        while (numBottles > 0) {
            total += numBottles;       // drink all
            empty += numBottles;       // get empties
            
            numBottles = empty / numExchange; // exchange
            empty = empty % numExchange;      // leftover
        }
        
        return total;
    }
};