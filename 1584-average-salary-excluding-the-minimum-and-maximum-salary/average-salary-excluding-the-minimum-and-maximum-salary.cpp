class Solution {
public:
    double average(vector<int>& salary) {
        int minSalary = *min_element(salary.begin(), salary.end());
        int maxSalary = *max_element(salary.begin(), salary.end());

        int sum = 0;
        for (int x : salary) {
            sum += x;
        }

        return (double)(sum - minSalary - maxSalary) / (salary.size() - 2);
    }
};