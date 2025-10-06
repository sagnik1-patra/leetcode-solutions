class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size() - 2;

        // Step 1: find first decreasing element from the right
        while (i >= 0 && s[i] >= s[i + 1]) i--;
        if (i < 0) return -1; // already largest permutation

        // Step 2: find next greater element to swap
        int j = s.size() - 1;
        while (s[j] <= s[i]) j--;

        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());

        // Step 3: convert back to integer
        long long val = stoll(s);
        return (val > INT_MAX) ? -1 : (int)val;
    }
};