class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            // Reverse from i to i+k-1, but not past the end
            int left = i, right = min(i + k - 1, n - 1);
            while (left < right) {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};