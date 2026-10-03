class Solution {
public:
    int batchSize;
    unordered_map<long long, int> memo;

    int dfs(vector<int>& cnt, int rem) {

        // Encode counts into a long long
        long long state = 0;

        for (int i = 1; i < batchSize; i++) {
            state = (state << 5) | cnt[i];
        }

        // Include current remainder
        long long key = (state << 4) | rem;

        if (memo.count(key)) {
            return memo[key];
        }

        int best = 0;

        for (int r = 1; r < batchSize; r++) {

            if (cnt[r] == 0)
                continue;

            cnt[r]--;

            int happy = (rem == 0) ? 1 : 0;

            int newRem = (rem + r) % batchSize;

            best = max(
                best,
                happy + dfs(cnt, newRem)
            );

            cnt[r]++;
        }

        return memo[key] = best;
    }

    int maxHappyGroups(int batchSize, vector<int>& groups) {

        this->batchSize = batchSize;

        vector<int> cnt(batchSize, 0);

        for (int g : groups) {
            cnt[g % batchSize]++;
        }

        // Groups divisible by batchSize
        // are always happy.
        int answer = cnt[0];
        cnt[0] = 0;

        // Greedily pair complementary remainders
        for (int i = 1; i < batchSize; i++) {

            int j = batchSize - i;

            if (i >= j)
                break;

            int pairs = min(cnt[i], cnt[j]);

            answer += pairs;

            cnt[i] -= pairs;
            cnt[j] -= pairs;
        }

        // Special case when batchSize is even:
        // remainder batchSize/2 pairs with itself
        if (batchSize % 2 == 0) {

            int r = batchSize / 2;

            answer += cnt[r] / 2;
            cnt[r] %= 2;
        }

        memo.clear();

        answer += dfs(cnt, 0);

        return answer;
    }
};