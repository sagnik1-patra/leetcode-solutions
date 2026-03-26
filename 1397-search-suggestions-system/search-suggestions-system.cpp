class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());  // Step 1: sort lexicographically
        vector<vector<string>> result;
        string prefix = "";
        
        for(char c : searchWord){
            prefix += c;  // Current prefix
            vector<string> suggestions;
            
            // Use lower_bound to find the first product >= prefix
            auto it = lower_bound(products.begin(), products.end(), prefix);
            
            // Take up to 3 products that match the prefix
            for(int i = 0; i < 3 && it + i != products.end(); i++){
                if((it + i)->substr(0, prefix.size()) == prefix)
                    suggestions.push_back(*(it + i));
                else
                    break;
            }
            
            result.push_back(suggestions);
        }
        
        return result;
    }
};