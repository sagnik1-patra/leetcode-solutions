class Solution {
public:
    int minimumBoxes(int n) {
        long long total = 0;
        long long floorBoxes = 0;
        long long layer = 0;

        // Build the largest complete tetrahedral structure
        while (true) {
            layer++;

            // Boxes added to the floor for this complete layer
            long long floorAdd = layer * (layer + 1) / 2;

            // Total boxes in a complete structure of this height
            long long nextTotal =
                layer * (layer + 1) * (layer + 2) / 6;

            if (nextTotal > n) {
                layer--;
                break;
            }

            total = nextTotal;
            floorBoxes = floorAdd;
        }

        // Add extra floor boxes until remaining boxes fit
        long long extra = 0;

        while (total < n) {
            extra++;
            floorBoxes++;
            total += extra;
        }

        return floorBoxes;
    }
};