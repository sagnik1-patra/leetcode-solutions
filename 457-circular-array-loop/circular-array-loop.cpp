class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto nextIdx = [&](int i) -> int {
            long long j = (long long)i + nums[i];
            j %= n;
            if (j < 0) j += n;
            return (int)j;
        };

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue;                 // already processed

            bool dir = nums[i] > 0;                     // target direction
            int slow = i, fast = i;

            // Floyd's algorithm with direction checks
            while (true) {
                // move slow one step
                int ns = nextIdx(slow);
                if (nums[slow] == 0 || (nums[ns] > 0) != dir) break;

                // move fast two steps
                int nf = nextIdx(fast);
                if (nums[fast] == 0 || (nums[nf] > 0) != dir) break;
                nf = nextIdx(nf);
                if (nums[nf] == 0 || (nums[nf] > 0) != dir) break;

                slow = ns;
                fast = nf;

                if (slow == fast) {
                    // reject 1-length loop (self-loop)
                    if (slow == nextIdx(slow)) break;
                    return true;
                }
            }

            // mark all nodes along this path as visited (set to 0)
            int idx = i;
            while (nums[idx] != 0 && (nums[idx] > 0) == dir) {
                int nxt = nextIdx(idx);
                nums[idx] = 0;
                idx = nxt;
            }
        }
        return false;
    }
};
