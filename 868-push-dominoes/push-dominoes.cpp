class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> force(n, 0);

        // Pass 1: Left to right (apply positive force for 'R')
        int f = 0;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') f = n;     // max force
            else if (dominoes[i] == 'L') f = 0; // reset
            else f = max(f - 1, 0);             // decay
            force[i] += f;
        }

        // Pass 2: Right to left (apply negative force for 'L')
        f = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') f = n;
            else if (dominoes[i] == 'R') f = 0;
            else f = max(f - 1, 0);
            force[i] -= f;
        }

        // Final state based on net force
        string result;
        for (int f : force) {
            if (f > 0) result += 'R';
            else if (f < 0) result += 'L';
            else result += '.';
        }

        return result;
    }
};