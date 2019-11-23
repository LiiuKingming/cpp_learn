//
// Created by 28943 on 2019/11/24.
//
#include <iostream>
using namespace std;

#if 0
int PerfectNum(int n) {
    int count = 0;
    for (int num = 3; num <= n; num++) {
        int sum = 0;
        for (int i = 1; i <= num / 2 + 1; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }
        if (sum == num)
            count++;
    }
    return count;
}
#else
//扑克
//单
//对子
//顺子
//三张
//炸弹
//王炸

string func(string &s){
    string s1;
    string s2;
    for (auto &i : s){
        int count = 0;
        if(i == '-'){
            count++;
        }
        if(i != '-' && count == 0){
            s1.push_back(i);
        } else if(i != '-' && count == 1){
            s2.push_back(i);
        }
    }
    for (auto &i : s1) {
        if ()
    }
}


#endif
int main(){
    string s;
    while (cin >> s){
        func(s);
    }
//    int num = 0;
//    while(cin >> num){
//        cout << PerfectNum(num) << endl;
//    }
    return 0;
}
