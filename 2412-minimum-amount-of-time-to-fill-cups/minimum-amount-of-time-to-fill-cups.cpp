class Solution {
public:
    int fillCups(vector<int>& amount) {
        int sum = amount[0] + amount[1] + amount[2];

        int maxi = max({amount[0], amount[1], amount[2]});

        return max(maxi, (sum + 1) / 2);
    }
};