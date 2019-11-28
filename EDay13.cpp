//
// Created by 28943 on 2019/11/20.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void func(string &s){
    int flag = 0;
    int count = 0;
    vector<char> tmp;
    for (auto &i : s){
        if(i == '\0'){
            break;
            cout << "0µÄ++";
        }
        if (i == '"' ){
            if (flag == 0){
                flag++;
            } else if (flag == 1){
                flag--;
                count++;
            }
        }
        if (i == ' ' && flag == 0){
            tmp.push_back('\n');
            count++;
//            cout << "²»¿Õ++";
        }
        if (i == ' ' && flag == 1){
            tmp.push_back(' ');
        }

        if (i != ' '){
            tmp.push_back(i);
        }
    }
    count++;
    cout << count << endl;
    for (auto &j : tmp){
        cout << j;
    }
}

int main(){
    string s;
    while(getline(cin, s)){
        func(s);
    }
    return 0;
}
