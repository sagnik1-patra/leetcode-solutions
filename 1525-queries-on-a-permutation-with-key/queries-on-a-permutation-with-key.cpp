class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> P;
        
        // initialize permutation
        for (int i = 1; i <= m; i++) {
            P.push_back(i);
        }
        
        vector<int> result;
        
        for (int q : queries) {
            int pos = 0;
            
            // find position
            while (P[pos] != q) pos++;
            
            result.push_back(pos);
            
            // move to front
            P.erase(P.begin() + pos);
            P.insert(P.begin(), q);
        }
        
        return result;
    }
};