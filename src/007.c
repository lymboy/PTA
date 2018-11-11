//
// Created by LYM on 2018/11/10.
//
/**
 * 链接：https://www.nowcoder.com/questionTerminal/25c3ae17bc99425b99542802ee882377?toCommentId=2349466
来源：牛客网

本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。
输入描述:
输入在1行中依次给出A和B，中间以1空格分隔。


输出描述:
在1行中依次输出Q和R，中间以1空格分隔。
示例1
输入
123456789050987654321 7
输出
17636684150141093474 3
 */
#include <stdio.h>
#include <string.h>

#define MAX 1000+5

int main(void) {
    char str[MAX];
    int divid;
    int i = 0;
    int tmp = 0;


    for (i = 0; i < MAX; i++) {
        str[i] = (char) getchar();
        if (str[i] == ' ') {
            str[i] = '\0';
            break;
        }
    }
    scanf("%d", &divid);

    for (i = 0; i<strlen(str); i++) {
        tmp = tmp*10 + (str[i]-'0');
        int ans = (int)(tmp/divid);

        // 输出第一位之后的0
        if (i > 0 && ans == 0) {
            printf("%d", ans);
            continue;
        }
        if (ans != 0) {
            printf("%d", ans);
            tmp %= divid;
        }
    }
    printf(" %d\n", tmp);

    return 0;
}
