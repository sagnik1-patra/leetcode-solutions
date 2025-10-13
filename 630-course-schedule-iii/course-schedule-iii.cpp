class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto &a, auto &b) {
            return a[1] < b[1];  // Sort by lastDay
        });

        priority_queue<int> maxHeap;
        int currentTime = 0;

        for (auto &course : courses) {
            int duration = course[0];
            int lastDay = course[1];
            currentTime += duration;
            maxHeap.push(duration);

            if (currentTime > lastDay) {
                currentTime -= maxHeap.top(); // Drop longest duration
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};
