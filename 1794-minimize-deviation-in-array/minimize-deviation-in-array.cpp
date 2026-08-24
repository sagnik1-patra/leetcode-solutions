class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn = INT_MAX;

        for (int x : nums) {
            if (x % 2 == 1) {
                x *= 2;
            }

            pq.push(x);
            mn = min(mn, x);
        }

        int ans = INT_MAX;

        while (!pq.empty()) {
            int mx = pq.top();
            pq.pop();

            ans = min(ans, mx - mn);

            if (mx % 2 == 1) {
                break;
            }

            mx /= 2;
            mn = min(mn, mx);
            pq.push(mx);
        }

        return ans;
    }
};