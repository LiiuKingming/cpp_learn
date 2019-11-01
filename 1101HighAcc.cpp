//
// Created by 28943 on 2019/11/1.
//

#include "1101HighAcc.h"

int main(){
    string s1("12345");
    string s2("98765");
    HighAcc num1(s1);
    HighAcc num2(s2);

    cout << (string)(num1 + num2);
    return 0;
}

