class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>, 
                       greater<pair<int, int>>> pq;
        
        int n = apples.size();
        int day = 0;
        int eaten = 0;

        while (day < n || !pq.empty()) {

            // Add today's apples
            if (day < n && apples[day] > 0) {
                int expiryDay = day + days[day];
                pq.push({expiryDay, apples[day]});
            }

            // Remove rotten apples
            while (!pq.empty() && pq.top().first <= day) {
                pq.pop();
            }

            // Eat one apple that expires earliest
            if (!pq.empty()) {
                auto current = pq.top();
                pq.pop();

                current.second--;
                eaten++;

                if (current.second > 0) {
                    pq.push(current);
                }
            }

            day++;
        }

        return eaten;
    }
};