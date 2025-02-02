// https://open.kattis.com/problems/warringscoring
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string a(const vector<string>& A) {
    if (A.empty())
        return "tie";

    int longest0 = 0, longest1 = 0;
    int currentCount = 1;  // count for the current streak
    string prev = A[0];

    // Initialize first streak
    if (prev == "Yraglac")
        longest0 = 1;
    else if (prev == "Notnomde")
        longest1 = 1;

    // Traverse the vector from the second element onward.
    for (size_t i = 1; i < A.size(); i++) {
        if (A[i] == prev) {
            currentCount++;
        } else {
            // Update the longest streak for the previous character.
            if (prev == "Yraglac")
                longest0 = max(longest0, currentCount);
            else if (prev == "Notnomde")
                longest1 = max(longest1, currentCount);

            // Reset for the new streak.
            prev = A[i];
            currentCount = 1;
        }
    }
    // Update for the last streak.
    if (prev == "Yraglac")
        longest0 = max(longest0, currentCount);
    else if (prev == "Notnomde")
        longest1 = max(longest1, currentCount);

    if (longest0 > longest1)
        return "Yraglac";
    else if (longest1 > longest0)
        return "Notnomde";
    else
        return "tie";
}

string b(const vector<string>& A) {
    int count0 = 0, count1 = 0;
    int maxLead0 = 0, maxLead1 = 0;

    // Process the sequence one element at a time.
    for (const auto& s : A) {
        if (s == "Yraglac")
            count0++;
        else if (s == "Notnomde")
            count1++;

        int diff = count0 - count1;
        if (diff > 0) {
            maxLead0 = max(maxLead0, diff);
        } else if (diff < 0) {
            maxLead1 = max(maxLead1, -diff);
        }
    }

    if (maxLead0 > maxLead1)
        return "Yraglac";
    else if (maxLead1 > maxLead0)
        return "Notnomde";
    else
        return "tie";
}

int main() {
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    if (a(A) == b(A)) cout << "Agree" << '\n';
    else cout << "Disagree" << '\n';
    return 0;
}
