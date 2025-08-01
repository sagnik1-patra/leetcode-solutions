class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                string word = q.front();
                q.pop();

                if (word == endWord) return steps;

                for (int j = 0; j < word.size(); ++j) {
                    char originalChar = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                            dict.erase(word); // Mark visited
                        }
                    }
                    word[j] = originalChar;
                }
            }
            ++steps;
        }

        return 0;
    }
};
