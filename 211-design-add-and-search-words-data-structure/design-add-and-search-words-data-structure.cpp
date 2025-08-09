class WordDictionary {
private:
    struct TrieNode {
        bool isEnd;
        TrieNode* children[26];
        TrieNode() : isEnd(false) {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    TrieNode* root;

    bool searchHelper(const string& word, int index, TrieNode* node) {
        if (!node) return false;
        if (index == word.size()) return node->isEnd;

        char c = word[index];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && searchHelper(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            return searchHelper(word, index + 1, node->children[c - 'a']);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
