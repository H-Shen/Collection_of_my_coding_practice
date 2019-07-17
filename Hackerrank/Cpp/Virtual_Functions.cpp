#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 105, MAXSIZE = 6;
static int Professor_cur_id = 1;
static int Student_cur_id = 1;

class Person {
private:
    char name[MAXN];
    int age;
public:
    virtual void getdata() {
        cin >> name >> age;
    }
    virtual void putdata() {
        cout << name << ' ' << age << endl;
    }
};

class Professor : public Person {
private:
    char name[MAXN];
    int age;
    int publications;
    int cur_id;
public:
    void getdata() {
        cin >> name >> age >> publications;
        cur_id = Professor_cur_id;
        Professor_cur_id++;
    }
    void putdata() {
        cout << name << ' ' << age << ' ' << publications << ' ' << cur_id << endl;
    }
};

class Student : public Person {
private:
    char name[MAXN];
    int age;
    int marks[MAXSIZE];
    int cur_id;
public:
    void getdata() {
        cin >> name >> age;
        for (int i = 0; i < MAXSIZE; i++) {
            cin >> marks[i];
        }

        cur_id = Student_cur_id;
        Student_cur_id++;
    }
    void putdata() {
        int sum = 0;
        for (int i = 0; i < MAXSIZE; i++) {
            sum += marks[i];
        }
        cout << name << ' ' << age << ' ' << sum << ' ' << cur_id << endl;
    }
};
int main(){