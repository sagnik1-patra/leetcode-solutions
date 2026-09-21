class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> countA(26, 0);
        vector<int> countB(26, 0);

        for (char c : a)
            countA[c - 'a']++;

        for (char c : b)
            countB[c - 'a']++;

        int n = a.size();
        int m = b.size();

        int answer = n + m;

        // Condition 3:
        // Both strings contain only the same single letter
        for (int i = 0; i < 26; i++) {
            int operations =
                (n - countA[i]) +
                (m - countB[i]);

            answer = min(answer, operations);
        }

        // Prefix counts
        vector<int> prefixA(26, 0);
        vector<int> prefixB(26, 0);

        prefixA[0] = countA[0];
        prefixB[0] = countB[0];

        for (int i = 1; i < 26; i++) {
            prefixA[i] = prefixA[i - 1] + countA[i];
            prefixB[i] = prefixB[i - 1] + countB[i];
        }

        // Try every boundary between letters
        // i represents the largest letter allowed
        // in the lexicographically smaller string
        for (int i = 0; i < 25; i++) {

            // Condition 1:
            // every character in a <= i
            // every character in b > i
            int condition1 =
                (n - prefixA[i]) +
                prefixB[i];

            // Condition 2:
            // every character in b <= i
            // every character in a > i
            int condition2 =
                (m - prefixB[i]) +
                prefixA[i];

            answer = min(answer, condition1);
            answer = min(answer, condition2);
        }

        return answer;
    }
};