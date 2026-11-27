class Solution {
public:
    int ans = INT_MAX;

    void backtrack(vector<int>& cookies, vector<int>& children,
                   int index, int k) {

        if (index == cookies.size()) {

            int unfairness = *max_element(children.begin(),
                                         children.end());

            ans = min(ans, unfairness);
            return;
        }

        for (int i = 0; i < k; i++) {

            // Give the current bag to child i
            children[i] += cookies[index];

            // Explore only if a better answer is possible
            if (children[i] < ans) {
                backtrack(cookies, children, index + 1, k);
            }

            // Undo the distribution
            children[i] -= cookies[index];

            // Avoid equivalent distributions among empty children
            if (children[i] == 0)
                break;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {

        ans = INT_MAX;
        vector<int> children(k, 0);

        sort(cookies.rbegin(), cookies.rend());

        backtrack(cookies, children, 0, k);

        return ans;
    }
};