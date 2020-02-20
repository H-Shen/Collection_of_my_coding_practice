#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
    int start_time;
    int duration;
    int end_time;
};
struct Available_Workshops {
    int n;
    Workshop* workshops;
};

Available_Workshops * initialize(int start_time[], int duration [], int n) {
    Available_Workshops * ptr = new Available_Workshops();
    ptr->n = n;
    ptr->workshops = new Workshop[n]();
    for (int i = 0; i < n; ++i) {
        ptr->workshops[i].duration = duration[i];
        ptr->workshops[i].start_time = start_time[i];
        ptr->workshops[i].end_time = ptr->workshops[i].start_time + ptr->workshops[i].duration;
    }
    return ptr;
}

// Use greedy to obtain the most intervals which don't intersect each other
int CalculateMaxWorkshops(Available_Workshops* ptr) {
    if (ptr == nullptr || ptr->n == 0) {
        return 0;
    }
    if (ptr->n == 1) {
        return 1;
    }
    sort(ptr->workshops, ptr->workshops + ptr->n, [](const Workshop &lhs, const Workshop &rhs){
        if (lhs.end_time == rhs.end_time) {
            return (lhs.start_time < rhs.start_time);
        }
        return (lhs.end_time < rhs.end_time);
    });
    int counter = 0;
    int current_end_time = -1;
    for (int i = 0; i < ptr->n; ++i) {
        if (ptr->workshops[i].start_time >= current_end_time) {
            ++counter;
            current_end_time = ptr->workshops[i].end_time;
        }
    }
    return counter;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
