class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> roots(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word, result;

        while (ss >> word) {
            string prefix;
            bool replaced = false;

            for (int i = 1; i <= word.size(); ++i) {
                prefix = word.substr(0, i);
                if (roots.count(prefix)) {
                    result += prefix + " ";
                    replaced = true;
                    break;
                }
            }

            if (!replaced) result += word + " ";
        }

        // Remove trailing space
        if (!result.empty()) result.pop_back();
        return result;
    }
};
