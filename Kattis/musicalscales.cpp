// https://open.kattis.com/problems/musicalscales
//
#include <bits/extc++.h>

using namespace std;

unordered_map<string, int> noteToPosition;
unordered_map<string, unordered_set<string> > uniqNotesForEachScale;

inline static
string advance(const vector<string> &order, const string &original, int step) {
    string result;
    size_t i = noteToPosition[original];
    for (int k = 0; k < step; ++k) {
        ++i;
        try {
            result = order.at(i);
        } catch (out_of_range &) {
            i = 0;
            result = order.at(i);
        }
    }
    return result;
}

inline static
vector<string> getMajorScale(const vector<string> &order, const string &original) {
    //  tone, tone, semitone, tone, tone, tone, semitone
    vector<string> result = {original};
    result.emplace_back(advance(order, original, 2));
    result.emplace_back(advance(order, original, 4));
    result.emplace_back(advance(order, original, 5));
    result.emplace_back(advance(order, original, 7));
    result.emplace_back(advance(order, original, 9));
    result.emplace_back(advance(order, original, 11));
    result.emplace_back(advance(order, original, 12));
    return result;
}

inline static
bool includes(const unordered_set<string> &lhs, const unordered_set<string> &rhs) {
    for (const auto &i : lhs) {
        if (rhs.find(i) == rhs.end()) {
            return false;
        }
    }
    return true;
}

int main() {

    // pre
    vector<string> order = {"A", "A#", "B", "C", "C#", "D","D#", "E", "F", "F#", "G", "G#"};
    for (size_t i = 0; i != order.size(); ++i) {
        noteToPosition[order.at(i)] = static_cast<int>(i);
    }
    for (size_t i = 0; i != order.size(); ++i) {
        auto temp = getMajorScale(order, order.at(i));
        uniqNotesForEachScale[order.at(i)] = unordered_set<string>(temp.begin(), temp.end());
    }


    // input
    ios_base::sync_with_stdio(false);
    int n;
    string note;
    unordered_set<string> uniqNotes;
    cin >> n;
    while (n--) {
        cin >> note;
        uniqNotes.insert(note);
    }

    // process
    vector<string> result;
    for (const auto &i : uniqNotesForEachScale) {
        if (includes(uniqNotes, i.second)) {
            result.emplace_back(i.first);
        }
    }

    // sort
    sort(result.begin(), result.end());

    // output
    if (result.empty()) {
        cout << "none";
    } else {
        bool firstItem = true;
        for (const string &i : result) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << ' ';
            }
            cout << i;
        }
    }
    cout << endl;

    return 0;
}
