class Solution {
public:
    int minOperations(vector<int>& nums) {
        int totalOnes = 0;
        int maxBits = 0;
        
        for (int x : nums) {
            int bits = 0;
            
            while (x > 0) {
                if (x & 1) totalOnes++; // count 1s
                x >>= 1;
                bits++;
            }
            
            maxBits = max(maxBits, bits);
        }
        
        // doubling operations = maxBits - 1
        return totalOnes + max(0, maxBits - 1);
    }
};