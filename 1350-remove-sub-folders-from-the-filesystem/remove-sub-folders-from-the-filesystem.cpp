class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        sort(folder.begin(), folder.end());
        
        vector<string> result;
        result.push_back(folder[0]);
        
        for(int i = 1; i < folder.size(); i++){
            
            string prev = result.back();
            string prefix = prev + "/";
            
            if(folder[i].substr(0, prefix.size()) != prefix){
                result.push_back(folder[i]);
            }
        }
        
        return result;
    }
};