class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        
        int g = nums[0];
        
        for(int x : nums){
            g = gcd(g, x);
            
            if(g == 1) return true;
        }
        
        return g == 1;
    }
};