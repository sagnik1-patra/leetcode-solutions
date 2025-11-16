class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        stringstream ss(sentence);
        string word, result;
        int index = 1;
        
        while (ss >> word) {
            if (vowels.count(word[0])) {
                word += "ma";
            } else {
                word = word.substr(1) + word[0] + "ma";
            }

            word += string(index, 'a');
            if (!result.empty()) result += " ";
            result += word;
            index++;
        }
        return result;
    }
};