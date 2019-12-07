//
// Created by 28943 on 2019/11/25.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int publicChildStr(string &a, string &b){
//    static string child;
//    static string tmp;
//    for (size_t i = 0; i < a.size(); i++){
//        for(size_t j = 0; j < b.size(); j++){
//            if(a[i] == b[j] && a[i + 1] == b[j + 1]){
//                tmp.push_back(a[i]);
//                break;
//            }else if(a[i] == b[j] && a[i + 1] != b[j + 1]){
//                tmp.push_back(a[i]);
//                child = tmp;
//                tmp.clear();
//                continue;
//            }
//        }
//    }
//    return child.size();
//}

int main(){
    //asdfas
    //wer asdfas wer
    string s1;
    string s2;
    while (cin >> s1 >> s2){
        string tmp;
        string max;
//        vector<char> v;
        for (size_t i = 0; i < s1.size(); i++){
            for(size_t j = 0; j < s2.size(); j++){
                if (s1[i] == s2[j]){
                    tmp.push_back(s1[i]);
                    if (s1[i + 1] != s2[j + 1] && tmp.size() >= max.size()){
                        max = tmp;
                        tmp.clear();
                    }
                    continue;
                }
            }
        }
        cout << max.size() << endl;
    }
    return 0;
}
