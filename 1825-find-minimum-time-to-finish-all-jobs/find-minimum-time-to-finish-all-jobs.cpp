class Solution {
public:
    int answer = INT_MAX;

    void backtrack(vector<int>& jobs, vector<int>& workers, int index) {
        if (index == jobs.size()) {
            int maxTime = 0;

            for (int time : workers) {
                maxTime = max(maxTime, time);
            }

            answer = min(answer, maxTime);
            return;
        }

        for (int i = 0; i < workers.size(); i++) {

            // Pruning: no need to continue if already worse
            if (workers[i] + jobs[index] >= answer) {
                continue;
            }

            workers[i] += jobs[index];

            backtrack(jobs, workers, index + 1);

            workers[i] -= jobs[index];

            // If this worker was empty, trying other empty
            // workers gives the same result
            if (workers[i] == 0) {
                break;
            }
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        // Larger jobs first gives better pruning
        sort(jobs.rbegin(), jobs.rend());

        vector<int> workers(k, 0);

        // Initial upper bound
        int sum = 0;
        for (int job : jobs) {
            sum += job;
        }

        answer = sum;

        backtrack(jobs, workers, 0);

        return answer;
    }
};