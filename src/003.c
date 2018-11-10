//
// Created by LYM on 2018/11/9.
//
/**
 * 令Pi表示第i个素数。现任给两个正整数M <= N <= 10000，请输出PM到PN的所有素数。
 */
#include <stdio.h>
#include <string.h>
#define MAX 1000000+5

int prime[MAX] = {0};
int is_prime[MAX] = {0};
int main(void) {

    int i, j;
    int M, N;
    int count = 0;
    int pi = 0;

    for (i=0; i<MAX; i++) {
        is_prime[i] = 1;
    }

    for (i=2; i<MAX; i++) {
        if (is_prime[i]) {
            prime[pi++] = i;
        }
        for (j=0; j<pi && i*prime[j]<MAX; j++) {
            is_prime[i*prime[j]] = 0;
            if (i%prime[j] == 0) {
                break;
            }
        }
    }


    scanf("%d %d", &M, &N);

    int tmp = M-1;
    for (i=0, j=0;  i<=N-M; ++i, ++j) {
        if (j > 0) {
            putchar(' ');
        }
        if (j == 10) {
            j = 0;
            putchar('\n');
        }
        printf("%d", prime[tmp++]);
    }

    return 0;
}
