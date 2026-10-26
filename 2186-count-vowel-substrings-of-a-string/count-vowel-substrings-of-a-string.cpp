class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<char> st;

            for (int j = i; j < n; j++) {
                char ch = word[j];

                if (ch != 'a' && ch != 'e' && ch != 'i' &&
                    ch != 'o' && ch != 'u') {
                    break;
                }

                st.insert(ch);

                if (st.size() == 5) {
                    count++;
                }
            }
        }

        return count;
    }
};