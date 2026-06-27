class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        // start from right (ignore first bit)
        for (int i = s.size() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;
            
            if (bit == 1) {
                // odd → +1 then /2
                steps += 2;
                carry = 1;
            } else {
                // even → just /2
                steps += 1;
            }
        }
        
        // if carry remains, one extra step
        return steps + carry;
    }
};