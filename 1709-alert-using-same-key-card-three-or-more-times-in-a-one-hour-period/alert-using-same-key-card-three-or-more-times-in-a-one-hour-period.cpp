class Solution {
public:
    int toMinutes(string &t) {
        return stoi(t.substr(0,2)) * 60 + stoi(t.substr(3,2));
    }
    
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> mp;
        
        int n = keyName.size();
        
        // Step 1: group times
        for (int i = 0; i < n; i++) {
            mp[keyName[i]].push_back(toMinutes(keyTime[i]));
        }
        
        vector<string> result;
        
        // Step 2: process each user
        for (auto &p : mp) {
            auto &times = p.second;
            sort(times.begin(), times.end());
            
            // Step 3: check window of size 3
            for (int i = 0; i + 2 < times.size(); i++) {
                if (times[i+2] - times[i] <= 60) {
                    result.push_back(p.first);
                    break;
                }
            }
        }
        
        // Step 4: sort result
        sort(result.begin(), result.end());
        return result;
    }
};