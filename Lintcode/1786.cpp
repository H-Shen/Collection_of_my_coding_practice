/* Definition of PushNotification
 * class PushNotification {
 * public:
 *     void static notify(int user_id, string message) 
 *  };
 */
class PubSubPattern {
private:
	unordered_map<string, unordered_set<int>> channel2users;
public:
	PubSubPattern() {
		// initialize your data structure here.
	}
	/**
	* @param channel:
	* @param user_id:
	* @return: nothing
	*/
	void subscribe(string &channel, int user_id) {
		// Write your code here
		channel2users[channel].insert(user_id);
	}

	/**
	* @param channel:
	* @param user_id:
	* @return: nothing
	*/
	void unsubscribe(string &channel, int user_id) {
		// Write your code here
		auto iter = channel2users.find(channel);
		if (iter != channel2users.end()) {
			iter->second.erase(user_id);
			if (iter->second.empty()) {
				channel2users.erase(iter);
			}
		}
	}

	/**
	* @param channel:
	* @param message:
	* @return: nothing
	*/
	void publish(string &channel, string &message) {
		// Write your code here
		auto iter = channel2users.find(channel);
		if (iter != channel2users.end()) {
			for (auto& user_id : iter->second) {
				PushNotification::notify(user_id, message);
			}
		}
	}
};