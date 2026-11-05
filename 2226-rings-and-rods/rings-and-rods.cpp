
class Solution {
public:
    int countPoints(string rings) {
        int rods[10] = {0};

        for (int i = 0; i < rings.size(); i += 2) {
            int pos = rings[i + 1] - '0';

            if (rings[i] == 'R')
                rods[pos] |= 1;
            else if (rings[i] == 'G')
                rods[pos] |= 2;
            else
                rods[pos] |= 4;
        }

        int count = 0;

        for (int i = 0; i < 10; i++) {
            if (rods[i] == 7)
                count++;
        }

        return count;
    }
};
