class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        string temp;
        int open = 0;
        
        // Pass 1: remove extra ')'
        for(char c : s){
            
            if(c == '('){
                open++;
                temp.push_back(c);
            }
            else if(c == ')'){
                
                if(open > 0){
                    open--;
                    temp.push_back(c);
                }
            }
            else{
                temp.push_back(c);
            }
        }
        
        // Pass 2: remove extra '('
        string result;
        
        for(int i = temp.size()-1; i >= 0; i--){
            
            if(temp[i] == '(' && open > 0){
                open--;
                continue;
            }
            
            result.push_back(temp[i]);
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};