class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Check divisibility
        if (n % k != 0) return false;

        // Step 2: Frequency map
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 3: Traverse sorted keys
        for (auto &it : freq) {
            int num = it.first;
            int count = it.second;

            // If this number still has frequency
            if (count > 0) {
                // Try forming sequences starting from num
                for (int i = 0; i < k; i++) {
                    int next = num + i;

                    // If next number not available enough times
                    if (freq[next] < count) {
                        return false;
                    }

                    freq[next] -= count;
                }
            }
        }

        return true;
    }
};