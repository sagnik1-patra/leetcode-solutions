class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        
        while (i < n - 1) {
            if (bits[i] == 1)
                i += 2;  // two-bit character
            else
                i += 1;  // one-bit character
        }
        
        // If we end exactly on the last bit, it's a one-bit character
        return i == n - 1;
    }
};
