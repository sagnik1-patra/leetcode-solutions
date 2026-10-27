class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers,
                      int pills, int strength) {

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int n = tasks.size();
        int m = workers.size();

        auto canAssign = [&](int k) {
            multiset<int> available;

            // Select the k strongest workers
            for (int i = m - k; i < m; i++) {
                available.insert(workers[i]);
            }

            int pillsLeft = pills;

            // Assign the k easiest tasks, hardest first
            for (int i = k - 1; i >= 0; i--) {

                int task = tasks[i];

                // Try assigning without a pill
                auto it = available.lower_bound(task);

                if (it != available.end()) {
                    available.erase(it);
                }
                else {
                    // A pill is required
                    if (pillsLeft == 0)
                        return false;

                    // Find weakest worker who can do it with a pill
                    it = available.lower_bound(task - strength);

                    if (it == available.end())
                        return false;

                    available.erase(it);
                    pillsLeft--;
                }
            }

            return true;
        };

        int low = 0;
        int high = min(n, m);
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canAssign(mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};