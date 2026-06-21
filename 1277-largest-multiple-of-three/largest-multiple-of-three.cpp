class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<vector<int>> mod(3);
        int sum = 0;
        
        // Step 1: group by remainder
        for (int d : digits) {
            sum += d;
            mod[d % 3].push_back(d);
        }
        
        // sort each group ascending (for easy removal)
        for (int i = 0; i < 3; i++) {
            sort(mod[i].begin(), mod[i].end());
        }
        
        int rem = sum % 3;
        
        // Step 2: remove minimal digits
        if (rem == 1) {
            if (!mod[1].empty()) {
                mod[1].erase(mod[1].begin());
            } else if (mod[2].size() >= 2) {
                mod[2].erase(mod[2].begin(), mod[2].begin() + 2);
            } else return "";
        }
        else if (rem == 2) {
            if (!mod[2].empty()) {
                mod[2].erase(mod[2].begin());
            } else if (mod[1].size() >= 2) {
                mod[1].erase(mod[1].begin(), mod[1].begin() + 2);
            } else return "";
        }
        
        // Step 3: collect remaining digits
        vector<int> res;
        for (int i = 0; i < 3; i++) {
            for (int d : mod[i]) res.push_back(d);
        }
        
        if (res.empty()) return "";
        
        // Step 4: sort descending
        sort(res.rbegin(), res.rend());
        
        // handle leading zeros
        if (res[0] == 0) return "0";
        
        // convert to string
        string ans = "";
        for (int d : res) ans += to_string(d);
        
        return ans;
    }
};