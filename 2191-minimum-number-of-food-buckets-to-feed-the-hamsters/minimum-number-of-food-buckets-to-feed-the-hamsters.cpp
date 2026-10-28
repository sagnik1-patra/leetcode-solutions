class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n = hamsters.size();
        int count = 0;

        for (int i = 0; i < n; i++) {

            if (hamsters[i] == 'H') {

                // Already has a bucket on the left
                if (i > 0 && hamsters[i - 1] == 'B') {
                    continue;
                }

                // Prefer placing bucket on the right
                if (i + 1 < n && hamsters[i + 1] == '.') {
                    hamsters[i + 1] = 'B';
                    count++;
                }

                // Otherwise place bucket on the left
                else if (i > 0 && hamsters[i - 1] == '.') {
                    hamsters[i - 1] = 'B';
                    count++;
                }

                // No empty adjacent position
                else {
                    return -1;
                }
            }
        }

        return count;
    }
};