class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        bool inBlock = false;
        string newline;

        for (string& line : source) {
            int n = line.size();
            if (!inBlock) newline = "";

            for (int i = 0; i < n; ++i) {
                if (!inBlock && i + 1 < n && line[i] == '/' && line[i + 1] == '*') {
                    inBlock = true;
                    ++i; // skip '*'
                } 
                else if (inBlock && i + 1 < n && line[i] == '*' && line[i + 1] == '/') {
                    inBlock = false;
                    ++i; // skip '/'
                } 
                else if (!inBlock && i + 1 < n && line[i] == '/' && line[i + 1] == '/') {
                    break; // line comment — ignore rest of line
                } 
                else if (!inBlock) {
                    newline += line[i];
                }
            }

            if (!inBlock && !newline.empty())
                result.push_back(newline);
        }

        return result;
    }
};
