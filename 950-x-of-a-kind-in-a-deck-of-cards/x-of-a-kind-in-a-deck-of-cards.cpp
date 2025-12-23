class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for (int x : deck) {
            freq[x]++;
        }

        int g = 0;
        for (auto& [_, count] : freq) {
            g = gcd(g, count);
        }

        return g >= 2;
    }
};
