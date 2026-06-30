class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int j = 0;
        
        for (int i = 1; i <= n && j < target.size(); i++) {
            if (i == target[j]) {
                ops.push_back("Push");
                j++;
            } else {
                ops.push_back("Push");
                ops.push_back("Pop");
            }
        }
        
        return ops;
    }
};