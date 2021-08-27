class Logger {
public:
    unordered_map<string, int> unmap;
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        constexpr int GAP = 10;
        if (unmap.find(message) == unmap.end()) {
            unmap[message] = timestamp;
            return true;
        }
        if (timestamp < unmap[message] + GAP) {
            return false;
        }
        unmap[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */