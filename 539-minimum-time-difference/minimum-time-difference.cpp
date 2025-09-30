class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        minutes.reserve(timePoints.size());

        // convert "HH:MM" to minutes
        for (auto &t : timePoints) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }

        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i-1]);
        }

        // circular case: last vs first + 24h
        minDiff = min(minDiff, 1440 - (minutes.back() - minutes.front()));

        return minDiff;
    }
};
