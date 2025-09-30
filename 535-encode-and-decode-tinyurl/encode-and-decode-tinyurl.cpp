class Solution {
private:
    unordered_map<string, string> shortToLong;
    unordered_map<string, string> longToShort;
    int counter = 0;
    const string base = "http://tinyurl.com/";

public:
    Solution() {}

    string encode(string longUrl) {
        // If already encoded, return existing tiny URL
        if (longToShort.count(longUrl)) {
            return longToShort[longUrl];
        }
        
        string key = to_string(counter++);
        string shortUrl = base + key;
        
        longToShort[longUrl] = shortUrl;
        shortToLong[shortUrl] = longUrl;

        return shortUrl;
    }

    string decode(string shortUrl) {
        return shortToLong[shortUrl];
    }
};