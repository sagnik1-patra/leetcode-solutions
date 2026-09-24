class Solution {
public:
    vector<long long> getSums(vector<int>& nums, int left, int right) {
        vector<long long> sums = {0};

        for (int i = left; i < right; i++) {
            int size = sums.size();

            for (int j = 0; j < size; j++) {
                sums.push_back(sums[j] + nums[i]);
            }
        }

        return sums;
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n / 2;

        vector<long long> leftSums = getSums(nums, 0, mid);
        vector<long long> rightSums = getSums(nums, mid, n);

        sort(rightSums.begin(), rightSums.end());

        long long answer = llabs((long long)goal);

        for (long long leftSum : leftSums) {
            long long target = (long long)goal - leftSum;

            auto it = lower_bound(
                rightSums.begin(),
                rightSums.end(),
                target
            );

            if (it != rightSums.end()) {
                answer = min(
                    answer,
                    llabs(leftSum + *it - goal)
                );
            }

            if (it != rightSums.begin()) {
                --it;

                answer = min(
                    answer,
                    llabs(leftSum + *it - goal)
                );
            }

            if (answer == 0) {
                return 0;
            }
        }

        return (int)answer;
    }
};