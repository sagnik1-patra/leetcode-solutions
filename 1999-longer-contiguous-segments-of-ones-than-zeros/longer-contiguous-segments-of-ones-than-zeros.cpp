class Solution {
public:
    bool checkZeroOnes(string s) {
        int currentOnes = 0;
        int currentZeros = 0;

        int maxOnes = 0;
        int maxZeros = 0;

        for (char c : s) {

            if (c == '1') {
                currentOnes++;
                currentZeros = 0;

                maxOnes = max(maxOnes, currentOnes);
            }
            else {
                currentZeros++;
                currentOnes = 0;

                maxZeros = max(maxZeros, currentZeros);
            }
        }

        return maxOnes > maxZeros;
    }
};