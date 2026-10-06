class Solution {
public:
    int getMinSwaps(string num, int k) {
        
        string target = num;

        // Step 1: Find kth smallest wonderful integer
        while (k--) {
            next_permutation(target.begin(), target.end());
        }

        // Step 2: Transform num into target
        // using minimum adjacent swaps
        int swaps = 0;

        for (int i = 0; i < num.size(); i++) {

            if (num[i] == target[i])
                continue;

            int j = i + 1;

            // Find the required digit
            while (num[j] != target[i]) {
                j++;
            }

            // Move it left using adjacent swaps
            while (j > i) {
                swap(num[j], num[j - 1]);
                j--;
                swaps++;
            }
        }

        return swaps;
    }
};