
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;

        for (int i = 0; i < s.size(); i += k) {
            string temp = s.substr(i, k);

            while (temp.size() < k) {
                temp += fill;
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
