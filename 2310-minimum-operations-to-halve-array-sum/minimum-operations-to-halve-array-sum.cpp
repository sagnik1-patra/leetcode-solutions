
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0;

        for (int num : nums) {
            sum += num;
            pq.push(num);
        }

        double target = sum / 2.0;
        double reduced = 0;
        int operations = 0;

        while (reduced < target) {
            double largest = pq.top();
            pq.pop();

            double half = largest / 2.0;

            reduced += half;
            pq.push(half);

            operations++;
        }

        return operations;
    }
};
