class Solution {
public:
    string decodeMessage(string key, string message) {

        unordered_map<char, char> mp;

        char ch = 'a';

        // Create substitution table
        for (char c : key) {

            if (c != ' ' && mp.find(c) == mp.end()) {
                mp[c] = ch;
                ch++;
            }
        }

        // Preserve spaces
        mp[' '] = ' ';

        // Decode the message
        for (int i = 0; i < message.size(); i++) {
            message[i] = mp[message[i]];
        }

        return message;
    }
};