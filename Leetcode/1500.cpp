constexpr int MAXN = 1e4+5;

class FileSharing {
private:
    vector<unordered_set<int> > chunks;
    unordered_map<int, vector<int> > user2chunks;
    set<int> unusedUserId;
public:
    FileSharing(int m) {
        for (int i = 1; i < MAXN; ++i) {
            unusedUserId.insert(i);
        }
        chunks.resize(m+1);
    }
    
    int join(vector<int> ownedChunks) {
        auto iter = unusedUserId.begin();
        int id = *iter;
        unusedUserId.erase(iter);
        for (const auto &i : ownedChunks) {
            chunks[i].insert(id);
        }
        user2chunks[id] = ownedChunks;
        return id;
    }
    
    void leave(int userID) {
        for (const auto &[k,vList] : user2chunks) {
            for (const auto &i : vList) {
                chunks[i].erase(userID);
            }
        }
        user2chunks.erase(userID);
        unusedUserId.insert(userID);
    }
    
    vector<int> request(int userID, int chunkID) {
        vector<int> ans;
        for (const auto &i : chunks[chunkID]) {
            ans.emplace_back(i);
        }
        sort(ans.begin(),ans.end());
        if (!ans.empty()) {
            // Update only when someone has this chunk
            user2chunks[userID].emplace_back(chunkID);
            chunks[chunkID].insert(userID);
        }
        return ans;
    }
};

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing* obj = new FileSharing(m);
 * int param_1 = obj->join(ownedChunks);
 * obj->leave(userID);
 * vector<int> param_3 = obj->request(userID,chunkID);
 */