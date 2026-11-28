class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {

            // Skip underscores
            while (i < n && start[i] == '_')
                i++;

            while (j < n && target[j] == '_')
                j++;

            // Both strings must finish together
            if (i == n || j == n)
                return i == n && j == n;

            // Relative order must remain the same
            if (start[i] != target[j])
                return false;

            // L cannot move right
            if (start[i] == 'L' && i < j)
                return false;

            // R cannot move left
            if (start[i] == 'R' && i > j)
                return false;

            i++;
            j++;
        }

        return true;
    }
};