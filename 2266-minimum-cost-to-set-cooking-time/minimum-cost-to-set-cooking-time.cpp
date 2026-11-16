
class Solution {
public:
    int minCostSetTime(int startAt, int moveCost,
                       int pushCost, int targetSeconds) {

        int ans = INT_MAX;

        for (int m = 0; m <= 99; m++) {
            int s = targetSeconds - m * 60;

            if (s < 0 || s > 99)
                continue;

            int time = m * 100 + s;
            string digits = to_string(time);

            int pos = startAt;
            int cost = 0;

            for (char ch : digits) {
                int digit = ch - '0';

                if (pos != digit) {
                    cost += moveCost;
                    pos = digit;
                }

                cost += pushCost;
            }

            ans = min(ans, cost);
        }

        return ans;
    }
};
