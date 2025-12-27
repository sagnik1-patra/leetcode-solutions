class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int maxTime = -1;

        do {
            int hour = arr[0] * 10 + arr[1];
            int minute = arr[2] * 10 + arr[3];

            if (hour < 24 && minute < 60) {
                int total = hour * 60 + minute;
                maxTime = max(maxTime, total);
            }
        } while (next_permutation(arr.begin(), arr.end()));

        if (maxTime == -1) return "";

        int h = maxTime / 60;
        int m = maxTime % 60;

        return (h < 10 ? "0" : "") + to_string(h) + ":" +
               (m < 10 ? "0" : "") + to_string(m);
    }
};
