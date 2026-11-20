
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0, right = n - 1;

        // Ignore cars escaping to the left
        while (left < n && directions[left] == 'L') {
            left++;
        }

        // Ignore cars escaping to the right
        while (right >= left && directions[right] == 'R') {
            right--;
        }

        int count = 0;

        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') {
                count++;
            }
        }

        return count;
    }
};
