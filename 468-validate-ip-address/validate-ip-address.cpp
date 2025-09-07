class Solution {
public:
    string validIPAddress(string queryIP) {
        if (count(queryIP.begin(), queryIP.end(), '.') == 3 && isIPv4(queryIP)) return "IPv4";
        if (count(queryIP.begin(), queryIP.end(), ':') == 7 && isIPv6(queryIP)) return "IPv6";
        return "Neither";
    }

private:
    // Split that preserves empty tokens (so "1..1" yields {"1","","1"})
    static vector<string> split(const string& s, char delim) {
        vector<string> parts;
        string cur;
        for (char c : s) {
            if (c == delim) {
                parts.push_back(cur);
                cur.clear();
            } else {
                cur.push_back(c);
            }
        }
        parts.push_back(cur); // last chunk
        return parts;
    }

    static bool isIPv4(const string& ip) {
        // exactly 4 parts, each 1..3 digits, no leading zeros unless single '0', 0..255
        auto parts = split(ip, '.');
        if (parts.size() != 4) return false;

        for (const string& p : parts) {
            if (p.empty() || p.size() > 3) return false;
            // only digits
            for (char c : p) if (!isdigit(static_cast<unsigned char>(c))) return false;
            // no leading zero unless exactly "0"
            if (p.size() > 1 && p[0] == '0') return false;
            // range 0..255
            int val = 0;
            for (char c : p) { val = val * 10 + (c - '0'); }
            if (val < 0 || val > 255) return false;
        }
        return true;
    }

    static bool isHex(char c) {
        return ('0' <= c && c <= '9')
            || ('a' <= c && c <= 'f')
            || ('A' <= c && c <= 'F');
    }

    static bool isIPv6(const string& ip) {
        // exactly 8 parts, each 1..4 hex chars
        auto parts = split(ip, ':');
        if (parts.size() != 8) return false;

        for (const string& p : parts) {
            if (p.empty() || p.size() > 4) return false;
            for (char c : p) if (!isHex(c)) return false;
        }
        return true;
    }
};