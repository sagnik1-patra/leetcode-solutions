class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();

        // last[d] stores the last index of digit d in the number
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i)
            last[s[i] - '0'] = i;

        // Traverse each digit from left to right
        for (int i = 0; i < n; ++i) {
            int curr = s[i] - '0';
            // Check if a larger digit appears later
            for (int d = 9; d > curr; --d) {
                if (last[d] > i) { // found a later larger digit
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }

        return num; // no swap needed
    }
};
