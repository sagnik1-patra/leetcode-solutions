
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<vector<int>> friends;

        for (int i = 0; i < n; i++) {
            friends.push_back({times[i][0], times[i][1], i});
        }

        sort(friends.begin(), friends.end());

        priority_queue<int, vector<int>, greater<int>> available;

        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> occupied;

        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        for (auto& f : friends) {
            int arrival = f[0];
            int leaving = f[1];
            int id = f[2];

            while (!occupied.empty() &&
                   occupied.top().first <= arrival) {
                available.push(occupied.top().second);
                occupied.pop();
            }

            int chair = available.top();
            available.pop();

            if (id == targetFriend) {
                return chair;
            }

            occupied.push({leaving, chair});
        }

        return -1;
    }
};
