//
// Created by LYM on 2018/11/7.
//
#include <iostream>

using namespace std;

bool isLeapYear(int year);

int main(void)
{
    int num;
    while (cin >> num) {
        if (isLeapYear(num)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}

bool isLeapYear(int year) {
    if ((year%400==0) || (year%4==0 && year%100!=0)) {
        return true;
    }
    return false;
}