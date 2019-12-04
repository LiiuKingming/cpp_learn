//
// Created by 28943 on 2019/11/24.
//
#include <iostream>
#include <string>

using namespace std;

int AddLonmgInteger(string &addend, string &augend){
    int num1 = 0;
    int num2 = 0;
    for(auto i = addend.begin(); i < addend.end(); i++){
        if (i == addend.begin()){
            num1 = addend[*i];
        } else {
            num1 += addend[*i] * 10;
        }
    }
    for(auto i = addend.begin(); i < addend.end(); i++){
        if (i == addend.begin()){
            num2 = *i;
        } else {
            num2 = *i * 10 + num2;
        }
    }
    return num1 + num2;
}

int main(){
    string add;
    string aug;
    while (cin >> add >> aug) {
        cout << AddLonmgInteger(add, aug) << endl;
    }
    return 0;
}
