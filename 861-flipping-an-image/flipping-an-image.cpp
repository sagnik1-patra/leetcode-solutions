class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();

        for (auto &row : image) {
            reverse(row.begin(), row.end());
            for (int &x : row) {
                x ^= 1; // invert: 0->1, 1->0
            }
        }
        return image;
    }
};