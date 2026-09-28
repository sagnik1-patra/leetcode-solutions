class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> numbers;
        int n = word.size();

        int i = 0;

        while (i < n) {

            // Skip letters
            if (!isdigit(word[i])) {
                i++;
                continue;
            }

            // Find the complete number
            int start = i;

            while (i < n && isdigit(word[i])) {
                i++;
            }

            string num = word.substr(start, i - start);

            // Remove leading zeros
            int pos = 0;

            while (pos < num.size() && num[pos] == '0') {
                pos++;
            }

            // Number consists entirely of zeros
            if (pos == num.size()) {
                num = "0";
            }
            else {
                num = num.substr(pos);
            }

            numbers.insert(num);
        }

        return numbers.size();
    }
};