class Solution {
public:
    bool isNumber(string s) {
        const static regex p0 (R"(^[ ]*(\+|\-){0,1}*\d+[ ]*$)");
        const static regex p1 (R"(^[ ]*(\+|\-){0,1}*\d*\.\d+[ ]*$)");
        const static regex p2 (R"(^[ ]*(\+|\-){0,1}*\d+\.\d*[ ]*$)");
        const static regex p3 (R"(^[ ]*(\+|\-){0,1}*\.\d+e(\+|\-){0,1}\d+[ ]*$)");
        const static regex p4 (R"(^[ ]*(\+|\-){0,1}*\d+\.\d*e(\+|\-){0,1}\d+[ ]*$)");
        const static regex p5 (R"(^[ ]*(\+|\-){0,1}*\d+e(\+|\-){0,1}\d+[ ]*$)");
        smatch r0, r1, r2, r3, r4, r5;
        return (regex_search(s, r0, p0) || regex_search(s, r1, p1) || regex_search(s, r2, p2) || regex_search(s, r3, p3) || regex_search(s, r4, p4) || regex_search(s, r5, p5));
    }
};