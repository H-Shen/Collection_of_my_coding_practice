#include <random>

class LoadBalancer {
private:
    unordered_map<int, int> serverId2Index;
    vector<int> index2serverId;
    random_device rd;
    mt19937 gen;
public:
    LoadBalancer() : rd(), gen(rd()) {
        // do intialization if necessary
    }

    /*
     * @param server_id: add a new server to the cluster
     * @return: nothing
     */
    void add(int server_id) {
        // write your code here
        if (serverId2Index.count(server_id) == 0) {
            serverId2Index[server_id] = (int)index2serverId.size();
            index2serverId.emplace_back(server_id);
        }
    }

    /*
     * @param server_id: server_id remove a bad server from the cluster
     * @return: nothing
     */
    void remove(int server_id) {
        // write your code here
        if (serverId2Index.count(server_id) > 0) {
            int index = serverId2Index[server_id];
            serverId2Index.erase(server_id);
            if (index != (int)index2serverId.size()-1) {
                index2serverId[index] = index2serverId.back();
                index2serverId.pop_back();
                serverId2Index[index2serverId[index]] = index;
            }
            else {
                index2serverId.pop_back();
            }
        }
    }

    /*
     * @return: pick a server in the cluster randomly with equal probability
     */
    int pick() {
        // write your code here
        if (index2serverId.empty()) {
            throw invalid_argument("no servers available");
        }
        uniform_int_distribution<> dist(0, (int)index2serverId.size()-1);
        return index2serverId[dist(gen)];
    }
};