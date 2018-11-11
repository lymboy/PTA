//
// Created by LYM on 2018/11/10.
//
#include <stdio.h>

int main(void) {
    int a, b, c, d;
    int sum1=0, sum2=0;

    scanf("%d %d %d %d", &a, &b, &c, &d);
    do {
        if (b == (a%10)) {
            sum1 = sum1*10 + a%10;
            //printf("a: %d\n", a%10);
        }
        if (d == (c%10)) {
            sum2 = sum2*10 + c%10;
            //printf("c: %d\n", c%10);
        }
        a /= 10;
        c /= 10;
    } while (a || c);

    printf("%d\n", sum1+sum2);

    return 0;
}
