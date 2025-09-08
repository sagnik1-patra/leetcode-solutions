class Solution {
    // max-heap for lower half, min-heap for upper half
    priority_queue<long long> lo;                              // lower (max-heap)
    priority_queue<long long, vector<long long>, greater<>> hi; // upper (min-heap)
    unordered_map<long long,int> delayed; // value -> how many times to delete lazily
    int loSize = 0, hiSize = 0;           // sizes excluding delayed elements

    void prune(priority_queue<long long>& heap) {
        while (!heap.empty()) {
            long long x = heap.top();
            auto it = delayed.find(x);
            if (it == delayed.end()) break;
            if (--(it->second) == 0) delayed.erase(it);
            heap.pop();
        }
    }
    void prune(priority_queue<long long, vector<long long>, greater<>>& heap) {
        while (!heap.empty()) {
            long long x = heap.top();
            auto it = delayed.find(x);
            if (it == delayed.end()) break;
            if (--(it->second) == 0) delayed.erase(it);
            heap.pop();
        }
    }

    // keep |lo| == |hi| or |lo| = |hi|+1
    void rebalance() {
        if (loSize > hiSize + 1) {
            hi.push(lo.top()); lo.pop();
            loSize--; hiSize++;
            prune(lo);
        } else if (loSize < hiSize) {
            lo.push(hi.top()); hi.pop();
            loSize++; hiSize--;
            prune(hi);
        }
    }

    void add(long long x) {
        if (lo.empty() || x <= lo.top()) {
            lo.push(x);
            loSize++;
        } else {
            hi.push(x);
            hiSize++;
        }
        rebalance();
    }

    void remove(long long x) {
        // mark for lazy deletion and adjust logical sizes
        delayed[x]++;
        if (!lo.empty() && x <= lo.top()) {
            loSize--;
            if (x == lo.top()) prune(lo);
        } else {
            hiSize--;
            if (!hi.empty() && x == hi.top()) prune(hi);
        }
        rebalance();
    }

    double median(int k) {
        if (k & 1) return (double)lo.top();
        return ((double)lo.top() + (double)hi.top()) * 0.5;
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        ans.reserve(nums.size() - k + 1);

        // build first window
        for (int i = 0; i < k; ++i) add(nums[i]);
        ans.push_back(median(k));

        for (int i = k; i < (int)nums.size(); ++i) {
            add(nums[i]);
            remove(nums[i - k]);
            ans.push_back(median(k));
        }
        return ans;
    }
};