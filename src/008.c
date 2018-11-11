//
// Created by LYM on 2018/11/11.
//
/**
 * 输入描述:
输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代
表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。


输出描述:
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯
一，则输出按字母序最小的解。
 */

#include <stdio.h>

typedef struct Result {
    int win;
    int lose;
    int even;
}Result;

int getguesture(const int *arr);

int main(void) {

    int N;
    int i=0;
    char first, second;
    const char ch[] = {'B', 'C', 'J'};
    int aWinCount[3] = {0, 0, 0};
    int bWinCount[3] = {0, 0, 0};
    Result A={0, 0, 0}, B={0, 0, 0};

    scanf("%d", &N);
    for (i=0; i<N; i++) {
        getchar();
        scanf("%c %c", &first, &second);

        if (first == second) {
            A.even++;
            B.even++;
            continue;
        }
        int aWin = (first=='B' && second=='C') ||
                (first=='C' && second=='J') || (first=='J' && second=='B');
        if (aWin) {
            A.win++;
            B.lose++;
            if (first == 'B') {
                aWinCount[0]++;
            }else if (first == 'C') {
                aWinCount[1]++;
            }else if (first == 'J') {
                aWinCount[2]++;
            }
        } else {
            B.win++;
            A.lose++;
            if (second == 'B') {
                bWinCount[0]++;
            }else if (second == 'C') {
                bWinCount[1]++;
            }else if (second == 'J') {
                bWinCount[2]++;
            }
        }
    }

    printf("%d %d %d\n", A.win, A.even, A.lose);
    printf("%d %d %d\n", B.win, B.even, B.lose);
    printf("%c %c\n", ch[getguesture(aWinCount)], ch[getguesture(bWinCount)]);


    return 0;
}

int getguesture(const int *arr) {
    int i = 0;
    int max = arr[0];
    int target = 0;
    for (i = 0; i < 3; ++i) {
        if (max < arr[i]) {
            max = arr[i];
            target = i;
        }
    }
    return target;
}