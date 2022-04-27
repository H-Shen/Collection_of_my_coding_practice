#include "ThreadSafeArrayList.h"
#include <fstream>
#include <string>
#include <vector>
#include <map>

const static thread::id mainThreadId = this_thread::get_id();
static ifstream infile;
static ofstream outfile;
static int i;
static int threadsize = 5;

class Command {
private:
    string method;
    int params;

    Command(string str, int x) {
        method = str;
        params = x;
    }

public:
    static Command* parse(string rawData) {
        string m;
        int p;
        for (int i = 0; i < rawData.size() - 1; i++) {
            if (rawData[i] == '(') {
                m = rawData.substr(0, i);
                p = stoi(rawData.substr(i + 1));
                break;
            }
        }
        return new Command(m, p);
    }
    int getParams() {
        return params;
    }
};

void static appendFunction(ThreadSafeArrayList& instance, vector<Command*> commands) {
    for (auto command : commands) {
        instance.append(command->getParams());
    }
}

void static getFunction(ThreadSafeArrayList& instance, vector<Command*> commands) {
    for (auto command : commands) {
        instance.get(command->getParams());
    }
}

void static appendThread(ThreadSafeArrayList& instance, vector<Command*> commands, int threadnumber) {
    vector<Command*> task;
    for (int j = threadnumber; j < commands.size(); j += threadsize) {
        task.push_back(commands[j]);
    }
    appendFunction(instance, task);
}

void static getThread(ThreadSafeArrayList& instance, vector<Command*> commands) {
    getFunction(instance, commands);
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
    vector<Command*> appendCommands;
    vector<Command*> getCommands;
    while (infile.getline(c, 30)) {
        s = string(c);
        if (s == "ThreadSafeArrayList()") {
            continue;
        }
        s = s.substr(0, s.size() - 1);
        if (s[0] == 'a') {
            appendCommands.push_back(Command::parse(s));
        }
        else {
            getCommands.push_back(Command::parse(s));
        }
        s = "";
    }
    ThreadSafeArrayList safeList;
    vector<thread*> threads;

    for (int j = 0; j < threadsize; j++) {
        threads.push_back(new thread(appendThread, ref(safeList), appendCommands, j));
    }
    threads.push_back(new thread(getThread, ref(safeList), getCommands));
    for (int j = 0; j < threadsize + 1; j++) {
        threads[j]->join();
        delete threads[j];
    }
    //test code
    map<int, int> correctData;
    map<int, int> listData;
    for (int i = 0; i < appendCommands.size(); i++) {
        int data = appendCommands[i]->getParams();
        if (correctData.count(data) == 0) {
            correctData[data] = 1;
        }
        else {
            correctData[data]++;
        }
    }
    for (int i = 0; i < safeList.getSize(); i++) {
        int data = safeList.get(i);
        if (listData.count(data) == 0) {
            listData[data] = 1;
        }
        else {
            listData[data]++;
        }
    }
    if (correctData.size() != listData.size()) {
        outfile << "Your array ignored some datas:\n" << endl;
        outfile << "Your array's size is " << safeList.getSize() << ":\n";
        for (int i = 0; i < safeList.getSize(); i++) {
            int data = safeList.get(i);
            outfile << data << ", ";
        }
        outfile << "\nThe real array's size is " << appendCommands.size() << ":\n";
        for (int i = 0; i < appendCommands.size(); i++) {
            int data = appendCommands[i]->getParams();
            outfile << data << ", ";
        }
        return 0;
    }
    map<int, int>::iterator it;
    for (it = correctData.begin(); it != correctData.end(); it++) {
        int key = (*it).first;
        int value = (*it).second;
        if (listData.count(key) != 0 && listData[key] == value) {
            continue;
        }
        else {
            outfile << "The correct data is " << key << "; counts:" << value << endl;
            outfile << "Your counts is: " << listData[key] << endl;
            outfile << "Your array ignored some datas:\n" << endl;
            outfile << "Your array's size is " << safeList.getSize() << ":\n";
            for (int i = 0; i < safeList.getSize(); i++) {
                int data = safeList.get(i);
                outfile << data << ", ";
            }
            outfile << "\nThe real array's size is " << appendCommands.size() << ":\n";
            for (int i = 0; i < appendCommands.size(); i++) {
                int data = appendCommands[i]->getParams();
                outfile << data << ", ";
            }
            return 0;
        }
    }
    outfile << "accepted" << endl;
    for (int i = 0; i < appendCommands.size(); i++) {
        delete appendCommands[i];
    }
    for (int i = 0; i < getCommands.size(); i++) {
        delete getCommands[i];
    }
    infile.close();
    outfile.close();
    return 0;
}

//testcode

//int tempsize = 3;
//int* a = new int[tempsize];
//a[0] = 1;
//a[1] = 2;
//a[2] = 3;
//for (int i = 0; i < 3; i++) {
//    cout << a[i] << " ";
//}
//int* b = new int[tempsize * 2];
//for (int i = 0; i < 3; i++) {
//    b[i] = a[i];
//}
//delete[] a;
//cout << endl;
//a = b;
//a[3] = 4;
//a[4] = 5;
//a[5] = 6;
//for (int i = 0; i < 6; i++) {
//    cout << a[i] << " ";
//}
//delete[] a;
//
//ThreadSafeArrayList testlist;
//testlist.append(1);
//testlist.append(2);
//testlist.append(3);
//testlist.append(4);
//cout << endl;
//for (int i = 0; i < testlist.getSize(); i++) {
//    cout << testlist.get(i) << " ";
//}
//cout << endl << "!" << endl;