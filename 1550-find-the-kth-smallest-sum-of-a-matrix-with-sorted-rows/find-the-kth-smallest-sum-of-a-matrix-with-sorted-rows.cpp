class Solution {
public:
    vector<int> merge(vector<int>& a, vector<int>& b, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        // (sum, index in b)
        for (int i = 0; i < a.size(); i++) {
            pq.push({a[i] + b[0], 0});
        }
        
        vector<int> result;
        
        while (k-- && !pq.empty()) {
            auto [sum, j] = pq.top();
            pq.pop();
            
            result.push_back(sum);
            
            if (j + 1 < b.size()) {
                pq.push({sum - b[j] + b[j + 1], j + 1});
            }
        }
        
        return result;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> sums = mat[0];
        
        for (int i = 1; i < mat.size(); i++) {
            sums = merge(sums, mat[i], k);
        }
        
        return sums[k - 1];
    }
};