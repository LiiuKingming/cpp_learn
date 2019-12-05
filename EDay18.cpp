//
// Created by 28943 on 2019/11/27.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//1.兔子生兔子
#if 0
int getTotalCount(int monthCount){
    int firstMonth = 1;
    int secondMonth = 1;
    int rabbitNum = 0;
    for(int i = 3; i <= monthCount; i++){
        rabbitNum = firstMonth + secondMonth;
        firstMonth = secondMonth;
        secondMonth = rabbitNum;
    }
    return rabbitNum;
}
#else
// te?t*.*
// txt12.xls
bool strbool(const char* s, const char* str){
    if (*s == '\0' || *str == '\0'){
        return false;
    } else if (*s == '\0' && *str == '\0'){
        return true;
    }
    if (*s == '?'){
        return strbool(s + 1, str + 1);
    } else if (*s == '*'){
        return strbool(s + 1, str) || strbool(s + 1, str + 1) || strbool(s, str + 1);
    } else if (*s == *str){
        return strbool(s + 1, str + 1);
    }
    return false;
}
#endif
int main(){
    string s1;
    string s2;
    while (cin >> s1 >> s2){
        int ret = strbool(s1.c_str(), s2.c_str());//c_str 返回C格式字符串
        if(ret != 0){
            cout << "true" << endl;
        } else {
            cout <<"false" << endl;
        }
    }
//    int month = 0;
//    while(cin >> month){
//        cout << getTotalCount(month) << endl;
//    }
    return 0;
}
