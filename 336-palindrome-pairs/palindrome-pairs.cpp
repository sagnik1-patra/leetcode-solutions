class Solution {
public:
    struct Node {
        int word = -1;                       // index of word ending here, -1 if none
        int nxt[26];
        vector<int> palBelow;                // indices of words where the remaining prefix is a palindrome
        Node() {
            memset(nxt, -1, sizeof(nxt));
        }
    };

    vector<Node> trie;

    vector<vector<int>> palindromePairs(vector<string>& words) {
        trie.clear();
        trie.emplace_back();                 // root

        // 1) Insert each word into trie in REVERSE.
        for (int i = 0; i < (int)words.size(); ++i) {
            insert(words[i], i);
        }

        // 2) For each word, walk forward in the trie and collect matches.
        vector<vector<int>> ans;
        for (int i = 0; i < (int)words.size(); ++i) {
            search(words[i], i, ans);
        }
        return ans;
    }

private:
    static bool isPal(const string& s, int l, int r) {
        while (l < r) if (s[l++] != s[r--]) return false;
        return true;
    }

    void insert(const string& w, int idx) {
        int node = 0;
        // Traverse from end to start; at each step, if w[0..i] is palindrome,
        // then any word ending at current node can pair with this word later.
        for (int i = (int)w.size() - 1; i >= 0; --i) {
            if (isPal(w, 0, i)) trie[node].palBelow.push_back(idx);
            int c = w[i] - 'a';
            if (trie[node].nxt[c] == -1) {
                trie[node].nxt[c] = (int)trie.size();
                trie.emplace_back();
            }
            node = trie[node].nxt[c];
        }
        trie[node].word = idx;
        trie[node].palBelow.push_back(idx);  // empty prefix is palindrome
    }

    void search(const string& w, int idx, vector<vector<int>>& out) {
        int node = 0;
        int n = (int)w.size();

        for (int i = 0; i < n; ++i) {
            // Case A: we are at a node that is the end of some word j.
            // If the rest of current word w[i..] is a palindrome,
            // then w + word(j) is a palindrome.
            int j = trie[node].word;
            if (j != -1 && j != idx && isPal(w, i, n - 1)) {
                out.push_back({idx, j});
            }
            int c = w[i] - 'a';
            if (trie[node].nxt[c] == -1) return; // no more matches
            node = trie[node].nxt[c];
        }

        // Case B: we've consumed all of w; any word j in palBelow from here
        // forms palindrome when appended: w + word(j)
        for (int j : trie[node].palBelow) {
            if (j != idx) out.push_back({idx, j});
        }
    }
};
