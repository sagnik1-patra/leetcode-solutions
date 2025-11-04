class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // Skip 'X' in both
            while (i < n && start[i] == 'X') i++;
            while (j < n && end[j] == 'X') j++;

            // If both end at same time, done
            if (i == n && j == n) return true;
            if (i == n || j == n) return false;

            if (start[i] != end[j]) return false;

            // Movement rules
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;

            i++; j++;
        }

        return true;
    }
};
