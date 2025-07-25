class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> targetFreq;
        for (char c : t) {
            targetFreq[c]++;
        }

        int left = 0, right = 0;
        int required = targetFreq.size();
        int formed = 0;

        unordered_map<char, int> windowCounts;
        int minLen = INT_MAX, minLeft = 0;

        while (right < s.size()) {
            char c = s[right];
            windowCounts[c]++;
            
            if (targetFreq.count(c) && windowCounts[c] == targetFreq[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                char d = s[left];
                windowCounts[d]--;
                if (targetFreq.count(d) && windowCounts[d] < targetFreq[d]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
