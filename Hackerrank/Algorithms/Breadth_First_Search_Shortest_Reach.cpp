#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    // construct the graph
    constexpr int INF = -1;
    constexpr int WEIGHT = 6;
    vector<vector<int> > adj(n + 5);
    int u, v;
    for (size_t i = 0; i != edges.size(); ++i) {
        u = edges.at(i).at(0);
        v = edges.at(i).at(1);
        adj.at(u).emplace_back(v);
        adj.at(v).emplace_back(u);
    }
    // run bfs
    vector<int> dis(n + 5, INF);
    dis.at(s) = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (const auto &v_ : adj.at(u)) {
            if (dis.at(v_) == -1) {
                q.push(v_);
                dis.at(v_) = dis.at(u) + WEIGHT;
            }
        }
    }
    // obtain the result
    vector<int> result;
    for (int i = 1; i <= n; ++i) {
        if (i != s) {
            result.emplace_back(dis.at(i));
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
