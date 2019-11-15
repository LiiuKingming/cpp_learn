//
// Created by 28943 on 2019/11/17.
//
//计算n * m 棋盘从左上角走到右下角(只可向右和向下不可回头)一共有多少种走法

#include <iostream>
using namespace std;

int move(int n, int m){
    if (n == 0 || m == 0){
        return 1;
    } else {
        return move(n - 1, m) + move(n, m - 1);
    }
}

int main(){
    int n;
    int m;
    while (cin >> n >> m){
        cout << move(n, m);
    }
    return 0;
}