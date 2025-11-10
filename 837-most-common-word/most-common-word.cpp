class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        string word;
        for (char &c : paragraph) {
            if (isalpha(c)) {
                word += tolower(c);
            } else if (!word.empty()) {
                if (!bannedSet.count(word)) freq[word]++;
                word.clear();
            }
        }

        // handle last word if paragraph ends with a letter
        if (!word.empty() && !bannedSet.count(word))
            freq[word]++;

        string result;
        int maxFreq = 0;
        for (auto &p : freq) {
            if (p.second > maxFreq) {
                maxFreq = p.second;
                result = p.first;
            }
        }

        return result;
    }
};