class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Make sentence1 the shorter sentence
        if (sentence1.length() > sentence2.length()) {
            swap(sentence1, sentence2);
        }

        vector<string> s1, s2;
        string word;

        stringstream ss1(sentence1);
        while (ss1 >> word) {
            s1.push_back(word);
        }

        stringstream ss2(sentence2);
        while (ss2 >> word) {
            s2.push_back(word);
        }

        int n = s1.size();
        int m = s2.size();

        int left = 0;

        // Match words from the beginning
        while (left < n && s1[left] == s2[left]) {
            left++;
        }

        int right = 0;

        // Match words from the end
        while (right < n - left &&
               s1[n - 1 - right] == s2[m - 1 - right]) {
            right++;
        }

        return left + right == n;
    }
};