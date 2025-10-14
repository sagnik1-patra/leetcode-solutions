class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> st;
        int prevTime = 0;

        for (string& log : logs) {
            int id, time;
            string type;

            // Parse log string
            auto p1 = log.find(':');
            auto p2 = log.find(':', p1 + 1);
            id = stoi(log.substr(0, p1));
            type = log.substr(p1 + 1, p2 - p1 - 1);
            time = stoi(log.substr(p2 + 1));

            if (type == "start") {
                if (!st.empty())
                    result[st.top()] += time - prevTime; // pause current
                st.push(id);
                prevTime = time; // mark start time
            } else { // "end"
                result[st.top()] += time - prevTime + 1; // include end timestamp
                st.pop();
                prevTime = time + 1; // resume next at next timestamp
            }
        }

        return result;
    }
};
