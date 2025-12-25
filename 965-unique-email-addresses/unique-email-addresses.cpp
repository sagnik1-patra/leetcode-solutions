class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;

        for (string email : emails) {
            string local, domain;
            int i = 0;

            // Process local name
            while (email[i] != '@') {
                if (email[i] == '+') {
                    // Ignore rest of local name
                    while (email[i] != '@') i++;
                    break;
                }
                if (email[i] != '.') {
                    local += email[i];
                }
                i++;
            }

            // Process domain
            domain = email.substr(i); // includes '@'

            unique.insert(local + domain);
        }

        return unique.size();
    }
};
