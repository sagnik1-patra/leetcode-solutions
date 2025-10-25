class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
        int count = 1;

        // Step 1: Count consecutive characters
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1])
                count++;
            else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count); // push last group

        // Step 2: Count valid substrings between adjacent groups
        int result = 0;
        for (int i = 1; i < groups.size(); ++i)
            result += min(groups[i - 1], groups[i]);

        return result;
    }
};
