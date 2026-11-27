class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (head != nullptr) {

            // Left to right
            for (int j = left; j <= right && head; j++) {
                matrix[top][j] = head->val;
                head = head->next;
            }
            top++;

            // Top to bottom
            for (int i = top; i <= bottom && head; i++) {
                matrix[i][right] = head->val;
                head = head->next;
            }
            right--;

            // Right to left
            for (int j = right; j >= left && head; j--) {
                matrix[bottom][j] = head->val;
                head = head->next;
            }
            bottom--;

            // Bottom to top
            for (int i = bottom; i >= top && head; i--) {
                matrix[i][left] = head->val;
                head = head->next;
            }
            left++;
        }

        return matrix;
    }
};