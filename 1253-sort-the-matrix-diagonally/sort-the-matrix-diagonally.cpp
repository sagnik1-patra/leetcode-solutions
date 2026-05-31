class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int, vector<int>> mp;
        
        // Step 1: group elements by diagonal (i - j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(mat[i][j]);
            }
        }
        
        // Step 2: sort each diagonal in descending order
        // (so we can pop from back efficiently)
        for (auto &it : mp) {
            sort(it.second.begin(), it.second.end(), greater<int>());
        }
        
        // Step 3: fill matrix back
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }
        
        return mat;
    }
};