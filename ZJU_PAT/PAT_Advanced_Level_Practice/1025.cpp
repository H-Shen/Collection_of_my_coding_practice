#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

struct Testee {
    string registration;
    int totalScore;
    int finalRank;
    int locationNumber;
    int localRank;
    
    Testee(string reg, int score, int loc, int rank) : 
        registration(reg), totalScore(score), locationNumber(loc), localRank(rank) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    unordered_map<string, int> totalScores;
    unordered_map<string, pair<int, int>> locationInfo; // location, local rank
    
    // Read data from all locations
    for (int location = 1; location <= N; location++) {
        int K;
        cin >> K;
        
        vector<pair<string, int>> locationTestees(K);
        
        for (int i = 0; i < K; i++) {
            cin >> locationTestees[i].first >> locationTestees[i].second;
        }
        
        // Sort by score (descending) to calculate local ranks
        sort(locationTestees.begin(), locationTestees.end(), 
             [](const pair<string, int>& a, const pair<string, int>& b) {
                 return a.second > b.second;
             });
        
        // Assign local ranks efficiently
        for (int i = 0; i < K; i++) {
            int localRank = 1;
            if (i > 0 && locationTestees[i].second < locationTestees[i-1].second) {
                localRank = i + 1;
            } else if (i > 0) {
                // Same score as previous, find the rank of first occurrence
                for (int j = i - 1; j >= 0; j--) {
                    if (locationTestees[j].second == locationTestees[i].second) {
                        localRank = j + 1;
                    } else {
                        break;
                    }
                }
            }
            
            totalScores[locationTestees[i].first] += locationTestees[i].second;
            locationInfo[locationTestees[i].first] = {location, localRank};
        }
    }
    
    // Create final list
    vector<Testee> finalTestees;
    finalTestees.reserve(totalScores.size());
    
    for (const auto& entry : totalScores) {
        finalTestees.emplace_back(entry.first, 
                                entry.second, 
                                locationInfo[entry.first].first,
                                locationInfo[entry.first].second);
    }
    
    // Sort by total score (descending) to assign final ranks
    sort(finalTestees.begin(), finalTestees.end(), 
         [](const Testee& a, const Testee& b) {
             return a.totalScore > b.totalScore;
         });
    
    // Assign final ranks efficiently
    int currentRank = 1;
    for (int i = 0; i < finalTestees.size(); i++) {
        if (i > 0 && finalTestees[i].totalScore < finalTestees[i-1].totalScore) {
            currentRank = i + 1;
        }
        finalTestees[i].finalRank = currentRank;
    }
    
    // Sort for output: by final rank, then by registration number
    sort(finalTestees.begin(), finalTestees.end(), 
         [](const Testee& a, const Testee& b) {
             if (a.finalRank != b.finalRank) {
                 return a.finalRank < b.finalRank;
             }
             return a.registration < b.registration;
         });
    
    // Output
    cout << finalTestees.size() << '\n';
    for (const auto& testee : finalTestees) {
        cout << testee.registration << ' ' 
             << testee.finalRank << ' ' 
             << testee.locationNumber << ' ' 
             << testee.localRank << '\n';
    }
    
    return 0;
}
