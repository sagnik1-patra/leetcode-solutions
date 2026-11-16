
class Bitset {
public:
    string bits;
    int ones;
    bool flipped;

    Bitset(int size) {
        bits = string(size, '0');
        ones = 0;
        flipped = false;
    }

    void fix(int idx) {
        char current = flipped ? '0' : '1';

        if (bits[idx] != current) {
            bits[idx] = current;
            ones++;
        }
    }

    void unfix(int idx) {
        char current = flipped ? '1' : '0';

        if (bits[idx] != current) {
            bits[idx] = current;
            ones--;
        }
    }

    void flip() {
        flipped = !flipped;
        ones = bits.size() - ones;
    }

    bool all() {
        return ones == bits.size();
    }

    bool one() {
        return ones > 0;
    }

    int count() {
        return ones;
    }

    string toString() {
        string result = bits;

        if (flipped) {
            for (char &c : result) {
                c = (c == '0') ? '1' : '0';
            }
        }

        return result;
    }
};
