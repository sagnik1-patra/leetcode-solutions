class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, n = data.size();
        while (i < n) {
            int b0 = data[i] & 0xFF;          // use only 8 bits
            int lead = countLeadingOnes(b0);  // number of leading 1s

            if (lead == 1 || lead > 4) return false;     // '10xxxxxx' can't start a char; >4 invalid
            if (lead == 0) {                              // 1-byte: 0xxxxxxx
                ++i;
                continue;
            }
            // multi-byte: need lead-1 continuation bytes
            if (i + lead > n) return false;              // not enough bytes
            for (int k = 1; k < lead; ++k) {
                int bx = data[i + k] & 0xFF;
                if ((bx & 0b11000000) != 0b10000000)     // must be 10xxxxxx
                    return false;
            }
            i += lead;
        }
        return true;
    }

private:
    int countLeadingOnes(int b) {
        // count consecutive 1s from MSB
        int cnt = 0;
        for (int mask = 0b10000000; mask && (b & mask); mask >>= 1) ++cnt;
        return cnt;
    }
};
