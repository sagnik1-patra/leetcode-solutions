class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int time = 1;

        while (true) {

            // Neither memory stick can provide 'time' bits
            if (memory1 < time && memory2 < time) {
                break;
            }

            // Choose the stick with more available memory.
            // If equal, choose memory1.
            if (memory1 >= memory2) {
                if (memory1 >= time) {
                    memory1 -= time;
                } else {
                    memory2 -= time;
                }
            } 
            else {
                if (memory2 >= time) {
                    memory2 -= time;
                } else {
                    memory1 -= time;
                }
            }

            time++;
        }

        return {time, memory1, memory2};
    }
};