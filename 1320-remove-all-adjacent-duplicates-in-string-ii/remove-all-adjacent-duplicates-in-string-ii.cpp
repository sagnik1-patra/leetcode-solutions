class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        vector<pair<char,int>> st;
        
        for(char c : s){
            
            if(!st.empty() && st.back().first == c){
                st.back().second++;
                
                if(st.back().second == k)
                    st.pop_back();
            }
            else{
                st.push_back({c,1});
            }
        }
        
        string result = "";
        
        for(auto &p : st)
            result.append(p.second, p.first);
        
        return result;
    }
};