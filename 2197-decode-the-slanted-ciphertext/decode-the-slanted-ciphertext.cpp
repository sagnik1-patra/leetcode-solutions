class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();

        if (n == 0) return "";

        int cols = n / rows;
        string ans = "";

        for (int j = 0; j < cols; j++) {
            int i = 0;
            int col = j;

            while (i < rows && col < cols) {
                ans += encodedText[i * cols + col];
                i++;
                col++;
            }
        }

        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};