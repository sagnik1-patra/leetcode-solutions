class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        
        // Step 1: sort
        sort(temp.begin(), temp.end());
        
        // Step 2: assign ranks
        unordered_map<int, int> rank;
        int r = 1;
        
        for (int x : temp) {
            if (rank.find(x) == rank.end()) {
                rank[x] = r++;
            }
        }
        
        // Step 3: map back
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rank[arr[i]];
        }
        
        return arr;
    }
};