#include <fstream>
#include "ThreadSafeCounter.h"
#include <iostream>
#include <thread>
#include <string>
#include <vector>

using namespace std;
const static thread::id mainThreadId = this_thread::get_id();
static ifstream infile;
static ofstream outfile;
static int i;

int static increase(int number) {
    i = ++number;
    return i;
}

int static decrease(int number) {
    i = --number;
    return i;
}

void static threadincr(int counts, ThreadSafeCounter& counter) {
    for (int j = 0; j < counts; j++) {
        counter.incr(increase);
    }
}

void static threaddecr(int counts, ThreadSafeCounter& counter) {
    for (int j = 0; j < counts; j++) {
        counter.decr(decrease);
    }
}

int main(int argc, char* argv[])
{
    string in_path = argv[1];
    string out_path = argv[2];
    infile.open(in_path);
    outfile.open(out_path);
    string s;
    string list[2] = {};
    char c[30];
    int incrCount = 0;
    int decrCount = 0;
    while (infile.getline(c, 30)) {
        s = string(c);
        if (s == "incr()") {
            incrCount++;
        }
        else if (s == "decr()") {
            decrCount++;
        }
        s = "";
    }
    ThreadSafeCounter counter;
    vector<thread*> threads;
    threads.push_back(new thread(threadincr, incrCount, ref(counter)));
    threads.push_back(new thread(threaddecr, decrCount, ref(counter)));
    int n = 2;
    for (int j = 0; j < n; j++) {
        threads[j]->join();
        delete threads[j];
    }
    if (i != counter.getCount()) {
        outfile << "Don't cheat!" << endl;
    }
    else {
        outfile << i << endl;
    }
    infile.close();
    outfile.close();
    return 0;
}