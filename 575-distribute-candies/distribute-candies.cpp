class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> uniqueTypes(candyType.begin(), candyType.end());
        int maxAllowed = candyType.size() / 2;
        return min((int)uniqueTypes.size(), maxAllowed);
    }
};
