//
// Created by 28943 on 2019/12/9.
//
//快到碗里来
#include <iostream>
using namespace std;
int main1(){
    double cat;
    double cup;
    while (cin >> cat >> cup){
        if(2 * cup * 3.14 >= cat){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

//跳台阶
class Solution {
public:
    int jumpFloorII(int number) {
        return 1 << number - 1;
    }
};


