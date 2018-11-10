//
// Created by LYM on 2018/11/9.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char day[7][10] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(void) {
    int i, j;
    char str[4][61];
    int ans[3];
    int flag = 1;

    fgets(str[0], 61, stdin);
    fgets(str[1], 61, stdin);
    fgets(str[2], 61, stdin);
    fgets(str[3], 61, stdin);

    for (i = 0, j = 0; i < strlen(str[0]) && j < strlen(str[1]); i++, j++) {
        if (str[0][i] == str[1][j]) {
            if (isdigit(str[0][i])) {
                ans[1] = str[0][i] - '0';
                if (!flag) {
                    break;
                }
            }
            ans[1] = str[0][i] - '0';
            if (isupper(str[0][i])) {
                ans[1] = str[0][i] - '0';
                if (flag) {
                    ans[0] = str[0][i] - 'A';
                    flag = 0;
                } else {
                    ans[1] = str[0][i] - 'A' + 10;
                    break;
                }
            }

        }
    }
    for (i = 0, j = 0; i < strlen(str[2]) && j < strlen(str[3]); i++, j++) {
        if (str[2][i] == str[3][j] && isalpha(str[2][i])) {
            ans[2] = i;
            break;
        }
    }

    printf("%s %02d:%02d", day[ans[0]], ans[1] % 24, ans[2]);

    return 0;
}