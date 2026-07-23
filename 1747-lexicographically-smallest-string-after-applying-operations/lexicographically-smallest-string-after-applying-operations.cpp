class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> vis;
        
        q.push(s);
        vis.insert(s);
        
        string ans = s;
        int n = s.size();
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            // update answer
            if (curr < ans) ans = curr;
            
            // Operation 1: Add to odd indices
            string addStr = curr;
            for (int i = 1; i < n; i += 2) {
                addStr[i] = (addStr[i] - '0' + a) % 10 + '0';
            }
            
            if (!vis.count(addStr)) {
                vis.insert(addStr);
                q.push(addStr);
            }
            
            // Operation 2: Rotate
            string rotateStr = curr.substr(n - b) + curr.substr(0, n - b);
            
            if (!vis.count(rotateStr)) {
                vis.insert(rotateStr);
                q.push(rotateStr);
            }
        }
        
        return ans;
    }
};