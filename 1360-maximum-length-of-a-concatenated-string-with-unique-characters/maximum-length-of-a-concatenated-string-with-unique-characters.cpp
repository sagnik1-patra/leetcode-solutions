class Solution {
public:
    
    int backtrack(vector<int>& masks, int index, int mask){
        
        int maxLen = __builtin_popcount(mask);
        
        for(int i=index;i<masks.size();i++){
            
            if((mask & masks[i]) == 0){
                maxLen = max(maxLen,
                             backtrack(masks, i+1, mask | masks[i]));
            }
        }
        
        return maxLen;
    }
    
    int maxLength(vector<string>& arr) {
        
        vector<int> masks;
        
        for(string &s : arr){
            
            int mask = 0;
            bool valid = true;
            
            for(char c : s){
                int bit = c - 'a';
                
                if(mask & (1 << bit)){
                    valid = false;
                    break;
                }
                
                mask |= (1 << bit);
            }
            
            if(valid)
                masks.push_back(mask);
        }
        
        return backtrack(masks, 0, 0);
    }
};