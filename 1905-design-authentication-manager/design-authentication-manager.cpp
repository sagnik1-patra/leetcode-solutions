class AuthenticationManager {
private:
    int ttl;
    unordered_map<string, int> tokens;

public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + ttl;
    }

    void renew(string tokenId, int currentTime) {
        // Token must exist and must not be expired
        if (tokens.count(tokenId) &&
            tokens[tokenId] > currentTime) {

            tokens[tokenId] = currentTime + ttl;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;

        for (auto &token : tokens) {
            if (token.second > currentTime) {
                count++;
            }
        }

        return count;
    }
};