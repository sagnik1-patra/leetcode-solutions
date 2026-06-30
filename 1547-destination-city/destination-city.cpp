class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> starts;
        
        // store all starting cities
        for (auto &p : paths) {
            starts.insert(p[0]);
        }
        
        // find city that is never a start
        for (auto &p : paths) {
            if (!starts.count(p[1])) {
                return p[1];
            }
        }
        
        return "";
    }
};