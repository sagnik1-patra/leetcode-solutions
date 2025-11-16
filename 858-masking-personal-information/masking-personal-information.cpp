class Solution {
public:
    string maskPII(string s) {
        // Check if it's an email (contains '@')
        if (s.find('@') != string::npos) {
            return maskEmail(s);
        } else {
            return maskPhone(s);
        }
    }

private:
    string maskEmail(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int atPos = s.find('@');
        string name = s.substr(0, atPos);
        string domain = s.substr(atPos);
        return string(1, name[0]) + "*****" + string(1, name.back()) + domain;
    }

    string maskPhone(string s) {
        string digits = "";
        for (char c : s) {
            if (isdigit(c)) digits += c;
        }

        int n = digits.size();
        string local = digits.substr(n - 4);
        string masked = "***-***-" + local;

        if (n > 10) {
            string prefix = "+";
            for (int i = 0; i < n - 10; i++) prefix += "*";
            masked = prefix + "-" + masked;
        }

        return masked;
    }
};