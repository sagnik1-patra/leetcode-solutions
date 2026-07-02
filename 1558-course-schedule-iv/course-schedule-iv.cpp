class Solution {
public:
    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries
    ) {
        vector<vector<bool>> pre(numCourses, vector<bool>(numCourses, false));

        for (auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];
            pre[a][b] = true;
        }

        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    if (pre[i][k] && pre[k][j]) {
                        pre[i][j] = true;
                    }
                }
            }
        }

        vector<bool> ans;

        for (auto &q : queries) {
            ans.push_back(pre[q[0]][q[1]]);
        }

        return ans;
    }
};