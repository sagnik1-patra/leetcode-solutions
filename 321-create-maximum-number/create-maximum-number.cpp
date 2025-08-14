class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> best;

        int start = max(0, k - n), end = min(k, m);
        for (int i = start; i <= end; ++i) {     // i from nums1, k-i from nums2
            vector<int> a = pickMax(nums1, i);
            vector<int> b = pickMax(nums2, k - i);
            vector<int> cand = merge(a, b, k);
            if (best.empty() || lexGreater(cand, 0, best, 0)) best = move(cand);
        }
        return best;
    }

private:
    // Greedily pick the maximum subsequence of length t from nums
    vector<int> pickMax(const vector<int>& nums, int t) {
        vector<int> st;
        int drop = (int)nums.size() - t;
        for (int d : nums) {
            while (!st.empty() && drop && st.back() < d) {
                st.pop_back();
                --drop;
            }
            st.push_back(d);
        }
        st.resize(t);
        return st;
    }

    // Compare vectors a[i..] and b[j..] lexicographically
    bool lexGreater(const vector<int>& a, int i, const vector<int>& b, int j) {
        int na = a.size(), nb = b.size();
        while (i < na && j < nb && a[i] == b[j]) { ++i; ++j; }
        if (j == nb) return true;
        if (i == na) return false;
        return a[i] > b[j];
    }

    // Merge two sequences into the maximum possible sequence of length k
    vector<int> merge(const vector<int>& a, const vector<int>& b, int k) {
        vector<int> res; res.reserve(k);
        int i = 0, j = 0;
        while ((int)res.size() < k) {
            if (lexGreater(a, i, b, j)) res.push_back(a[i++]);
            else                        res.push_back(b[j++]);
        }
        return res;
    }
};
