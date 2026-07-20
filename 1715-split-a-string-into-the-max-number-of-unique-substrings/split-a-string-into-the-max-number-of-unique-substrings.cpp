class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> used;
        int ans = 0;
        
        function<void(int)> dfs = [&](int start) {
            // pruning
            if (used.size() + (s.size() - start) <= ans) return;
            
            if (start == s.size()) {
                ans = max(ans, (int)used.size());
                return;
            }
            
            string temp = "";
            for (int i = start; i < s.size(); i++) {
                temp += s[i];
                
                if (!used.count(temp)) {
                    used.insert(temp);
                    dfs(i + 1);
                    used.erase(temp);
                }
            }
        };
        
        dfs(0);
        return ans;
    }
};