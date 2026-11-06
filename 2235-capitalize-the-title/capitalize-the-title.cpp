
class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();

        // Convert entire string to lowercase
        for (char &c : title) {
            c = tolower(c);
        }

        int start = 0;

        for (int i = 0; i <= n; i++) {
            if (i == n || title[i] == ' ') {

                if (i - start > 2) {
                    title[start] = toupper(title[start]);
                }

                start = i + 1;
            }
        }

        return title;
    }
};
