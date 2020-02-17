#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (N % 2 != 0) printf("Weird\n");
    else if (N % 2 == 0){
        if (N >= 2 && N <= 5) 
            printf("Not Weird\n");
        else if (N >= 6 && N <= 20) 
            printf("Weird\n");
        else if (N > 20)
            printf("Not Weird\n");
    }

    return 0;
}
