class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> boxes(50, 0);
        int answer = 0;

        for (int num = lowLimit; num <= highLimit; num++) {
            int x = num;
            int digitSum = 0;

            while (x > 0) {
                digitSum += x % 10;
                x /= 10;
            }

            boxes[digitSum]++;
            answer = max(answer, boxes[digitSum]);
        }

        return answer;
    }
};