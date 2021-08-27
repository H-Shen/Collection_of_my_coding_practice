class AuthenticationManager {
private:
    int timeToLive;
    unordered_map<string, int> unmap;
public:
    AuthenticationManager(int timeToLive) : timeToLive(timeToLive) {
        
    }
    
    void generate(string tokenId, int currentTime) {
        unmap[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if (unmap[tokenId] <= currentTime) return;
        unmap[tokenId] = currentTime + timeToLive;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int counter = 0;
        for (const auto &[k,v] : unmap) {
            if (v > currentTime) ++counter;
        }
        return counter;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */