class Solution {
public:
    string orderlyQueue(string s, int k) {
        // Case 1: Only rotations possible
        if (k == 1) {
            string best = s;
            int n = s.size();
            for (int i = 1; i < n; i++) {
                string rotated = s.substr(i) + s.substr(0, i);
                best = min(best, rotated);
            }
            return best;
        }
        // Case 2: Full rearrangement possible
        sort(s.begin(), s.end());
        return s;
    }
};
