
/*
 * 给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
 */


#include <stdio.h>

typedef struct D {
    long sum;
    long count;
    int flag;
} D;

int main(void) {

    int N;
    int num;
    int i = 0;
    D ans[5] = {{0, 0, 0},
                {0, 0, 1},
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}};

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &num);
        if (num % 10 == 0) {
            ans[0].sum += num;
        }
        if (num % 5 == 1) {
            ans[1].sum += (ans[1].flag ? num : (-num));
            ans[1].flag = !ans[1].flag;
        }
        if (num % 5 == 2) {
            ans[2].sum++;
        }
        if (num % 5 == 3) {
            ans[3].sum += num;
            ans[3].count++;
        }
        if (num % 5 == 4) {
            if (num > ans[4].sum) {
                ans[4].sum = num;
            }
        }
    }

    for (i = 0; i < 5; i++) {
        if (i > 0) {
            putchar(' ');
        }
        if (ans[i].sum == 0 && ans[i].count == 0) {
            putchar('N');
        } else {
            if (i == 3) {
                printf("%.1f", 1.0*ans[3].sum/ans[3].count);
            } else {
                printf("%ld", ans[i].sum);
            }
        }
    }

    return 0;
}