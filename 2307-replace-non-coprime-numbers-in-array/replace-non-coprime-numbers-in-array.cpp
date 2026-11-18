
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;

        for (int num : nums) {
            long long curr = num;

            while (!st.empty()) {
                long long g = gcd((long long)st.back(), curr);

                if (g == 1)
                    break;

                curr = (st.back() / g) * curr;
                st.pop_back();
            }

            st.push_back((int)curr);
        }

        return st;
    }
};
