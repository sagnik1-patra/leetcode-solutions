class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = (int)matrix.size();
        int lo = matrix[0][0], hi = matrix[n-1][n-1];

        auto countLE = [&](int x) -> int {
            // count of elements <= x using a staircase walk
            int i = n - 1, j = 0, cnt = 0;
            while (i >= 0 && j < n) {
                if (matrix[i][j] <= x) {
                    cnt += i + 1; // all in this column up to row i are <= x
                    ++j;
                } else {
                    --i;
                }
            }
            return cnt;
        };

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (countLE(mid) < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
