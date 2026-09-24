class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right && s[left] == s[right]) {
            char ch = s[left];

            // Remove matching prefix
            while (left <= right && s[left] == ch) {
                left++;
            }

            // Remove matching suffix
            while (left <= right && s[right] == ch) {
                right--;
            }
        }

        return max(0, right - left + 1);
    }
};