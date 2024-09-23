// https://www.nowcoder.com/practice/3cd4621963e8454594f00199f4536bb1

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_BUF 5000  //The max length of the input string.

int main() {

    string ori_str_cppStr;
    while (getline(cin, ori_str_cppStr)) {

        const char *p = ori_str_cppStr.c_str();
        char ori_str[MAX_BUF];
        strcpy(ori_str, p);

        int i = 0;
        int ori_strlen = 0;

        while ('\0' != ori_str[ori_strlen++]);

        const int trans_strlen = 2 * (ori_strlen - 1);
        char *str = (char *) malloc(trans_strlen + 1);

        if (!str)
            continue;

        //init string str[]
        str[0] = '$';
        str[1] = ori_str[0];
        for (i = 1; i < ori_strlen; i++) {
            str[2 * i] = '#';
            str[2 * i + 1] = ori_str[i];
        }
        str[trans_strlen] = '\0';


        int *P = (int *) malloc(trans_strlen * sizeof(int));
        if (!P)
            continue;
        P[0] = 0;

        int id = 0;
        int mx = 0;

        //update P[]
        int str_strlen = (int) strlen(str);
        for (i = 1; i < str_strlen; i++) {
            if (i < mx)
                P[i] = min(P[2 * id - i], mx - i);
            else
                P[i] = 0;

            while (str[i + P[i] + 1] == str[i - P[i] - 1])
                P[i]++;

            if (P[i] + i > mx) {
                id = i;
                mx = P[i] + id;
            }
        }

        //find the longest palindromic string
        int max_len = 0;
        int max_index = 0;

        for (i = 1; i < trans_strlen; i++) {
            if (P[i] > max_len) {
                max_len = P[i];
                max_index = i;
            }
        }

        char *longest_palindrome = (char *) malloc(max_len + 1);

        if (!longest_palindrome)
            continue;

        if ('#' == str[max_index - max_len])
            max_len--;

        if (0 == max_len) {
            printf("1\n");
            continue;
        }

        int longest_palindrome_pos = (max_index - max_len) / 2;

        for (i = 0; i < max_len + 1; i++)
            longest_palindrome[i] = ori_str[longest_palindrome_pos++];
        longest_palindrome[++max_len] = '\0';

        printf("%d\n", max_len);

        free(str);
        free(P);
        free(longest_palindrome);

    }
    return 0;
}
