class Solution {
public:
    int rand10() {
        while (true) {
            int a = rand7();
            int b = rand7();
            int idx = (a - 1) * 7 + b; // 1..49
            if (idx <= 40) {
                return 1 + (idx - 1) % 10; // 1..10 uniformly
            }
            // else retry
        }
    }
};