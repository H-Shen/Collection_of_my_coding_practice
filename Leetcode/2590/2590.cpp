class TodoList {
private:
    int currentTaskId = 1;
    struct Node {
        unordered_map<int, string> taskId2description;
        unordered_map<int, int> taskId2dueDate;
        unordered_map<int, vector<string>> taskId2tags;
        unordered_map<string, unordered_set<int>> tag2taskId;
    };
    unordered_map<int, Node> userId2Node;
public:
    TodoList() {

    }

    int addTask(int userId, string taskDescription, int dueDate, const vector<string>& tags) {
        Node& node = userId2Node[userId];
        node.taskId2description[currentTaskId] = std::move(taskDescription);
        node.taskId2dueDate[currentTaskId] = dueDate;
        node.taskId2tags[currentTaskId] = tags;
        for (const auto &tag : tags) {
            node.tag2taskId[tag].insert(currentTaskId);
        }
        ++currentTaskId;
        return currentTaskId-1;
    }

    vector<string> getAllTasks(int userId) {
        if (userId2Node.count(userId) == 0) {
            return {};
        }
        Node& node = userId2Node[userId];
        int n = (int)node.taskId2description.size();
        vector<pair<string,int>> result(n);
        auto iter = node.taskId2description.begin();
        for (int i = 0; i < n; ++i, ++iter) {
            result[i].first = iter->second;
            result[i].second = node.taskId2dueDate[iter->first];
        }
        sort(result.begin(),result.end(),[](const auto &l, const auto &r){
            return l.second < r.second;
        });
        vector<string> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = result[i].first;
        }
        return res;
    }

    vector<string> getTasksForTag(int userId, const string& tag) {
        if (userId2Node.count(userId) == 0) {
            return {};
        }
        Node& node = userId2Node[userId];
        if (node.tag2taskId.count(tag) == 0) {
            return {};
        }
        unordered_set<int>& temp = node.tag2taskId[tag];
        int n = (int)temp.size();
        vector<pair<string,int>> tasksWithDueDate(n);
        auto iter = temp.begin();
        for (int i = 0; i < n; ++i, ++iter) {
            tasksWithDueDate[i].first = node.taskId2description[*iter];
            tasksWithDueDate[i].second = node.taskId2dueDate[*iter];
        }
        sort(tasksWithDueDate.begin(), tasksWithDueDate.end(), [](const auto &l, const auto &r){
            return l.second < r.second;
        });
        vector<string> tasks(n);
        for (int i = 0; i < n; ++i) {
            tasks[i] = tasksWithDueDate[i].first;
        }
        return tasks;
    }

    void completeTask(int userId, int taskId) {
        if (userId2Node.count(userId) == 0) {
            return;
        }
        Node& node = userId2Node[userId];
        if (node.taskId2description.count(taskId) == 0) {
            return;
        }
        node.taskId2description.erase(taskId);
        node.taskId2dueDate.erase(taskId);
        vector<string>& vec = node.taskId2tags[taskId];
        for (const auto &i : vec) {
            node.tag2taskId[i].erase(taskId);
            if (node.tag2taskId[i].empty()) {
                node.tag2taskId.erase(i);
            }
        }
        node.taskId2tags.erase(taskId);
    }
};

/**
 * Your TodoList object will be instantiated and called as such:
 * TodoList* obj = new TodoList();
 * int param_1 = obj->addTask(userId,taskDescription,dueDate,tags);
 * vector<string> param_2 = obj->getAllTasks(userId);
 * vector<string> param_3 = obj->getTasksForTag(userId,tag);
 * obj->completeTask(userId,taskId);
 */