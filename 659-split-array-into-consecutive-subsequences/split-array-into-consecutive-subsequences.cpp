class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;

        // Count occurrences of each number
        for (int num : nums)
            freq[num]++;

        for (int num : nums) {
            if (freq[num] == 0) continue;  // Already used

            // If we can extend a previous subsequence ending at num-1
            if (need[num] > 0) {
                need[num]--;
                need[num + 1]++;
            }
            // Else, try to start a new subsequence num, num+1, num+2
            else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                freq[num + 1]--;
                freq[num + 2]--;
                need[num + 3]++;
            }
            else {
                return false;  // Can't form or extend any valid subsequence
            }

            freq[num]--;
        }

        return true;
    }
};
