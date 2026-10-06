class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms,
                            vector<vector<int>>& queries) {

        int k = queries.size();

        // Sort rooms by size descending
        sort(rooms.begin(), rooms.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });

        // Store queries as:
        // {minSize, preferred, originalIndex}
        vector<vector<int>> q;

        for (int i = 0; i < k; i++) {
            q.push_back({
                queries[i][1],
                queries[i][0],
                i
            });
        }

        // Sort queries by minSize descending
        sort(q.begin(), q.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] > b[0];
             });

        vector<int> answer(k, -1);

        // Contains IDs of rooms that satisfy current minSize
        set<int> available;

        int roomIndex = 0;

        for (auto &query : q) {

            int minSize = query[0];
            int preferred = query[1];
            int originalIndex = query[2];

            // Add every room large enough for this query
            while (roomIndex < rooms.size() &&
                   rooms[roomIndex][1] >= minSize) {

                available.insert(rooms[roomIndex][0]);
                roomIndex++;
            }

            if (available.empty()) {
                answer[originalIndex] = -1;
                continue;
            }

            // First room ID >= preferred
            auto it = available.lower_bound(preferred);

            int best = -1;

            // Candidate on the right
            if (it != available.end()) {
                best = *it;
            }

            // Candidate on the left
            if (it != available.begin()) {

                auto prevIt = prev(it);
                int left = *prevIt;

                if (best == -1 ||
                    abs(left - preferred) <=
                    abs(best - preferred)) {

                    best = left;
                }
            }

            answer[originalIndex] = best;
        }

        return answer;
    }
};