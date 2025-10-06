class Solution {
public:
    string nearestPalindromic(string n) {
        long long len = n.size();
        long long num = stoll(n);
        unordered_set<long long> candidates;

        // Edge cases
        candidates.insert((long long)pow(10, len) + 1);   // e.g., 1000 -> 1001
        candidates.insert((long long)pow(10, len - 1) - 1); // e.g., 1000 -> 999

        // Take the prefix (first half + middle if odd)
        long long prefixLen = (len + 1) / 2;
        long long prefix = stoll(n.substr(0, prefixLen));

        for (long long i = -1; i <= 1; i++) {
            string p = to_string(prefix + i);
            string pal = makePalindrome(p, len % 2);
            candidates.insert(stoll(pal));
        }

        candidates.erase(num); // exclude itself

        long long best = -1;
        for (long long cand : candidates) {
            if (best == -1 ||
                abs(cand - num) < abs(best - num) ||
                (abs(cand - num) == abs(best - num) && cand < best)) {
                best = cand;
            }
        }

        return to_string(best);
    }

private:
    string makePalindrome(string prefix, bool isOdd) {
        string pal = prefix;
        int start = isOdd ? prefix.size() - 2 : prefix.size() - 1;
        for (int i = start; i >= 0; i--)
            pal += prefix[i];
        return pal;
    }
};