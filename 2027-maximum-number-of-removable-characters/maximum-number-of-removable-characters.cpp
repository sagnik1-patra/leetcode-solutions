
class Solution {
public:
    bool isSubsequence(string& s, string& p,
                       vector<int>& removable, int k) {
        vector<bool> removed(s.size(), false);

        for (int i = 0; i < k; i++) {
            removed[removable[i]] = true;
        }

        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            if (!removed[i] && j < p.size() && s[i] == p[j]) {
                j++;
            }
        }

        return j == p.size();
    }

    int maximumRemovals(string s, string p,
                        vector<int>& removable) {
        int left = 0;
        int right = removable.size();

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            if (isSubsequence(s, p, removable, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};
