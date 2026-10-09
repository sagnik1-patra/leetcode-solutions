
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Find maximum element in middle column
            int maxRow = 0;

            for (int i = 1; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            int curr = mat[maxRow][mid];

            int leftVal = (mid > 0)
                        ? mat[maxRow][mid - 1] : -1;

            int rightVal = (mid < n - 1)
                         ? mat[maxRow][mid + 1] : -1;

            if (curr > leftVal && curr > rightVal) {
                return {maxRow, mid};
            }
            else if (leftVal > curr) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return {-1, -1};
    }
};
