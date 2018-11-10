//
// Created by LYM on 2018/11/7.
//

#include <iostream>

using namespace std;

int main(void) {

    char str[27][27];
    char ch;
    for (int i=0; i<26; i++) {
        ch = 'A';
        for (int j=i; j<26; j++) {
            str[i][j] = ch++;
        }
        ch = 'A';
        for (int j=i; j>=0; j--) {
            str[i][j] = ch++;
        }
    }

    int m, n;

    cin >> m >> n;

    for (int i=0; i<m; i++) {
        for (int j = 0; j < n; ++j) {
            cout << str[i][j];

        }
        cout << endl;
    }

    return 0;
}
