class Solution {
public:
    string largestWordCount(vector<string>& messages,
                            vector<string>& senders) {

        unordered_map<string, int> mp;

        for (int i = 0; i < messages.size(); i++) {
            int words = 1;

            for (char ch : messages[i]) {
                if (ch == ' ') {
                    words++;
                }
            }

            mp[senders[i]] += words;
        }

        string ans = "";
        int maxWords = 0;

        for (auto& entry : mp) {
            string name = entry.first;
            int words = entry.second;

            if (words > maxWords ||
                (words == maxWords && name > ans)) {

                maxWords = words;
                ans = name;
            }
        }

        return ans;
    }
};