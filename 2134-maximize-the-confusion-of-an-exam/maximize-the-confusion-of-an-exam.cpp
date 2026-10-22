
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0;
        int countT = 0;
        int countF = 0;
        int ans = 0;

        for (int right = 0; right < answerKey.size(); right++) {
            if (answerKey[right] == 'T') {
                countT++;
            } else {
                countF++;
            }

            while (min(countT, countF) > k) {
                if (answerKey[left] == 'T') {
                    countT--;
                } else {
                    countF--;
                }
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
