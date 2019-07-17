#include <iostream>
#include <string>

using namespace std;

class Student {
    private:
        int Age;
        string First_name;
        string Last_name;
        int Standard;
    public:
        void set_age(int age) {
            Age = age;
        }
        void set_standard(int standard) {
            Standard = standard;
        }
        void set_first_name(string first_name) {
            First_name = first_name;
        }
        void set_last_name(string last_name) {
            Last_name = last_name;
        }
        int get_age(void) {
            return Age;
        }
        string get_first_name(void) {
            return First_name;
        }
        string get_last_name(void) {
            return Last_name;
        }
        int get_standard(void) {
            return Standard;
        }
        string to_string(void) {
            string res = ::to_string(Age) + ',' + First_name + ',' + Last_name + ',' + ::to_string(Standard);
            return res;
        }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}
