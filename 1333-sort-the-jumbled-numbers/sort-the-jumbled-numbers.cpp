
class Solution {
public:
    int getMapped(int num, vector<int>& mapping) {
        if (num == 0)
            return mapping[0];

        int result = 0;
        int place = 1;

        while (num > 0) {
            int digit = num % 10;
            result += mapping[digit] * place;

            place *= 10;
            num /= 10;
        }

        return result;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> arr;

        for (int num : nums) {
            arr.push_back({getMapped(num, mapping), num});
        }

        stable_sort(arr.begin(), arr.end(),
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first;
            });

        vector<int> ans;

        for (auto& p : arr) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
