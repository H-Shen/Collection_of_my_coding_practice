class Solution {
public:
    string interpret(string command) {
        static const regex r0("\\(al\\)");
        static const regex r1("\\(\\)");
        return regex_replace(regex_replace(command, r0, "al"), r1, "o");
    }
};