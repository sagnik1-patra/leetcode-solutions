class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<queue<int>> pos(10);
        
        // store positions of digits in s
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - '0'].push(i);
        }
        
        for (char c : t) {
            int d = c - '0';
            
            if (pos[d].empty()) return false;
            
            int idx = pos[d].front();
            pos[d].pop();
            
            // check smaller digits
            for (int smaller = 0; smaller < d; smaller++) {
                if (!pos[smaller].empty() && pos[smaller].front() < idx) {
                    return false;
                }
            }
        }
        
        return true;
    }
};