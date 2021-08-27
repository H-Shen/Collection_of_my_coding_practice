class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // id each station
        unordered_map<string, int> name2id;
        int id = 0;
        vector<string> id2name;
        for (const auto &i : tickets) {
            for (const auto &j : i) {
                if (name2id.find(j) == name2id.end()) {
                    name2id[j] = id;
                    ++id;
                    id2name.emplace_back(j);
                }
            }
        }
        // create the graph and store in an adjacency list, and sort each element in the list lexicalgraphically
        int u, v;
        vector<deque<int> > AL(id);
        vector<int> inDegree(id);
        vector<int> outDegree(id);
        for (const auto &i : tickets) {
            u = name2id[i[0]];
            v = name2id[i[1]];
            AL[u].emplace_back(v);
            ++outDegree.at(u);
            ++inDegree.at(v);
        }
        int startVertex = name2id["JFK"];   //
        for (auto &i : AL) {
            sort(i.begin(), i.end(), [&](const auto &l, const auto &r){
                return id2name[l] < id2name[r];
            });
        }
        // run Hierholzer
        auto Hierholzer = [&]() {
            stack<int> path;
            vector<int> circuit;
            int current = startVertex;
            path.push(current);
            while (!path.empty()) {
                if (!AL.at(current).empty()) {
                    path.push(current);
                    int next = AL.at(current).front();
                    AL.at(current).pop_front();
                    current = next;
                } else {
                    circuit.emplace_back(current);
                    current = path.top();
                    path.pop();
                }
            }
            reverse(circuit.begin(), circuit.end());
            return circuit;
        };
        auto result = Hierholzer();
        vector<string> output(result.size());
        auto iter = output.begin();
        // output
        for (const auto &i : result) {
            *iter = id2name[i];
            ++iter;
        }
        return output;
    }
};