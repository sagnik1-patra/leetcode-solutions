class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        vector<vector<int>> hull;

        // Function to compute cross product
        auto cross = [](vector<int>& A, vector<int>& B, vector<int>& C) {
            return (B[0] - A[0]) * (C[1] - A[1]) - (B[1] - A[1]) * (C[0] - A[0]);
        };

        // Build lower hull
        for (auto& p : trees) {
            while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), p) < 0)
                hull.pop_back();
            hull.push_back(p);
        }

        // Build upper hull
        int lower_size = hull.size();
        for (int i = trees.size() - 2; i >= 0; i--) {
            auto p = trees[i];
            while ((int)hull.size() > lower_size && cross(hull[hull.size() - 2], hull.back(), p) < 0)
                hull.pop_back();
            hull.push_back(p);
        }

        // Remove duplicates
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());
        return hull;
    }
};