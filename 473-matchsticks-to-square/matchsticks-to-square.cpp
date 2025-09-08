class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        long long sum = 0;
        for (int x : matchsticks) sum += x;
        if (matchsticks.empty() || sum % 4 != 0) return false;
        int target = sum / 4;

        // Sort descending for stronger pruning
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if (matchsticks[0] > target) return false; // early fail

        array<int,4> side{0,0,0,0};
        return dfs(0, matchsticks, side, target);
    }

private:
    bool dfs(int i, const vector<int>& a, array<int,4>& side, int target) {
        if (i == (int)a.size()) {
            return side[0] == target && side[1] == target &&
                   side[2] == target && side[3] == target;
        }
        int stick = a[i];

        // Try to place stick on one of 4 sides
        for (int s = 0; s < 4; ++s) {
            if (side[s] + stick > target) continue;

            // Symmetry pruning: avoid trying identical side states
            bool seenSame = false;
            for (int t = 0; t < s; ++t) {
                if (side[t] == side[s]) { seenSame = true; break; }
            }
            if (seenSame) continue;

            side[s] += stick;
            if (dfs(i + 1, a, side, target)) return true;
            side[s] -= stick;

            // If this stick cannot go on an empty side, no point trying other empty sides
            if (side[s] == 0) break;
        }
        return false;
    }
};