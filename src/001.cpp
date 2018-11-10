//
// Created by LYM on 2018/11/9.
//

#include <stdio.h>

typedef long long LL;

int main(void) {

    int T;
    LL a, b, c;
    int i;

    scanf("%d", &T);
    for (i=1; i<=T; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("Case #%d: %s\n", i, ((a+b>c) ? "true":"false"));
    }

    return 0;
}

