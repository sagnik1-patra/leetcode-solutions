
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts,
                     vector<vector<int>>& dig) {

        unordered_set<int> excavated;

        for (auto &cell : dig) {
            int r = cell[0];
            int c = cell[1];
            excavated.insert(r * n + c);
        }

        int count = 0;

        for (auto &artifact : artifacts) {
            int r1 = artifact[0];
            int c1 = artifact[1];
            int r2 = artifact[2];
            int c2 = artifact[3];

            bool found = true;

            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    if (excavated.find(i * n + j) == excavated.end()) {
                        found = false;
                        break;
                    }
                }
                if (!found) break;
            }

            if (found) count++;
        }

        return count;
    }
};
