// https://open.kattis.com/problems/eligibility
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string name;
    int y0, m0, d0, y1, m1, d1, course;

    cin >> n;
    while (n--)
    {
        cin >> name;
        scanf("%d/%d/%d", &y0, &m0, &d0);
        scanf("%d/%d/%d", &y1, &m1, &d1);
        cin >> course;

        if (y0 >= 2010 || y1 >= 1991)
        {
            cout << name << " eligible" << endl;
        }
        else if (course >= 41)
        {
            cout << name << " ineligible" << endl;
        }
        else
        {
            cout << name << " coach petitions" << endl;
        }

    }
    return 0;
}
