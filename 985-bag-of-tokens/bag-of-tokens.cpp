class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int l = 0, r = tokens.size() - 1;
        int score = 0, maxScore = 0;

        while (l <= r) {
            if (power >= tokens[l]) {
                // play face-up
                power -= tokens[l++];
                score++;
                maxScore = max(maxScore, score);
            } 
            else if (score >= 1) {
                // play face-down
                power += tokens[r--];
                score--;
            } 
            else {
                break;
            }
        }

        return maxScore;
    }
};
