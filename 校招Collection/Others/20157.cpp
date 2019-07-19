#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <cassert>
using namespace std;
int main()
{

    int a[10] = {1, 3, 2, 10,7, 18,20,31,47,59};
    sort(a,a+10);

    pair<int*,int*> p;

    p =
            equal_range
                    (a,a+10,18);

    assert(* (p.first) == 18);
    assert(* (p.second) == 20);
    return 0;
}