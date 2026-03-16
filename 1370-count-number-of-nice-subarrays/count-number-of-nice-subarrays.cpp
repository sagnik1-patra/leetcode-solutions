class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        freq[0] = 1;
        
        int prefix = 0;
        int result = 0;
        
        for(int x : nums){
            
            prefix += x % 2;
            
            if(freq.count(prefix - k))
                result += freq[prefix - k];
            
            freq[prefix]++;
        }
        
        return result;
    }
};