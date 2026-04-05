class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> freqMap;
        vector<int> charCount(26, 0);

        int unique = 0;
        int left = 0;
        int result = 0;

        for (int right = 0; right < s.size(); right++) {
            // Add character
            if (charCount[s[right] - 'a'] == 0) unique++;
            charCount[s[right] - 'a']++;

            // Maintain window size = minSize
            if (right - left + 1 > minSize) {
                charCount[s[left] - 'a']--;
                if (charCount[s[left] - 'a'] == 0) unique--;
                left++;
            }

            // When window size is exactly minSize
            if (right - left + 1 == minSize && unique <= maxLetters) {
                string sub = s.substr(left, minSize);
                freqMap[sub]++;
                result = max(result, freqMap[sub]);
            }
        }

        return result;
    }
};