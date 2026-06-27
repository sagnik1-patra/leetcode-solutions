class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> mp = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"}
        };
        
        string result;
        
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == '&') {
                bool found = false;
                
                // check all possible entity lengths
                for (int len = 4; len <= 7 && i + len <= text.size(); len++) {
                    string sub = text.substr(i, len);
                    
                    if (mp.count(sub)) {
                        result += mp[sub];
                        i += len - 1;
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    result += text[i];
                }
            } else {
                result += text[i];
            }
        }
        
        return result;
    }
};