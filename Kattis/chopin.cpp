// https://open.kattis.com/problems/chopin
//
#include <bits/extc++.h>

using namespace std;

unordered_map<string, string> alternative;

int main() {

    alternative["A#"] = "Bb";
    alternative["Bb"] = "A#";
    alternative["C#"] = "Db";
    alternative["Db"] = "C#";
    alternative["D#"] = "Eb";
    alternative["Eb"] = "D#";
    alternative["F#"] = "Gb";
    alternative["Gb"] = "F#";
    alternative["G#"] = "Ab";
    alternative["Ab"] = "G#";

    int n = 1;
    string note, tonality, alternativeNote, alternativeComb;
    while (cin >> note >> tonality) {
        alternativeNote = "";
        if (alternative.find(note) != alternative.end()) {
            alternativeNote = alternative[note];
        }
        alternativeComb = alternativeNote + " " + tonality;

        if (!alternativeNote.empty()) {
            cout << "Case " << n << ": " << alternativeComb << endl;
        } else {
            cout << "Case " << n << ": UNIQUE" << endl;
        }
        ++n;
    }

    return 0;
}
