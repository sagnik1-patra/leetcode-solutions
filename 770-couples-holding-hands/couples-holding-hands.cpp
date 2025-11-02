class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> pos(n); // pos[id] = index in row

        // Store current positions
        for (int i = 0; i < n; ++i)
            pos[row[i]] = i;

        int swaps = 0;

        for (int i = 0; i < n; i += 2) {
            int a = row[i];
            int b = a ^ 1; // partner (0↔1, 2↔3, 4↔5, etc.)

            if (row[i + 1] != b) {
                swaps++;

                // Partner’s position
                int partnerPos = pos[b];

                // Swap row[i+1] and row[partnerPos]
                swap(row[i + 1], row[partnerPos]);

                // Update positions after swap
                pos[row[partnerPos]] = partnerPos;
                pos[row[i + 1]] = i + 1;
            }
        }

        return swaps;
    }
};
