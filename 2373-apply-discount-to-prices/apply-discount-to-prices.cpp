class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string word, ans;

        while (ss >> word) {
            bool valid = true;

            // Check whether the word starts with '$'
            if (word.size() < 2 || word[0] != '$') {
                valid = false;
            } else {
                // Every character after '$' must be a digit
                for (int i = 1; i < word.size(); i++) {
                    if (!isdigit(word[i])) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid) {
                long long price = stoll(word.substr(1));

                // Calculate discounted price in cents
                long long cents = price * (100 - discount);

                long long whole = cents / 100;
                long long decimal = cents % 100;

                word = "$" + to_string(whole) + ".";

                if (decimal < 10) {
                    word += "0";
                }

                word += to_string(decimal);
            }

            if (!ans.empty()) {
                ans += " ";
            }

            ans += word;
        }

        return ans;
    }
};