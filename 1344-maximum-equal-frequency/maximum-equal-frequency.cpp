class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        
        unordered_map<int,int> freq;
        unordered_map<int,int> count;
        
        int maxFreq = 0;
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            
            int x = nums[i];
            
            int f = freq[x];
            if(f>0) count[f]--;
            
            freq[x]++;
            f = freq[x];
            count[f]++;
            
            maxFreq = max(maxFreq,f);
            
            int len = i+1;
            
            if(maxFreq==1 ||
               maxFreq*count[maxFreq] + 1 == len ||
               (maxFreq-1)*(count[maxFreq-1]+1) + 1 == len){
                
                ans = len;
            }
        }
        
        return ans;
    }
};