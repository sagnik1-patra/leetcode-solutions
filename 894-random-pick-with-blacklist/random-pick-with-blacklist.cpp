class Solution {
private:
    int m;  // valid range size
    unordered_map<int, int> mapping;  // map from blacklisted to valid numbers
    mt19937 rng{random_device{}()};   // random number generator
    uniform_int_distribution<int> dist; // will be reset in constructor

public:
    Solution(int n, vector<int>& blacklist) {
        int b = blacklist.size();
        m = n - b;

        unordered_set<int> blackSet;
        for (int x : blacklist)
            if (x >= m)
                blackSet.insert(x);

        int nextValid = m;
        for (int x : blacklist) {
            if (x < m) {
                while (blackSet.count(nextValid))
                    ++nextValid;
                mapping[x] = nextValid++;
            }
        }

        dist = uniform_int_distribution<int>(0, m - 1);
    }

    int pick() {
        int x = dist(rng);
        if (mapping.count(x))
            return mapping[x];
        return x;
    }
};