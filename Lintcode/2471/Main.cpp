#include "ThreadSafeLinkedList.h"
#include <fstream>
#include <string>
#include <vector>
#include <map>

#define THREADSIZE 5

const static thread::id mainThreadId = this_thread::get_id();
static ifstream infile;
static ofstream outfile;
static int i;

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

void static appendLeftFunction(ThreadSafeLinkedList& instance, vector<Command*> commands) {
    for (auto command : commands) {
        instance.appendLeft(command->getParams());
    }
}

void static appendRightFunction(ThreadSafeLinkedList& instance, vector<Command*> commands) {
    for (auto command : commands) {
        instance.appendRight(command->getParams());
    }
}

void static appendLeftThread(ThreadSafeLinkedList& instance, vector<Command*> commands, int threadnumber) {
    vector<Command*> task;
    for (int j = threadnumber; j < commands.size(); j += THREADSIZE) {
        task.push_back(commands[j]);
    }
    appendLeftFunction(instance, task);
}

void static appendRightThread(ThreadSafeLinkedList& instance, vector<Command*> commands, int threadnumber) {
    vector<Command*> task;
    for (int j = threadnumber; j < commands.size(); j += THREADSIZE) {
        task.push_back(commands[j]);
    }
    appendRightFunction(instance, task);
}

int main(int argc, char* argv[])
{
    string in_path = argv[1];
    string out_path = argv[2];
    infile.open(in_path);
    outfile.open(out_path);
    string s;
    char c[30];
    vector<Command*> appendLeftCommands;
    vector<Command*> appendRightCommands;
    int left = 0;
    int right = 0;
    while (infile.getline(c, 30)) {
        s = string(c);
        if (s == "ThreadSafeLinkedList()" || s == "") {
            continue;
        }
        s = s.substr(0, s.size() - 1);
        if (s[s.size() - 2] == 'h') {
            appendRightCommands.push_back(Command::parse(s));
        }
        else {
            appendLeftCommands.push_back(Command::parse(s));
        }
        s = "";
    }
    ThreadSafeLinkedList safeList;
    vector<thread*> leftThreads;
    vector<thread*> rightThreads;
    for (int j = 0; j < THREADSIZE; j++) {
        leftThreads.push_back(new thread(appendLeftThread, ref(safeList), appendLeftCommands, j));
    }
    for (int j = 0; j < THREADSIZE; j++) {
        rightThreads.push_back(new thread(appendRightThread, ref(safeList), appendRightCommands, j));
    }
    for (int j = 0; j < THREADSIZE; j++) {
        leftThreads[j]->join();
        delete leftThreads[j];
        rightThreads[j]->join();
        delete rightThreads[j];
    }
    //test code
    map<int, int> correctData;
    map<int, int> listData;
    for (int i = 0; i < appendLeftCommands.size(); i++) {
        int data = appendLeftCommands[i]->getParams();
        if (correctData.count(data) == 0) {
            correctData[data] = 1;
        }
        else {
            correctData[data]++;
        }
    }
    for (int i = 0; i < appendRightCommands.size(); i++) {
        int data = appendRightCommands[i]->getParams();
        if (correctData.count(data) == 0) {
            correctData[data] = 1;
        }
        else {
            correctData[data]++;
        }
    }
    ListNode* head = safeList.getLinkedList();
    while (head!=NULL) {
        int data = head->getData();
        if (listData.count(data) == 0) {
            listData[data] = 1;
        }
        else {
            listData[data]++;
        }
        head = head->getNext();
    }
    if (correctData.size() != listData.size()) {
        outfile << "Your array isn't correct!\n" << endl;
        outfile << "Your array's is:\n ";
        outfile << ListNode::toString(safeList.getLinkedList()) << endl;
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
            outfile << "Your array isn't correct!\n" << endl;
            outfile << "Your array's is:\n ";
            outfile << ListNode::toString(safeList.getLinkedList()) << endl;
            return 0;
        }
    }
    outfile << "accepted" << endl;
    for (int i = 0; i < appendLeftCommands.size(); i++) {
        delete appendLeftCommands[i];
    }
    for (int i = 0; i < appendRightCommands.size(); i++) {
        delete appendRightCommands[i];
    }
    infile.close();
    outfile.close();
    return 0;
}