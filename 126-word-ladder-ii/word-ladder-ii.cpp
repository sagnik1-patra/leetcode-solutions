class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (dict.find(endWord) == dict.end())
            return result;

        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> visited;
        queue<string> q;

        q.push(beginWord);
        visited[beginWord] = 0;

        int level = 0;
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            ++level;
            unordered_set<string> currentLevelVisited;

            for (int i = 0; i < size; ++i) {
                string word = q.front(); q.pop();
                string original = word;

                for (int j = 0; j < word.size(); ++j) {
                    char originalChar = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;
                        if (dict.count(word)) {
                            if (!visited.count(word)) {
                                visited[word] = level;
                                q.push(word);
                                currentLevelVisited.insert(word);
                                graph[word].push_back(original);
                            } else if (visited[word] == level) {
                                graph[word].push_back(original);
                            }

                            if (word == endWord)
                                found = true;
                        }
                    }
                    word[j] = originalChar;
                }
            }

            for (const string& word : currentLevelVisited)
                dict.erase(word);
        }

        if (found) {
            vector<string> path;
            backtrack(endWord, beginWord, graph, path, result);
        }

        return result;
    }

private:
    void backtrack(const string& word, const string& beginWord,
                   unordered_map<string, vector<string>>& graph,
                   vector<string>& path, vector<vector<string>>& result) {
        path.push_back(word);
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
        } else {
            for (const string& prev : graph[word]) {
                backtrack(prev, beginWord, graph, path, result);
            }
        }
        path.pop_back();
    }
};
