//
// Created by 28943 on 2019/11/12.
//
//插入字符求是否为回文串

#include <iostream>
#include <string>

using namespace std;

bool palindromestr(string &str){
    size_t left = 0;
    size_t right = str.size() - 1;
    for( ; left <= right; left++, right--){
        if(str[left] != str[right]){
            return false;
        }
    }
    return true;
}
int obtainstr(string &str1, string &str2){
    string newstr;
    int count = 0;
    for(int i = 0; i < str1.size(); i++){
        newstr =  str1.insert(i, str2);
        if( palindromestr(newstr) ){
            count++;
        }
    }
    return count;
}

int main(){
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    int time = obtainstr(str1, str2);
    cout << time;
//    cout << str1;
//    cout << str2;

    return 0;
}
