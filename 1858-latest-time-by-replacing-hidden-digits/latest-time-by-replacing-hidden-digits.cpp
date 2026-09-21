class Solution {
public:
    string maximumTime(string time) {
        // First hour digit
        if (time[0] == '?') {
            if (time[1] == '?' || time[1] <= '3')
                time[0] = '2';
            else
                time[0] = '1';
        }

        // Second hour digit
        if (time[1] == '?') {
            if (time[0] == '2')
                time[1] = '3';
            else
                time[1] = '9';
        }

        // First minute digit
        if (time[3] == '?') {
            time[3] = '5';
        }

        // Second minute digit
        if (time[4] == '?') {
            time[4] = '9';
        }

        return time;
    }
};