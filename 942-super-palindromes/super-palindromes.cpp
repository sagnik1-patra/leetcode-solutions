class Solution {
public:
    bool isPalindrome(long long x) {
        string s = to_string(x);
        return s == string(s.rbegin(), s.rend());
    }

    int superpalindromesInRange(string left, string right) {
        long long L = stoll(left);
        long long R = stoll(right);
        int ans = 0;

        for (int i = 1; i < 100000; i++) {
            string s = to_string(i);

            // -------- Odd-length palindrome --------
            string odd = s + string(s.rbegin() + 1, s.rend());
            long long p = stoll(odd);

            __int128 sq = ( __int128 )p * p;
            if (sq > R) break;
            if (sq >= L && isPalindrome((long long)sq)) ans++;

            // -------- Even-length palindrome --------
            string even = s + string(s.rbegin(), s.rend());
            p = stoll(even);

            sq = ( __int128 )p * p;
            if (sq > R) continue;
            if (sq >= L && isPalindrome((long long)sq)) ans++;
        }

        return ans;
    }
};
