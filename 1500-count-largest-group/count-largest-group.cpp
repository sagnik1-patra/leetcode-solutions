class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> freq;
        
        // Step 1: group by digit sum
        for (int i = 1; i <= n; i++) {
            int sum = 0, x = i;
            
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            
            freq[sum]++;
        }
        
        // Step 2: find max group size
        int maxSize = 0;
        for (auto &p : freq) {
            maxSize = max(maxSize, p.second);
        }
        
        // Step 3: count groups with max size
        int count = 0;
        for (auto &p : freq) {
            if (p.second == maxSize) {
                count++;
            }
        }
        
        return count;
    }
};