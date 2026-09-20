class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int answer = 0;

        // Convert each cell into the height of consecutive 1s
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        // For each row, sort heights in descending order
        for (int i = 0; i < m; i++) {
            vector<int> heights = matrix[i];

            sort(heights.rbegin(), heights.rend());

            for (int j = 0; j < n; j++) {
                int height = heights[j];
                int width = j + 1;

                answer = max(answer, height * width);
            }
        }

        return answer;
    }
};