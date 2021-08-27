using ll = long long;

struct Server {
    int weight;
    int index;
    Server(int w, int i) : weight(w), index(i) {}
    bool operator < (const Server &o) const {
        if (weight == o.weight) {
            return index > o.index;
        }
        return weight > o.weight;
    }
};

struct Task {
    Server server;
    ll startTime, endTime;
    Task(Server s, ll st, ll et) : server(s), startTime(st), endTime(et) {}
    bool operator < (const Task &o) const {
        return endTime > o.endTime;
    }
};

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = (int)servers.size();
        int m = (int)tasks.size();
        vector<int> ans(m);
        priority_queue<Server, vector<Server>, less<Server> > freeServers;
        priority_queue<Task, vector<Task>, less<Task> > tasksOngoing;
        for (int i = 0; i < n; ++i) {
            freeServers.push(Server(servers[i],i));
        }
        ll currentTime = 0;
        int i = 0;  // currentJobIndex = i
        while (i < m) {
            if (freeServers.empty()) {
                currentTime = max(currentTime,tasksOngoing.top().endTime);
                while (!tasksOngoing.empty() && tasksOngoing.top().endTime <= currentTime) {
                    freeServers.push(tasksOngoing.top().server);
                    tasksOngoing.pop();
                }
                while (currentTime >= (ll)i && !freeServers.empty() && i < m) {
                    ans[i] = freeServers.top().index;
                    tasksOngoing.push(Task(freeServers.top(), currentTime, currentTime + tasks[i]));
                    freeServers.pop();
                    ++i;
                }
            }
            else {
                if (currentTime < (ll)i) {
                    currentTime = (ll)i;
                    while (!tasksOngoing.empty() && tasksOngoing.top().endTime <= currentTime) {
                        freeServers.push(tasksOngoing.top().server);
                        tasksOngoing.pop();
                    }
                }
                while (currentTime >= (ll)i && !freeServers.empty() && i < m) {
                    ans[i] = freeServers.top().index;
                    tasksOngoing.push(Task(freeServers.top(), currentTime, currentTime + tasks[i]));
                    freeServers.pop();
                    ++i;
                }
            }
        }
        
        return ans;
    }
};