class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        string left = "", right = "";
        int count = 0;

        for (int i = 0; i < n; i++) {
            left += text[i];
            right = text[n - 1 - i] + right;

            if (left == right) {
                count++;
                left = "";
                right = "";
            }
        }

        return count;
    }
};
