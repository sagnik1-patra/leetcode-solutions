class StreamChecker {
private:
    struct TrieNode {
        bool isEnd;
        TrieNode* child[26];

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* root;
    string stream;
    int maxLen;

    void insertWord(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }

public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        maxLen = 0;

        for (string& w : words) {
            reverse(w.begin(), w.end());
            insertWord(w);
            maxLen = max(maxLen, (int)w.size());
        }
    }

    bool query(char letter) {
        stream.push_back(letter);
        if (stream.size() > maxLen)
            stream.erase(stream.begin());

        TrieNode* node = root;
        for (int i = stream.size() - 1; i >= 0; i--) {
            int idx = stream[i] - 'a';
            if (!node->child[idx])
                return false;
            node = node->child[idx];
            if (node->isEnd)
                return true;
        }
        return false;
    }
};
