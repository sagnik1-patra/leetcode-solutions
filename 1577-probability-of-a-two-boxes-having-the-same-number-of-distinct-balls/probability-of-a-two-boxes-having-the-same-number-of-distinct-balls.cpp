class Solution {
public:
    vector<vector<double>> comb;
    double good = 0, total = 0;
    int n;

    void dfs(vector<int>& balls, int idx, int box1Count, int box2Count,
             int color1, int color2, double ways) {
        
        if (idx == balls.size()) {
            if (box1Count == n && box2Count == n) {
                total += ways;

                if (color1 == color2) {
                    good += ways;
                }
            }
            return;
        }

        int count = balls[idx];

        for (int take = 0; take <= count; take++) {
            int giveBox1 = take;
            int giveBox2 = count - take;

            dfs(
                balls,
                idx + 1,
                box1Count + giveBox1,
                box2Count + giveBox2,
                color1 + (giveBox1 > 0),
                color2 + (giveBox2 > 0),
                ways * comb[count][take]
            );
        }
    }

    double getProbability(vector<int>& balls) {
        int sum = 0;
        for (int x : balls) sum += x;

        n = sum / 2;

        comb.assign(7, vector<double>(7, 0));

        for (int i = 0; i <= 6; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            }
        }

        dfs(balls, 0, 0, 0, 0, 0, 1.0);

        return good / total;
    }
};