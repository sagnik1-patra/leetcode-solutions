
class Solution {
public:
    int getValue(string s) {
        int num = 0;

        for (char c : s) {
            num = num * 10 + (c - 'a');
        }

        return num;
    }

    bool isSumEqual(string firstWord, string secondWord,
                    string targetWord) {

        int first = getValue(firstWord);
        int second = getValue(secondWord);
        int target = getValue(targetWord);

        return first + second == target;
    }
};
