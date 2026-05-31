class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        
        // Edge case
        if (n == 1) return "";
        
        // Step 1: try replacing first non-'a' in first half
        for (int i = 0; i < n / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        // Step 2: all are 'a' → change last char to 'b'
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};