//
// Created by 28943 on 2019/11/21.
//

#include <iostream>
#include <map>
using namespace std;

//int main(){
//    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//    int year, month, day;
//    while(cin >> year >> month >> day){
//        int sum = 0;
//        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
//            days[2]++;
//        }
//        for (int i = 0; i < month; i++){
//            sum += days[i];
//        }
//        sum += day;
//        cout << sum <<endl;
//    }
//}

static map<int, int> s_m;
void yearnum(int year){
    s_m.insert(pair<int, int>(0, 0));
    s_m.insert(pair<int, int>(1, 31));
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        s_m.insert(pair<int, int>(2, 29));
    } else {
        s_m.insert(pair<int, int>(2, 28));
    }
    s_m.insert(pair<int, int>(3, 31));
    s_m.insert(pair<int, int>(4, 30));
    s_m.insert(pair<int, int>(5, 31));
    s_m.insert(pair<int, int>(6, 30));
    s_m.insert(pair<int, int>(7, 31));
    s_m.insert(pair<int, int>(8, 31));
    s_m.insert(pair<int, int>(9, 30));
    s_m.insert(pair<int, int>(10, 31));
    s_m.insert(pair<int, int>(11, 30));
    s_m.insert(pair<int, int>(12, 31));
}

int daynum(int year, int month, int day){
    int num = 0;
    yearnum(year);
    if (month == 1){
        return day;
    }
    for(int i = 1; i < month; i++){
        num += s_m[i];
    }
    return num + day;
}

int main(){

    int year, month, day;
    while(cin >> year >> month >> day){
        cout << daynum(year, month, day) << endl;
    }
    return 0;
}