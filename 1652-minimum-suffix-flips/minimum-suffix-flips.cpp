class Solution {
public:
    int minFlips(string target) {
        int flips = 0;
        
        for (char c : target) {
            // current bit after flips
            char current = (flips % 2 == 0) ? '0' : '1';
            
            if (current != c) {
                flips++; // perform flip
            }
        }
        
        return flips;
    }
};