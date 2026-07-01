class Solution {
public:
    bool isSubset(unordered_set<string>& a, unordered_set<string>& b) {
        // check if a ⊆ b
        for (auto &x : a) {
            if (!b.count(x)) return false;
        }
        return true;
    }
    
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        
        vector<unordered_set<string>> sets(n);
        for (int i = 0; i < n; i++) {
            sets[i] = unordered_set<string>(
                favoriteCompanies[i].begin(),
                favoriteCompanies[i].end()
            );
        }
        
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            bool isSubsetOfAny = false;
            
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                
                // optimization: only check if j is bigger or equal
                if (sets[j].size() < sets[i].size()) continue;
                
                if (isSubset(sets[i], sets[j])) {
                    isSubsetOfAny = true;
                    break;
                }
            }
            
            if (!isSubsetOfAny) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};