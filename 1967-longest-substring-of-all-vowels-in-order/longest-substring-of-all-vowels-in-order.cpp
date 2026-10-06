class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();

        int start = 0;
        int distinct = 1;
        int answer = 0;

        for (int i = 1; i < n; i++) {

            // Order is broken, so start a new substring
            if (word[i] < word[i - 1]) {
                start = i;
                distinct = 1;
            }

            // A new vowel appears in increasing order
            else if (word[i] > word[i - 1]) {
                distinct++;
            }

            // If all 5 vowels are present
            if (distinct == 5) {
                answer = max(answer, i - start + 1);
            }
        }

        return answer;
    }
};