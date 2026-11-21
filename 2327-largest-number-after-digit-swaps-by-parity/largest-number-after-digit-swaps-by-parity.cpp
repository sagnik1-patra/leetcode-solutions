
class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);

        vector<char> odd, even;

        // Separate odd and even digits
        for (char c : s) {
            if ((c - '0') % 2 == 0) {
                even.push_back(c);
            } else {
                odd.push_back(c);
            }
        }

        // Sort in descending order
        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());

        int i = 0, j = 0;

        // Reconstruct the largest number
        for (char &c : s) {
            if ((c - '0') % 2 == 0) {
                c = even[j++];
            } else {
                c = odd[i++];
            }
        }

        return stoi(s);
    }
};
