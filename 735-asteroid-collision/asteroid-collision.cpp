class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && a < 0 && st.back() > 0) {
                if (st.back() < -a) {
                    st.pop_back(); // right-moving asteroid is smaller, destroyed
                    continue;
                } else if (st.back() == -a) {
                    st.pop_back(); // both explode
                }
                destroyed = true; // current one destroyed
                break;
            }

            if (!destroyed)
                st.push_back(a);
        }

        return st;
    }
};