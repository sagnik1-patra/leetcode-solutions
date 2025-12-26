class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs, digitLogs;

        for (string& log : logs) {
            int pos = log.find(' ');
            if (isdigit(log[pos + 1])) {
                digitLogs.push_back(log);
            } else {
                letterLogs.push_back(log);
            }
        }

        sort(letterLogs.begin(), letterLogs.end(),
             [](const string& a, const string& b) {
                 int posA = a.find(' ');
                 int posB = b.find(' ');

                 string contentA = a.substr(posA + 1);
                 string contentB = b.substr(posB + 1);

                 if (contentA == contentB)
                     return a.substr(0, posA) < b.substr(0, posB);

                 return contentA < contentB;
             });

        letterLogs.insert(letterLogs.end(), digitLogs.begin(), digitLogs.end());
        return letterLogs;
    }
};
