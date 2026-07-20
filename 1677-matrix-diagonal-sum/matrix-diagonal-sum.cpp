class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += mat[i][i]; // primary
            
            if (i != n - 1 - i) { // avoid double count
                sum += mat[i][n - 1 - i]; // secondary
            }
        }
        
        return sum;
    }
};