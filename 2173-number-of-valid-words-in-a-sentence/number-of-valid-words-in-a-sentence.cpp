
class Solution {
public:
    int countValidWords(string sentence) {
        stringstream ss(sentence);
        string word;
        int count = 0;

        while (ss >> word) {
            bool valid = true;
            int hyphen = 0;
            int punctuation = 0;
            int n = word.size();

            for (int i = 0; i < n; i++) {
                char ch = word[i];

                if (isdigit(ch)) {
                    valid = false;
                    break;
                }

                if (ch == '-') {
                    hyphen++;

                    if (hyphen > 1 || i == 0 || i == n - 1 ||
                        !islower(word[i-1]) ||
                        !islower(word[i+1])) {
                        valid = false;
                        break;
                    }
                }

                if (ch == '!' || ch == '.' || ch == ',') {
                    punctuation++;

                    if (punctuation > 1 || i != n - 1) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid) {
                count++;
            }
        }

        return count;
    }
};
