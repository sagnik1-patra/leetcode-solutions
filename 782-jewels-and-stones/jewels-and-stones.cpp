class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> set(jewels.begin(), jewels.end());
        int count = 0;

        for (char s : stones) {
            if (set.count(s)) count++;
        }

        return count;
    }
};
