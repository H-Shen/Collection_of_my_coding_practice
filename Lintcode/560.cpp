class FriendshipService {
private:
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, unordered_set<int>> followings;
public:
    FriendshipService() {
        // do intialization if necessary
    }

    /*
     * @param user_id: An integer
     * @return: all followers and sort by user_id
     */
    vector<int> getFollowers(int user_id) const {
        // write your code here
        auto iter = followers.find(user_id);
        if (iter == followers.end()) {
            return vector<int>();
        }
        vector<int> result(iter->second.begin(),iter->second.end());
        sort(result.begin(),result.end());
        return result;
    }

    /*
     * @param user_id: An integer
     * @return: all followings and sort by user_id
     */
    vector<int> getFollowings(int user_id) const {
        // write your code here
        auto iter = followings.find(user_id);
        if (iter == followings.end()) {
            return vector<int>();
        }
        vector<int> result(iter->second.begin(),iter->second.end());
        sort(result.begin(),result.end());
        return result;
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void follow(int to_user_id, int from_user_id) {
        // write your code here
        followers[to_user_id].insert(from_user_id);
        followings[from_user_id].insert(to_user_id);
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void unfollow(int to_user_id, int from_user_id) {
        // write your code here
        auto iter = followers.find(to_user_id);
        if (iter != followers.end()) {
            iter->second.erase(from_user_id);
        }
        auto iter2 = followings.find(from_user_id);
        if (iter2 != followings.end()) {
            iter2->second.erase(to_user_id);
        }
    }
};