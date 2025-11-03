class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0;
        int maxSoFar = 0;

        for (int i = 0; i < arr.size(); ++i) {
            maxSoFar = max(maxSoFar, arr[i]);
            if (maxSoFar == i)  // all elements up to i are in correct range
                chunks++;
        }

        return chunks;
    }
};
