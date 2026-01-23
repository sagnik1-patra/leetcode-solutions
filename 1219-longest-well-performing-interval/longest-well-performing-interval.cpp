class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> firstIndex;
        int prefix = 0;
        int ans = 0;

        for (int i = 0; i < hours.size(); i++) {
            prefix += (hours[i] > 8 ? 1 : -1);

            // Case 1: whole prefix is positive
            if (prefix > 0) {
                ans = i + 1;
            } 
            else {
                // Case 2: look for prefix - 1
                if (firstIndex.count(prefix - 1)) {
                    ans = max(ans, i - firstIndex[prefix - 1]);
                }
            }

            // Store earliest occurrence
            if (!firstIndex.count(prefix)) {
                firstIndex[prefix] = i;
            }
        }

        return ans;
    }
};
