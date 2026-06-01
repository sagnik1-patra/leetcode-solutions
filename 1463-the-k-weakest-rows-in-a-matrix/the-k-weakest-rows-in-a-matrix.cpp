class Solution {
public:
    int countSoldiers(vector<int>& row) {
        int left = 0, right = row.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (row[mid] == 1) left = mid + 1;
            else right = mid;
        }
        
        return left; // number of 1s
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        
        for (int i = 0; i < mat.size(); i++) {
            int soldiers = countSoldiers(mat[i]);
            v.push_back({soldiers, i});
        }
        
        sort(v.begin(), v.end()); // auto sorts by pair
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(v[i].second);
        }
        
        return result;
    }
};