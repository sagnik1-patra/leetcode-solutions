class Solution {
public:
    int matchCount(const string &a, const string &b) {
        int cnt = 0;
        for (int i = 0; i < 6; i++)
            if (a[i] == b[i]) cnt++;
        return cnt;
    }

    void findSecretWord(vector<string>& words, Master& master) {

        int attemptsLeft = 30;  // <-- use the given allowedGuesses (30 in this testcase)

        while (attemptsLeft--) {

            // 1. build collision matrix
            int n = words.size();
            vector<vector<int>> cnt(n, vector<int>(7, 0));

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        int m = matchCount(words[i], words[j]);
                        cnt[i][m]++;
                    }
                }
            }

            // 2. pick word with minimum worst bucket
            int bestIndex = -1;
            int bestValue = 1e9;

            for (int i = 0; i < n; i++) {
                int worst = *max_element(cnt[i].begin(), cnt[i].end());
                if (worst < bestValue) {
                    bestValue = worst;
                    bestIndex = i;
                }
            }

            string guessWord = words[bestIndex];
            int matches = master.guess(guessWord);

            if (matches == 6) return;

            // 3. filter words
            vector<string> next;
            for (auto &w : words) {
                if (matchCount(guessWord, w) == matches)
                    next.push_back(w);
            }

            words = next;
        }
    }
};
