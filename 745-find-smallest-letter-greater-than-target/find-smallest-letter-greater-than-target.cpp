class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size();
        
        // Binary search for first character > target
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }

        // If we go past end, wrap around to first letter
        return letters[left % letters.size()];
    }
};
