class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        if (x % 2 == 0) return x == 2;
        for (int i = 3; i * 1LL * i <= x; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        // Handle small cases
        if (n <= 2) return 2;
        if (n <= 3) return 3;
        if (n <= 5) return 5;
        if (n <= 7) return 7;
        if (n <= 11) return 11;

        // Generate odd-length palindromes
        for (int i = 1; i <= 100000; i++) {
            string s = to_string(i);
            string rev = s.substr(0, s.size() - 1);
            reverse(rev.begin(), rev.end());
            int pal = stoi(s + rev);

            if (pal >= n && isPrime(pal)) {
                return pal;
            }
        }

        return -1; // guaranteed not needed
    }
};
